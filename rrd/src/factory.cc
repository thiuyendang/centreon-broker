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

#include <memory>
#include "com/centreon/broker/exceptions/msg.hh"
#include "com/centreon/broker/rrd/connector.hh"
#include "com/centreon/broker/rrd/factory.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::rrd;

/**************************************
*                                     *
*            Local Objects            *
*                                     *
**************************************/

/**
 *  Search for a property value.
 *
 *  @param[in] cfg  Configuration object.
 *  @param[in] key  Key to get.
 *  @param[in] thrw Should throw if value is not found.
 *  @param[in] def  Default value.
 */
static QString const& find_param(config::endpoint const& cfg,
                                 QString const& key,
                                 bool thrw = true,
                                 QString const& def = QString()) {
  QMap<QString, QString>::const_iterator it(cfg.params.find(key));
  if (cfg.params.end() == it) {
    if (thrw)
      throw (exceptions::msg() << "RRD: no '" << key << "' defined " \
               " for endpoint '" << cfg.name << "'");
    else
      return (def);
  }
  return (it.value());
}

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
factory::factory() {}

/**
 *  Copy constructor.
 *
 *  @param[in] f Object to copy.
 */
factory::factory(factory const& f) : io::factory(f) {}

/**
 *  Destructor.
 */
factory::~factory() {}

/**
 *  Assignment operator.
 *
 *  @param[in] f Object to copy.
 *
 *  @return This object.
 */
factory& factory::operator=(factory const& f) {
  io::factory::operator=(f);
  return (*this);
}

/**
 *  Clone this object.
 *
 *  @return Exact copy of this factory.
 */
io::factory* factory::clone() const {
  return (new factory(*this));
}

/**
 *  Check if a configuration match the RRD layer.
 *
 *  @param[in] cfg       Endpoint configuration.
 *  @param[in] is_input  true if endpoint should act as input.
 *  @param[in] is_output true if endpoint should act as output.
 *
 *  @return true if the configuration matches the RRD layer.
 */
bool factory::has_endpoint(config::endpoint const& cfg, 
                           bool is_input,
                           bool is_output) const {
  (void)is_input;
  (void)is_output;
  return (cfg.type == "rrd");
}

/**
 *  Build a RRD endpoint from a configuration.
 *
 *  @param[in]  cfg         Endpoint configuration.
 *  @param[in]  is_input    true if endpoint should act as input.
 *  @param[in]  is_output   true if endpoint should act as output.
 *  @param[out] is_acceptor Will be set to false.
 *
 *  @return Endpoint matching the given configuration.
 */
io::endpoint* factory::new_endpoint(config::endpoint const& cfg,
                                    bool is_input,
                                    bool is_output,
                                    bool& is_acceptor) const {
  (void)is_acceptor;
  (void)is_output;

  // Check that endpoint is output only.
  if (is_input)
    throw (exceptions::msg()
             << "RRD: cannot create an input RRD endpoint");

  // Get metrics RRD path.
  QString metrics_path(find_param(cfg, "metrics_path"));

  // Get status RRD path.
  QString status_path(find_param(cfg, "status_path"));

  // Local socket path.
  QString path(find_param(cfg, "path", false));

  // Network connection.
  unsigned short port;
  port = find_param(cfg, "port", false, "0").toUShort();

  // Create endpoint.
  std::auto_ptr<rrd::connector> endp(new rrd::connector);
  endp->set_metrics_path(metrics_path);
  endp->set_status_path(status_path);
  if (!path.isEmpty())
    endp->set_cached_local(path);
  else if (port)
    endp->set_cached_net(port);
  is_acceptor = false;
  return (endp.release());
}