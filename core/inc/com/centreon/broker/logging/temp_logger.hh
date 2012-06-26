/*
** Copyright 2009-2011 Merethis
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

#ifndef CCB_LOGGING_TEMP_LOGGER_HH_
# define CCB_LOGGING_TEMP_LOGGER_HH_

# include <QString>
# include "com/centreon/broker/logging/defines.hh"
# include "com/centreon/broker/misc/stringifier.hh"
# include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace                logging {
  /**
   *  @class temp_logger temp_logger.hh "com/centreon/broker/logging/temp_logger.hh"
   *  @brief Log messages.
   *
   *  This class is used to temporarily buffer log messages before
   *  writing them to backends.
   */
  class                  temp_logger : private misc::stringifier {
   private:
    struct               redir {
      temp_logger& (temp_logger::*
                         redirect_bool)(bool) throw ();
      temp_logger& (temp_logger::*
                         redirect_double)(double) throw ();
      temp_logger& (temp_logger::*
                         redirect_int)(int) throw ();
      temp_logger& (temp_logger::*
                         redirect_long)(long) throw ();
      temp_logger& (temp_logger::*
                         redirect_long_long)(long long) throw ();
      temp_logger& (temp_logger::*
                         redirect_qstring)(QString const&) throw ();
      temp_logger& (temp_logger::*
                         redirect_unsigned_int)(unsigned int) throw ();
      temp_logger& (temp_logger::*
                         redirect_unsigned_long)(unsigned long) throw ();
      temp_logger& (temp_logger::*
                         redirect_unsigned_long_long)(unsigned long long) throw ();
      temp_logger& (temp_logger::*
                         redirect_string)(char const*) throw ();
      temp_logger& (temp_logger::*
                         redirect_pointer)(void const*) throw ();
    };
    level                _level;
    mutable redir const* _redir;
    static redir const   _redir_nothing;
    static redir const   _redir_stringifier;
    type                 _type;
    void                 _internal_copy(temp_logger const& t);
    template             <typename T>
    temp_logger&         _nothing(T t) throw ();
    template             <typename T>
    temp_logger&         _to_stringifier(T t) throw ();

   public:
                         temp_logger(type log_type,
                           level l,
                           bool enable = true);
                         temp_logger(temp_logger const& t);
                         ~temp_logger();
    temp_logger&         operator=(temp_logger const& t);
    temp_logger&         operator<<(bool b) throw ();
    temp_logger&         operator<<(double d) throw ();
    temp_logger&         operator<<(int i) throw ();
    temp_logger&         operator<<(long l) throw ();
    temp_logger&         operator<<(long long ll) throw ();
    temp_logger&         operator<<(QString const& q) throw ();
    temp_logger&         operator<<(unsigned int u) throw ();
    temp_logger&         operator<<(unsigned long ul) throw ();
    temp_logger&         operator<<(unsigned long long ull) throw ();
    temp_logger&         operator<<(char const* str) throw ();
    temp_logger&         operator<<(void const* ptr) throw ();
  };
}

CCB_END()

#endif /* !CCB_LOGGING_TEMP_LOGGER_HH_ */