/*
** Copyright 2015 Merethis
**
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

#include <cmath>
#include "com/centreon/broker/dumper/entries/ba.hh"
#include "com/centreon/broker/dumper/internal.hh"
#include "com/centreon/broker/io/events.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::dumper::entries;

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
ba::ba()
  : enable(true),
    poller_id(0),
    ba_id(0),
    level_critical(NAN),
    level_warning(NAN),
    organization_id(0),
    type_id(0) {}

/**
 *  Copy constructor.
 *
 *  @param[in] other  Object to copy.
 */
ba::ba(ba const& other) : io::data(other) {
  _internal_copy(other);
}

/**
 *  Destructor.
 */
ba::~ba() {}

/**
 *  Assignment operator.
 *
 *  @param[in] other  Object to copy.
 *
 *  @return This object.
 */
ba& ba::operator=(ba const& other) {
  if (this != &other) {
    io::data::operator=(other);
    _internal_copy(other);
  }
  return (*this);
}

/**
 *  Equality operator.
 *
 *  @param[in] other  Object to compare to.
 *
 *  @return True if both objects are equal.
 */
bool ba::operator==(ba const& other) const {
  return ((enable == other.enable)
          && (poller_id == other.poller_id)
          && (ba_id == other.ba_id)
          && (description == other.description)
          && (level_critical == other.level_critical)
          && (level_warning == other.level_warning)
          && (name == other.name)
          && (organization_id == other.organization_id)
          && (type_id == other.type_id));
}

/**
 *  Inequality operator.
 *
 *  @param[in] other  Object to compare to.
 *
 *  @return True if both objects are not equal.
 */
bool ba::operator!=(ba const& other) const {
  return (!operator==(other));
}

/**
 *  Get event type.
 *
 *  @return Event type.
 */
unsigned int ba::type() const {
  return (io::events::data_type<io::events::dumper, dumper::de_entries_ba>::value);
}

/**************************************
*                                     *
*           Private Methods           *
*                                     *
**************************************/

/**
 *  Copy internal data objects.
 *
 *  @param[in] other  Object to copy.
 */
void ba::_internal_copy(ba const& other) {
  enable = other.enable;
  poller_id = other.poller_id;
  ba_id = other.ba_id;
  description = other.description;
  level_critical = other.level_critical;
  level_warning = other.level_warning;
  name = other.name;
  organization_id = other.organization_id;
  type_id = other.type_id;
  return ;
}
