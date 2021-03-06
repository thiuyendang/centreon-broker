/*
** Copyright 2011-2013 Centreon
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

#include <fstream>
#include "com/centreon/broker/misc/string.hh"

using namespace com::centreon::broker::misc;

static char const* whitespaces(" \t\r\n");

/**
 *  Get the next valid line.
 *
 *  @param[in, out] stream The current stream to read new line.
 *  @param[out]     line   The line to fill.
 *  @param[in, out] pos    The current position.
 *
 *  @return True if data is available, false if no data.
 */
bool string::get_next_line(
       std::ifstream& stream,
       std::string& line,
       unsigned int& pos) {
  while (std::getline(stream, line, '\n')) {
    ++pos;
    string::trim(line);
    if (!line.empty()) {
      char c(line[0]);
      if (c != '#' && c != ';' && c != '\x0')
        return (true);
    }
  }
  return (false);
}

/**
 *  Get key and value from line.
 *
 *  @param[in,out] line  The line to process.
 *  @param[out]    key   The key pointer.
 *  @param[out]    value The value pointer.
 *  @param[in]     delim The delimiter.
 */
bool string::split(
               std::string& line,
               char const** key,
               char const** value,
               char delim) {
  std::size_t delim_pos(line.find_first_of(delim));
  if (delim_pos == std::string::npos)
    return (false);

  std::size_t first_pos;
  std::size_t last_pos;
  line.append("", 1);

  last_pos = line.find_last_not_of(whitespaces, delim_pos - 1);
  if (last_pos == std::string::npos)
    *key = NULL;
  else {
    first_pos = line.find_first_not_of(whitespaces);
    line[last_pos + 1] = '\0';
    *key = line.data() + first_pos;
  }

  first_pos = line.find_first_not_of(whitespaces, delim_pos + 1);
  if (first_pos == std::string::npos)
    *value = NULL;
  else {
    last_pos = line.find_last_not_of(whitespaces);
    line[last_pos + 1] = '\0';
    *value = line.data() + first_pos;
  }

  return (true);
}

/**
 *  Get key and value from line.
 *
 *  @param[in]  line  The line to extract data.
 *  @param[out] key   The key to fill.
 *  @param[out] value The value to fill.
 *  @param[in]  delim The delimiter.
 */
bool string::split(
       std::string const& line,
       std::string& key,
       std::string& value,
       char delim) {
  std::size_t delim_pos(line.find_first_of(delim));
  if (delim_pos == std::string::npos)
    return (false);

  std::size_t first_pos;
  std::size_t last_pos;

  last_pos = line.find_last_not_of(whitespaces, delim_pos - 1);
  if (last_pos == std::string::npos)
    key.clear();
  else {
    first_pos = line.find_first_not_of(whitespaces);
    key.assign(line, first_pos, last_pos + 1 - first_pos);
  }

  first_pos = line.find_first_not_of(whitespaces, delim_pos + 1);
  if (first_pos == std::string::npos)
    value.clear();
  else {
    last_pos = line.find_last_not_of(whitespaces);
    value.assign(line, first_pos, last_pos + 1 - first_pos);
  }

  return (true);
}

/**
 *  Split data into element.
 *
 *  @param[in]  data  The data to split.
 *  @param[out] out   The list to fill.
 *  @param[in]  delim The delimiter.
 */
void string::split(
               std::string const& data,
               std::list<std::string>& out,
               char delim) {
  if (data.empty())
    return ;

  std::size_t last(0);
  std::size_t current(0);
  while ((current = data.find(delim, current)) != std::string::npos) {
    std::string tmp(data.substr(last, current - last));
    out.push_back(trim(tmp));
    last = ++current;
  }
  std::string tmp(last ? data.substr(last) : data);
  out.push_back(trim(tmp));
  return ;
}

/**
 *  Split data into element.
 *
 *  @param[in]  data  The data to split.
 *  @param[out] out   The vector to fill.
 *  @param[in]  delim The delimiter.
 */
void string::split(
               std::string const& data,
               std::vector<std::string>& out,
               char delim) {
  if (data.empty())
    return ;

  std::size_t last(0);
  std::size_t current(0);
  while ((current = data.find(delim, current)) != std::string::npos) {
    std::string tmp(data.substr(last, current - last));
    out.push_back(trim(tmp));
    last = ++current;
  }
  std::string tmp(last ? data.substr(last) : data);
  out.push_back(trim(tmp));
  return ;
}

/**
 *  Trim a string.
 *
 *  @param[in] str The string.
 *
 *  @return The trimming stream.
 */
std::string& string::trim(std::string& str) throw () {
  size_t pos(str.find_last_not_of(whitespaces));
  if (pos == std::string::npos)
    str.clear();
  else {
    str.erase(pos + 1);
    if ((pos = str.find_first_not_of(whitespaces)) != std::string::npos)
      str.erase(0, pos);
  }
  return (str);
}

/**
 *  Trim at the left of the string.
 *
 *  @param[in] str The string.
 *
 *  @return The trimming stream.
 */
std::string& string::trim_left(std::string& str) throw () {
  size_t pos(str.find_first_not_of(whitespaces));
  if (pos != std::string::npos)
    str.erase(0, pos);
  return (str);
}

/**
 *  Trim at the right of the string.
 *
 *  @param[in] str The string.
 *
 *  @return The trimming stream.
 */
std::string& string::trim_right(std::string& str) throw () {
  size_t pos(str.find_last_not_of(whitespaces));
  if (pos == std::string::npos)
    str.clear();
  else
    str.erase(pos + 1);
  return (str);
}

/**
 *  Replace all the instance of string str from the string input.
 *
 *  @param[in,out] input The string to modify.
 *  @param[in] str The string to search for.
 *  @param[in] str2 The string to replace.
 */
void string::replace_all(std::string& input,
                         std::string const& str,
                         std::string const& str2) {
  size_t pos = 0;
  while ((pos = input.find(str, pos)) != std::string::npos) {
       input.replace(pos, str.length(), str2);
       pos += str.length();
  }
}
