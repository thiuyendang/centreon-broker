/*
** Copyright 2011 Merethis
** This file is part of Centreon Broker.
**
** Centreon Broker is free software: you can redistribute it and/or
** modify it under the terms of the GNU General Public License version 2
** as published by the Free Software Foundation.
**
** Centreon Broker is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Centreon Broker. If not, see
** <http://www.gnu.org/licenses/>.
*/

#include <QScopedPointer>
#include "exceptions/basic.hh"
#include "storage/connector.hh"
#include "storage/factory.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::storage;

/**************************************
*                                     *
*           Static Objects            *
*                                     *
**************************************/

/**
 *  Find a parameter in configuration.
 *
 *  @param[in] cfg Configuration object.
 *  @param[in] key Properties to get.
 *
 *  @return Properties value.
 */
static QString const& find_param(config::endpoint const& cfg,
                                 QString const& key) {
  QMap<QString, QString>::const_iterator it(cfg.params.find(key));
  if (it == cfg.params.end())
    throw (exceptions::basic() << "no '" << key.toStdString().c_str()
             << "' defined for storage endpoint '"
             << cfg.name.toStdString().c_str());
  return (it.value());
}

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
factory::factory() {}

/**
 *  Copy constructor.
 *
 *  @param[in] f Object to copy.
 */
factory::factory(factory const& f) : io::factory(f) {}

/**
 *  Destructor.
 */
factory::~factory() {}

/**
 *  Assignment operator.
 *
 *  @param[in] f Object to copy.
 *
 *  @return This object.
 */
factory& factory::operator=(factory const& f) {
  io::factory::operator=(f);
  return (*this);
}

/**
 *  Clone this object.
 *
 *  @return Exact copy of this factory.
 */
io::factory* factory::clone() const {
  return (new factory(*this));
}

/**
 *  Check if a configuration match the storage layer.
 *
 *  @param[in] cfg       Endpoint configuration.
 *  @param[in] is_input  true if endpoint should act as input.
 *  @param[in] is_output true if endpoint should act as output.
 *
 *  @return true if the configuration matches the storage layer.
 */
bool factory::has_endpoint(config::endpoint const& cfg, 
                           bool is_input,
                           bool is_output) const {
  (void)is_output;
  return (!is_input && (cfg.type == "storage"));
}

/**
 *  Build a storage endpoint from a configuration.
 *
 *  @param[in]  cfg         Endpoint configuration.
 *  @param[in]  is_input    true if endpoint should act as input.
 *  @param[in]  is_output   true if endpoint should act as output.
 *  @param[out] is_acceptor Will be set to false.
 *
 *  @return Endpoint matching the given configuration.
 */
io::endpoint* factory::new_endpoint(config::endpoint const& cfg,
                                    bool is_input,
                                    bool is_output,
                                    bool& is_acceptor) const {
  (void)is_output;

  // Check that endpoint should not be an input.
  if (is_input)
    throw (exceptions::basic() << "cannot create an input storage endpoint");

  // Find centreon DB parameters.
  QString centreon_type(find_param(cfg, "centreon_type"));
  QString centreon_host(find_param(cfg, "centreon_host"));
  QString centreon_port(find_param(cfg, "centreon_port"));
  QString centreon_user(find_param(cfg, "centreon_user"));
  QString centreon_password(find_param(cfg, "centreon_password"));
  QString centreon_db(find_param(cfg, "centreon_db"));

  // Find storage DB parameters.
  QString storage_type(find_param(cfg, "storage_type"));
  QString storage_host(find_param(cfg, "storage_host"));
  QString storage_port(find_param(cfg, "storage_port"));
  QString storage_user(find_param(cfg, "storage_user"));
  QString storage_password(find_param(cfg, "storage_password"));
  QString storage_db(find_param(cfg, "storage_db"));

  // Connector.
  QScopedPointer<storage::connector> c(new storage::connector);
  c->connect_to(centreon_type,
    centreon_host,
    centreon_port.toUShort(),
    centreon_user,
    centreon_password,
    centreon_db,
    storage_type,
    storage_host,
    storage_port.toUShort(),
    storage_user,
    storage_password,
    storage_db);
  is_acceptor = false;
  return (c.take());
}