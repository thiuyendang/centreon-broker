/*
** Copyright 2009-2011,2017 Centreon
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

#include "com/centreon/broker/logging/logging.hh"

using namespace com::centreon::broker;

/**************************************
*                                     *
*           Global Objects            *
*                                     *
**************************************/

logging::logger logging::config(logging::config_type);
logging::logger logging::debug(logging::debug_type);
logging::logger logging::error(logging::error_type);
logging::logger logging::info(logging::info_type);
logging::logger logging::perf(logging::perf_type);
