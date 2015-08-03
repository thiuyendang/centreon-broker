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

#ifndef CCB_CONFIG_APPLIER_STATE_HH
#  define CCB_CONFIG_APPLIER_STATE_HH

#  include "com/centreon/broker/config/state.hh"
#  include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace           config {
  namespace         applier {
    /**
     *  @class state state.hh "com/centreon/broker/config/applier/state.hh"
     *  @brief Apply a configuration.
     *
     *  Apply some configuration state.
     */
    class           state {
    public:
                    ~state();
      void          apply(
                      config::state const& s,
                      bool run_mux = true);
      static state& instance();
      static void   load();
      static void   unload();

      static unsigned int
                    instance_id;

    private:
                    state();
                    state(state const& s);
      state&        operator=(state const& s);
    };
  }
}

CCB_END()

#endif // !CCB_CONFIG_APPLIER_STATE_HH
