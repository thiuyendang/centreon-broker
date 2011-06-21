/*
** Copyright 2011 Merethis
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

#include <assert.h>
#include <QScopedPointer>
#include <stdlib.h>
#include "com/centreon/broker/exceptions/msg.hh"
#include "com/centreon/broker/logging/logging.hh"
#include "com/centreon/broker/tcp/acceptor.hh"
#include "com/centreon/broker/tcp/stream.hh"
#include "com/centreon/broker/tcp/tls_server.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::tcp;

/**************************************
*                                     *
*           Private Methods           *
*                                     *
**************************************/

/**
 *  @brief Copy constructor.
 *
 *  Any call to this constructor will result in a call to abort().
 *
 *  @param[in] a Object to copy.
 */
acceptor::acceptor(acceptor const& a) : io::endpoint(a) {
  assert(false);
  abort();
}

/**
 *  @brief Assignment operator.
 *
 *  Any call to this method will result in a call to abort().
 *
 *  @param[in] a Object to copy.
 *
 *  @return This object.
 */
acceptor& acceptor::operator=(acceptor const& a) {
  (void)a;
  assert(false);
  abort();
  return (*this);
}

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
acceptor::acceptor() : _port(0), _tls(false) {}

/**
 *  Destructor.
 */
acceptor::~acceptor() {}

/**
 *  Close the acceptor.
 */
void acceptor::close() {
  if (!_socket.isNull()) {
    _socket->close();
    _socket.reset();
  }
  return ;
}

/**
 *  Set the port on which the acceptor will listen.
 *
 *  @param[in] port Port on which the acceptor will listen.
 */
void acceptor::listen_on(unsigned short port) {
  _port = port;
  return ;
}

/**
 *  Start connection acception.
 */
QSharedPointer<io::stream> acceptor::open() {
  // Listen on port.
  if (_socket.isNull()) {
    _socket.reset(_tls ? new tls_server(_private, _public, _ca)
                       : new QTcpServer);
    if (!_socket->listen(QHostAddress::Any, _port))
      throw (exceptions::msg() << "could not listen on port " << _port
               << ": " << _socket->errorString().toStdString().c_str());
  }

  // Wait for incoming connections.
  logging::debug << logging::MEDIUM << "TCP: waiting for new connection";
  if (!_socket->waitForNewConnection(-1))
    throw (exceptions::msg() << "could not accept incoming TCP client: "
             << _socket->errorString().toStdString().c_str());

  // Accept client.
  QSharedPointer<QTcpSocket> incoming(_socket->nextPendingConnection());
  if (incoming.isNull())
    throw (exceptions::msg() << "could not accept incoming TCP client: "
             << _socket->errorString().toStdString().c_str());
  logging::info << logging::MEDIUM << "TCP: new client successfully connected";

  // Return object.
  return (QSharedPointer<io::stream>(new stream(incoming)));
}

/**
 *  Set TLS parameters.
 *
 *  @param[in] enable true to enable TLS encryption.
 *  @param[in] private_key Private key to use for encryption.
 *  @param[in] public_cert Public certificate to use for encryption.
 *  @param[in] ca_cert     Trusted CA's certificate, used to
 *                         authenticate peers.
 */
void acceptor::set_tls(bool enable,
                       QString const& private_key,
                       QString const& public_cert,
                       QString const& ca_cert) {
  _ca = ca_cert;
  _private = private_key;
  _public = public_cert;
  _tls = enable;
  return ;
}
