/*
** Copyright 2009-2013,2015 Centreon
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

#ifndef CCB_NEB_LOG_ENTRY_HH
#  define CCB_NEB_LOG_ENTRY_HH

#  include <QString>
#  include "com/centreon/broker/io/data.hh"
#  include "com/centreon/broker/io/event_info.hh"
#  include "com/centreon/broker/mapping/entry.hh"
#  include "com/centreon/broker/namespace.hh"
#  include "com/centreon/broker/timestamp.hh"

CCB_BEGIN()

namespace          neb {
  /**
   *  @class log_entry log_entry.hh "com/centreon/broker/neb/log_entry.hh"
   *  @brief Log message.
   *
   *  From time to time, the scheduling engine generates a log
   *  message. These messages can be useful, especially when
   *  investigating problems. This class holds all information
   *  related to a log entry.
   */
  class            log_entry : public io::data {
  public:
                   log_entry();
                   log_entry(log_entry const& other);
                   ~log_entry();
    log_entry&     operator=(const log_entry& other);
    unsigned int   type() const;
    static unsigned int
                   static_type();

    timestamp      c_time;
    unsigned int   host_id;
    QString        host_name;
    timestamp      issue_start_time;
    short          log_type;
    short          msg_type;
    QString        notification_cmd;
    QString        notification_contact;
    QString        output;
    QString        poller_name;
    int            retry;
    QString        service_description;
    unsigned int   service_id;
    short          status;

    static mapping::entry const
                   entries[];
    static io::event_info::event_operations const
                   operations;

  private:
    void           _internal_copy(log_entry const& other);
  };
}

CCB_END()

#endif // !CCB_NEB_LOG_ENTRY_HH
