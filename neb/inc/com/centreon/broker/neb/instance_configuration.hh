/*
** Copyright 2009-2012 Centreon
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

#ifndef CCB_NEB_INSTANCE_CONFIGURATION_HH
#  define CCB_NEB_INSTANCE_CONFIGURATION_HH

#  include <QString>
#  include "com/centreon/broker/io/data.hh"
#  include "com/centreon/broker/namespace.hh"
#  include "com/centreon/broker/timestamp.hh"

CCB_BEGIN()

namespace          neb {
  /**
   *  @class instance_configuration instance_configuration.hh "com/centreon/broker/neb/instance_configuration.hh"
   *  @brief Information about the instance configuration.
   *
   *  An event of this class is sent when centreon engine has finished
   *  reloading its configuration, either successfully or not.
   */
  class            instance_configuration : public io::data {
  public:
                   instance_configuration();
                   instance_configuration(instance_configuration const& i);
                   ~instance_configuration();
    instance_configuration&
                   operator=(instance_configuration const& i);
    unsigned int   type() const;

    bool           loaded;

  private:
    void           _internal_copy(instance_configuration const& i);
  };
}

CCB_END()

#endif // !CCB_NEB_INSTANCE_CONFIGURATION_HH