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

#ifndef CCB_COMPRESSION_STREAM_HH
#  define CCB_COMPRESSION_STREAM_HH

#  include "com/centreon/broker/io/stream.hh"
#  include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace                      compression {
  /**
   *  @class stream stream.hh "com/centreon/broker/compression/stream.hh"
   *  @brief Compression stream.
   *
   *  Compress and uncompress data.
   */
  class                        stream : public io::stream {
  public:
                               stream(
                                 int level = -1,
                                 unsigned int size = 0);
                               stream(stream const& s);
                               ~stream();
    stream&                    operator=(stream const& s);
    void                       process(bool in = false, bool out = false);
    misc::shared_ptr<io::data> read();
    void                       write(misc::shared_ptr<io::data> d);

  private:
    void                       _flush();
    bool                       _get_data(unsigned int size);
    void                       _internal_copy(stream const& s);

    int                        _level;
    bool                       _process_in;
    bool                       _process_out;
    QByteArray                 _rbuffer;
    unsigned int               _size;
    QByteArray                 _wbuffer;
  };
}

CCB_END()

#endif // !CCB_COMPRESSION_STREAM_HH