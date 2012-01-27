/*
** Copyright 2009-2011 MERETHIS
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
**
** For more information: contact@centreon.com
*/

#include "events/service_dependency.hh"

using namespace events;

/**************************************
*                                     *
*           Private Methods           *
*                                     *
**************************************/

/**
 *  Copy internal members from the given object.
 *
 *  @param[in] sd Object to copy.
 */
void service_dependency::_internal_copy(service_dependency const& sd) {
  dependent_service_id = sd.dependent_service_id;
  service_id = sd.service_id;
  return ;
}

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
service_dependency::service_dependency()
  : dependent_service_id(0), service_id(0) {}

/**
 *  Copy constructor.
 *
 *  @param[in] sd Object to copy.
 */
service_dependency::service_dependency(service_dependency const& sd)
  : dependency(sd) {
  _internal_copy(sd);
}

/**
 *  Destructor.
 */
service_dependency::~service_dependency() {}

/**
 *  Assignment operator.
 *
 *  @param[in] sd Object to copy.
 *
 *  @return This object.
 */
service_dependency& service_dependency::operator=(
  service_dependency const& sd) {
  dependency::operator=(sd);
  _internal_copy(sd);
  return (*this);
}

/**
 *  Get the type of this object (event::SERVICEDEPENDENCY).
 *
 *  @return event::SERVICEDEPENDENCY
 */
int service_dependency::get_type() const {
  return (SERVICEDEPENDENCY);
}