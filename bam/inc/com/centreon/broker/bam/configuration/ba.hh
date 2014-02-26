/*
** Copyright 2014 Merethis
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

#ifndef CCB_BAM_CONFIGURATION_BA_HH
#  define CCB_BAM_CONFIGURATION_BA_HH

#  include <string>
#  include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace              bam {
  namespace            configuration {
    /**
     *  @class ba ba.hh "com/centreon/broker/bam/configuration/ba.hh"
     *  @brief BA configuration state.
     *
     *  The ba class is used to stored configuration directly read from
     *  the DB.
     */
    class              ba {
    public:
                       ba();
                       ba(
                         unsigned int id,
                         std::string const& name,
                         double level,
                         double warning_level,
                         double critical_level);
                       ba(ba const& right);
                       ~ba();
    ba&                operator=(ba const& right);

    unsigned int       get_id() const;
    std::string const& get_name() const;
    double             get_level() const;
    double             get_warning_level() const;
    double             get_critical_level() const;

    void               set_id( unsigned int id);
    void               set_name(std::string const& name);
    void               set_level(double level);
    void               set_warning_level(double warning_level);  
    void               set_critical_level(double critical_level);
    
  private:
    unsigned int       _id;
    std::string        _name;
    double             _level;
    double             _warning_level;
    double             _critical_level;    
  };
}

CCB_END()

#endif // !CCB_BAM_CONFIGURATION_BA_HH
