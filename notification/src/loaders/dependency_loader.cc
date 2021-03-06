/*
** Copyright 2014 Centreon
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** For more information : contact@centreon.com
*/

#include <utility>
#include <vector>
#include <sstream>
#include <QVariant>
#include <QSqlError>
#include "com/centreon/broker/exceptions/msg.hh"
#include "com/centreon/broker/logging/logging.hh"
#include "com/centreon/broker/notification/objects/dependency.hh"
#include "com/centreon/broker/notification/loaders/dependency_loader.hh"

using namespace com::centreon::broker::notification;
using namespace com::centreon::broker::notification::objects;

dependency_loader::dependency_loader() {}

/**
 *  Load the dependencies from the database.
 *
 *  @param[in] db       An open connection to the database.
 * @param[out] output   A dependency builder object to register the dependencies.
 */
void dependency_loader::load(QSqlDatabase* db, dependency_builder* output) {
  // If we don't have any db or output, don't do anything.
  if (!db || !output)
    return;

  logging::debug(logging::medium)
    << "notification: loading dependencies from the database";

  // We do not know the type of a dependency until far latter.
  // Cache the options until we know enough to correctly parse them.
  std::vector<std::pair<int, std::string> > dep_execution_failure_options;
  std::vector<std::pair<int, std::string > > dep_notification_failure_options;
  QSqlQuery query(*db);

  // Performance improvement, as we never go back.
  query.setForwardOnly(true);

  // Load the dependencies.
  if (!query.exec(
               "SELECT dep_id, inherits_parent,"
               "       execution_failure_criteria,"
               "       notification_failure_criteria"
               "  FROM cfg_dependencies"))
    throw (exceptions::msg()
           << "notification: cannot load dependencies from database: "
           << query.lastError().text());

  while (query.next()) {
    dependency::ptr dep(new dependency);
    unsigned int id = query.value(0).toUInt();
    dep->set_inherits_parent(query.value(1).toBool());
    dep_execution_failure_options.push_back(
      std::make_pair(id, query.value(2).toString().toStdString()));
    dep_notification_failure_options.push_back(
      std::make_pair(id, query.value(3).toString().toStdString()));

    output->add_dependency(id, dep);
  }

  // Get the relations of the dependencies. It will also give us their type.
  _load_relations(query, *output);

  // We now know the types of the dependencies: we can parse the failure options.
  for (std::vector<std::pair<int, std::string> >::const_iterator
       it(dep_execution_failure_options.begin()),
       end(dep_execution_failure_options.end());
       it != end; ++it)
    output->set_execution_failure_options(it->first, it->second);
  for (std::vector<std::pair<int, std::string> >::const_iterator
       it(dep_notification_failure_options.begin()),
       end(dep_notification_failure_options.end());
       it != end; ++it)
    output->set_notification_failure_options(it->first, it->second);
}

/**
 *  Load the relations from the database.
 *
 *  @param[in] query    A query object linked to the db.
 *  @param[out] output  An output dependency builder to load the relations.
 */
void dependency_loader::_load_relations(
                          QSqlQuery& query,
                          dependency_builder& output) {

  if (!query.exec("SELECT dependency_dep_id, host_host_id"
                  "  FROM cfg_dependencies_hostchildren_relations"))
    throw (exceptions::msg()
           << "notification: cannot load host/child dependencies from database: "
           << query.lastError().text());
  while (query.next())
    output.dependency_node_id_child_relation(
             query.value(0).toUInt(),
             node_id(query.value(1).toUInt()));

  if (!query.exec("SELECT dependency_dep_id, host_host_id"
                  "  FROM cfg_dependencies_hostparents_relations"))
    throw (exceptions::msg()
           << "notification: cannot load host/parent dependencies from database: "
           << query.lastError().text());
  while (query.next())
    output.dependency_node_id_parent_relation(
             query.value(0).toUInt(),
             node_id(query.value(1).toUInt()));

  if (!query.exec("SELECT dependency_dep_id, service_service_id, host_host_id"
                  "  FROM cfg_dependencies_servicechildren_relations"))
    throw (exceptions::msg()
           << "notification: cannot load service/child dependencies from database: "
           << query.lastError().text());
  while (query.next())
    output.dependency_node_id_child_relation(
             query.value(0).toUInt(),
             node_id(query.value(2).toUInt(),
             query.value(1).toUInt()));

  if (!query.exec("SELECT dependency_dep_id, service_service_id, host_host_id"
                  "  FROM cfg_dependencies_serviceparents_relations"))
    throw (exceptions::msg()
           << "notification: cannot load service/parent dependencies from database: "
           << query.lastError().text());
  while (query.next())
    output.dependency_node_id_parent_relation(
             query.value(0).toUInt(),
             node_id(query.value(2).toUInt(),
             query.value(1).toUInt()));
}

/**
 *  Load a relation between two ids, one of which is dependency_dep_id, from a table in the database.
 *
 *  @param[in,out] query                A query object linked to the db.
 *  @param[out] output                  The output dependency builder.
 *  @param[in] relation_id_name         The name of the second relation identifier.
 *  @param[in] table                    The table to load the relations from.
 *  @param[in] register_method          The dependency builder method to call to register the escalation.
 */
void dependency_loader::_load_relation(
       QSqlQuery& query,
       dependency_builder& output,
       std::string const& relation_id_name,
       std::string const& table,
       void (dependency_builder::*register_method)(unsigned int, unsigned int)) {
  std::stringstream ss;
  ss << "SELECT dependency_dep_id, " << relation_id_name << " FROM " << table;
  if (!query.exec(ss.str().c_str()))
    throw (exceptions::msg()
      << "notification: cannot select " <<  table << " in loader: "
      << query.lastError().text());

  while (query.next()) {
    unsigned int id = query.value(0).toUInt();
    unsigned int associated_id = query.value(1).toUInt();

    (output.*register_method)(id, associated_id);
  }
}
