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

#include "logging/ostream.hh"

using namespace logging;

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
ostream::ostream() : _os(NULL) {}

/**
 *  Copy constructor.
 *
 *  @param[in] s Object to copy.
 */
ostream::ostream(ostream const& o) : backend(o) {
  _os = static_cast<std::ostream*>(o._os);
}

/**
 *  Constructor.
 *
 *  @param[in] Already opened stream.
 */
ostream::ostream(std::ostream& os) : _os(&os) {}

/**
 *  Destructor.
 */
ostream::~ostream() {}

/**
 *  Assignment operator.
 *
 *  @param[in] s Object to copy.
 *
 *  @return This object.
 */
ostream& ostream::operator=(ostream const& o) {
  backend::operator=(o);
  _os = const_cast<std::ostream*>(o._os);
  return (*this);
}

/**
 *  Assignment operator.
 *
 *  @param[in] os Stream to write on.
 *
 *  @return This object.
 */
ostream& ostream::operator=(std::ostream& os) {
  _os = &os;
  return (*this);
}

/**
 *  Write log message to stream.
 *
 *  @param[in] msg      Log message.
 *  @param[in] len      Message length.
 *  @param[in] log_type Type of the log message.
 *  @param[in] l        Log level.
 */
void ostream::log_msg(char const* msg,
                      unsigned int len,
                      type log_type,
                      level l) throw () {
  (void)len;
  (void)l;
  if (_os && msg) {
    char const* prefix;
    switch (log_type) {
     case CONFIG:
      prefix = "CONFIG: ";
      break ;
     case DEBUG:
      prefix = "DEBUG: ";
      break ;
     case ERROR:
      prefix = "ERROR: ";
      break ;
     case INFO:
      prefix = "INFO: ";
      break ;
     default:
      prefix = "UNDEFINED: ";
    }
    *_os << prefix << msg;
    _os->flush();
  }
  return ;
}