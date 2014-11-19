/*
** Copyright 2011-2014 Merethis
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

#ifndef CCB_NOTIFICATION_BUILDERS_TIMEPERIOD_BY_ID_BUILDER_HH
#  define CCB_NOTIFICATION_BUILDERS_TIMEPERIOD_BY_ID_BUILDER_HH

#  include "com/centreon/broker/namespace.hh"
#  include "com/centreon/broker/notification/objects/node_id.hh"
#  include "com/centreon/broker/notification/objects/timeperiod.hh"
#  include "com/centreon/broker/notification/builders/composed_builder.hh"
#  include "com/centreon/broker/notification/builders/timeperiod_builder.hh"

CCB_BEGIN()

namespace       notification {
  /**
   *  @class timeperiod_by_id_builder timeperiod_by_id_builder.hh "com/centreon/broker/notification/builders/timeperiod_by_id_builder.hh"
   *  @brief Timeperiod by id builder.
   */
  class         timeperiod_by_id_builder
                  : public composed_builder<timeperiod_builder> {
  public:
    timeperiod_by_id_builder(
      QHash<unsigned int, objects::timeperiod::ptr>& table);

    void        add_timeperiod(
                  unsigned int id,
                  objects::timeperiod::ptr con);

  private:
    QHash<unsigned int, objects::timeperiod::ptr>&
                  _table;
  };

}

CCB_END()

#endif // !CCB_NOTIFICATION_BUILDERS_TIMEPERIOD_BY_ID_BUILDER_HH
