/*
** Copyright 2011-2012 Merethis
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

#ifndef CCB_SQL_CONNECTOR_HH
#  define CCB_SQL_CONNECTOR_HH

#  include <QString>
#  include "com/centreon/broker/io/endpoint.hh"
#  include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace                        sql {
  /**
   *  @class connector connector.hh "com/centreon/broker/sql/connector.hh"
   *  @brief Connect to a database.
   *
   *  Send events to a SQL database.
   */
  class                          connector : public io::endpoint {
  public:
                                 connector();
                                 connector(connector const& c);
                                 ~connector();
    connector&                   operator=(connector const& c);
    void                         close();
    void                         connect_to(
                                   QString const& type,
                                   QString const& host,
                                   unsigned short port,
                                   QString const& user,
                                   QString const& password,
                                   QString const& db,
                                   bool with_state_events = false);
    misc::shared_ptr<io::stream> open();

  private:
    QString                      _db;
    QString                      _host;
    QString                      _password;
    unsigned short               _port;
    QString                      _type;
    QString                      _user;
    bool                         _with_state_events;
  };
}

CCB_END()

#endif // !CCB_SQL_CONNECTOR_HH