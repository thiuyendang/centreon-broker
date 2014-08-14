/*
** Copyright 2011-2013 Merethis
**
** This file is part of Centreon Engine.
**
** Centreon Engine is free software: you can redistribute it and/or
** modify it under the terms of the GNU General Public License version 2
** as published by the Free Software Foundation.
**
** Centreon Engine is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Centreon Engine. If not, see
** <http://www.gnu.org/licenses/>.
*/

#include "com/centreon/broker/notification/objects/daterange.hh"

using namespace com::centreon::broker::notification;

/**
 *  Constructor.
 *
 *  @param[in] type The date range type.
 */
daterange::daterange(type_range type)
 :_month_end(0),
  _month_start(0),
  _month_day_end(0),
  _month_day_start(0),
  _skip_interval(0),
  _type(type),
  _week_day_end(0),
  _week_day_start(0),
  _week_day_end_offset(0),
  _week_day_start_offset(0),
  _year_end(0),
  _year_start(0) {

}

/**
 *  Copy constructor.
 *
 *  @param[in] right The object to copy.
 */
daterange::daterange(daterange const& right) {
  operator=(right);
}

/**
 *  Destructor.
 */
daterange::~daterange() {

}

/**
 *  Copy operator.
 *
 *  @param[in] right The object to copy.
 *
 *  @return This object.
 */
daterange& daterange::operator=(daterange const& right) {
  if (this != &right) {
    _month_end = right._month_end;
    _month_start = right._month_start;
    _month_day_end = right._month_day_end;
    _month_day_start = right._month_day_start;
    _skip_interval = right._skip_interval;
    _timeranges = right._timeranges;
    _type = right._type;
    _week_day_end = right._week_day_end;
    _week_day_start = right._week_day_start;
    _week_day_end_offset = right._week_day_end_offset;
    _week_day_start_offset = right._week_day_start_offset;
    _year_end = right._year_end;
    _year_start = right._year_start;
  }
  return (*this);
}

/**
 *  Equal operator.
 *
 *  @param[in] right The object to compare.
 *
 *  @return True if object is the same, otherwise false.
 */
bool daterange::operator==(daterange const& right) const throw () {
  return (_month_end == right._month_end
          && _month_start == right._month_start
          && _month_day_end == right._month_day_end
          && _month_day_start == right._month_day_start
          && _skip_interval == right._skip_interval
          && _timeranges == right._timeranges
          && _type == right._type
          && _week_day_end == right._week_day_end
          && _week_day_start == right._week_day_start
          && _week_day_end_offset == right._week_day_end_offset
          && _week_day_start_offset == right._week_day_start_offset
          && _year_end == right._year_end
          && _year_start == right._year_start);
}

/**
 *  Not equal operator.
 *
 *  @param[in] right The object to compare.
 *
 *  @return True if object is not the same, otherwise false.
 */
bool daterange::operator!=(daterange const& right) const throw () {
  return (!operator==(right));
}

/**
 *  Less-than operator.
 *
 *  @param[in] right Object to compare to.
 *
 *  @return True if this object is less than right.
 */
bool daterange::operator<(daterange const& right) const throw () {
  if (_month_end != right._month_end)
    return (_month_end < right._month_end);
  else if (_month_start != right._month_start)
    return (_month_start < right._month_start);
  else if (_month_day_end != right._month_day_end)
    return (_month_day_end < right._month_day_end);
  else if (_month_day_start != right._month_day_start)
    return (_month_day_start < right._month_day_start);
  else if (_skip_interval != right._skip_interval)
    return (_skip_interval < right._skip_interval);
  else if (_type != right._type)
    return (_type < right._type);
  else if (_week_day_end != right._week_day_end)
    return (_week_day_end < right._week_day_end);
  else if (_week_day_start != right._week_day_start)
    return (_week_day_start < right._week_day_start);
  else if (_week_day_end_offset != right._week_day_end_offset)
    return (_week_day_end_offset < right._week_day_end_offset);
  else if (_week_day_start_offset != right._week_day_start_offset)
    return (_week_day_start_offset < right._week_day_start_offset);
  else if (_year_end != right._year_end)
    return (_year_end < right._year_end);
  else if (_year_start != right._year_start)
    return (_year_start < right._year_start);
  return (_timeranges < right._timeranges);
}

/**
 *  Set month_end value.
 *
 *  @param[in] value The new month_end value.
 */
void daterange::month_end(unsigned int value) {
  _month_end = value;
}

/**
 *  Get month_end value.
 *
 *  @return The month_end value.
 */
unsigned int daterange::month_end() const throw () {
  return (_month_end);
}

/**
 *  Set month_start value.
 *
 *  @param[in] value The new month_start value.
 */
void daterange::month_start(unsigned int value) {
  _month_start = value;
}

/**
 *  Get month_start value.
 *
 *  @return The month_start value.
 */
unsigned int daterange::month_start() const throw () {
  return (_month_start);
}

/**
 *  Set month_day_end value.
 *
 *  @param[in] value The new month_day_end value.
 */
void daterange::month_day_end(int value) {
  _month_day_end = value;
}

/**
 *  Get month_day_end value.
 *
 *  @return The month_day_end value.
 */
int daterange::month_day_end() const throw () {
  return (_month_day_end);
}

/**
 *  Set month_day_start value.
 *
 *  @param[in] value The new month_day_start value.
 */
void daterange::month_day_start(int value) {
  _month_day_start = value;
}

/**
 *  Get month_day_start value.
 *
 *  @return The month_day_start value.
 */
int daterange::month_day_start() const throw () {
  return (_month_day_start);
}

/**
 *  Set skip_interval value.
 *
 *  @param[in] value The new skip_interval value.
 */
void daterange::skip_interval(unsigned int value) {
  _skip_interval = value;
}

/**
 *  Get skip_interval value.
 *
 *  @return The skip_interval value.
 */
unsigned int daterange::skip_interval() const throw () {
  return (_skip_interval);
}

/**
 *  Get timeranges value.
 *
 *  @return The timeranges value.
 */
void daterange::timeranges(std::list<timerange> const& value) {
  _timeranges = value;
}

/**
 *  Set timeranges value.
 *
 *  @param[in] value The new timeranges value.
 */
std::list<timerange> const& daterange::timeranges() const throw () {
  return (_timeranges);
}

/**
 *  Set type value.
 *
 *  @param[in] value The new type value.
 */
void daterange::type(type_range value) {
  _type = value;
}

/**
 *  Get type value.
 *
 *  @return The type value.
 */
daterange::type_range daterange::type() const throw () {
  return (_type);
}

/**
 *  Set week_day_end value.
 *
 *  @param[in] value The new week_day_end value.
 */
void daterange::week_day_end(unsigned int value) {
  _week_day_end = value;
}

/**
 *  Get week_day_end value.
 *
 *  @return The week_day_end value.
 */
unsigned int daterange::week_day_end() const throw () {
  return (_week_day_end);
}

/**
 *  Set week_day_start value.
 *
 *  @param[in] value The new week_day_start value.
 */
void daterange::week_day_start(unsigned int value) {
  _week_day_start = value;
}

/**
 *  Get week_day_start value.
 *
 *  @return The week_day_start value.
 */
unsigned int daterange::week_day_start() const throw () {
  return (_week_day_start);
}

/**
 *  Set week_day_end_offset value.
 *
 *  @param[in] value The new week_day_end_offset value.
 */
void daterange::week_day_end_offset(int value) {
  _week_day_end_offset = value;
}

/**
 *  Get week_day_end_offset value.
 *
 *  @return The week_day_end_offset value.
 */
int daterange::week_day_end_offset() const throw () {
  return (_week_day_end_offset);
}

/**
 *  Set week_day_start_offset value.
 *
 *  @param[in] value The new week_day_start_offset value.
 */
void daterange::week_day_start_offset(int value) {
  _week_day_start_offset = value;
}

/**
 *  Get week_day_start_offset value.
 *
 *  @return The week_day_start_offset value.
 */
int daterange::week_day_start_offset() const throw () {
  return (_week_day_start_offset);
}

/**
 *  Set year_end value.
 *
 *  @param[in] value The new year_end value.
 */
void daterange::year_end(unsigned int value) {
  _year_end = value;
}

/**
 *  Get year_end value.
 *
 *  @return The year_end value.
 */
unsigned int daterange::year_end() const throw () {
  return (_year_end);
}

/**
 *  Set year_start value.
 *
 *  @param[in] value The new year_start value.
 */
void daterange::year_start(unsigned int value) {
  _year_start = value;
}

/**
 *  Get year_start value.
 *
 *  @return The year_start value.
 */
unsigned int daterange::year_start() const throw () {
  return (_year_start);
}

// UTILITIES

/**
 *  Internal struct time information.
 */
struct daterange::time_info {
  time_t current_time;
  tm     curtime;
  time_t midnight;
  time_t preferred_time;
  tm     preftime;
};

/**
 *  Add a round number of days (expressed in seconds) to a date.
 *
 *  @param[in] middnight  Midnight of base day.
 *  @param[in] skip       Number of days to skip (in seconds).
 *
 *  @return Midnight of the day in skip seconds.
 */
static time_t _add_round_days_to_midnight(time_t midnight, time_t skip) {
  // Compute expected time with no DST.
  time_t next_day_time(midnight + skip);
  struct tm next_day;
  localtime_r(&next_day_time, &next_day);

  // There was a DST shift in between.
  if (next_day.tm_hour || next_day.tm_min || next_day.tm_sec) {
    /*
    ** The trick here is to move from midnight to noon, add the skip
    ** seconds and break time down in a tm structure. We're now sure to
    ** be in the proper day (DST shift is +-1h) we only have to reset
    ** time to midnight, convert back and we're done.
    */
    next_day_time += 12 * 60 * 60 + skip;
    localtime_r(&next_day_time, &next_day);
    next_day.tm_hour = 0;
    next_day.tm_min = 0;
    next_day.tm_sec = 0;
    next_day_time = mktime(&next_day);
  }

  return (next_day_time);
}

/**
 *  Returns a time (midnight) of particular (3rd, last) day in a given
 *  month.
 *
 *  @param[in] year      Year.
 *  @param[in] month     Month.
 *  @param[in] monthday  Day in month.
 *
 *  @return Requested timestamp, (time_t)-1 if conversion failed.
 */
static time_t calculate_time_from_day_of_month(
                int year,
                int month,
                int monthday) {
  time_t midnight;
  tm t;

  // Positive day (3rd day).
  if (monthday > 0) {
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_year = year;
    t.tm_mon = month;
    t.tm_mday = monthday;
    t.tm_isdst = -1;
    midnight = mktime(&t);

    // If we rolled over to the next month, time is invalid, assume the
    // user's intention is to keep it in the current month.
    if (t.tm_mon != month)
      midnight = (time_t)-1;
  }
  // Negative offset (last day, 3rd to last day).
  else {
    // Find last day in the month.
    int day(32);
    do {
      // Back up a day.
      --day;

      // Make the new time.
      t.tm_mon = month;
      t.tm_year = year;
      t.tm_mday = day;
      t.tm_isdst = -1;
      midnight = mktime(&t);
    } while ((midnight == (time_t)-1)
             || (t.tm_mon != month));

    // Now that we know the last day, back up more.
    t.tm_mon = month;
    t.tm_year = year;
    // Beware to roll over the whole month.
    if (-monthday >= t.tm_mday)
      t.tm_mday = 1;
    // -1 means last day of month, so add one to make this correct.
    else
      t.tm_mday += monthday + 1;
    t.tm_isdst = -1;
    midnight = mktime(&t);
  }

  return (midnight);
}

/**
 *  Returns a time (midnight) of particular (3rd, last) weekday in a
 *  given month.
 *
 *  @param[in] year            Year.
 *  @param[in] month           Month.
 *  @param[in] weekday         Target weekday.
 *  @param[in] weekday_offset  Weekday offset (1 is first, 2 is second,
 *                             -1 is last).
 *
 *  @return Requested timestamp, (time_t)-1 if conversion failed.
 */
static time_t calculate_time_from_weekday_of_month(
                int year,
                int month,
                int weekday,
                int weekday_offset) {
  // Compute first day of month (to get weekday).
  tm t;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_year = year;
  t.tm_mon = month;
  t.tm_mday = 1;
  t.tm_isdst = -1;
  time_t midnight(mktime(&t));

  // How many days must we advance to reach the first instance of the
  // weekday this month ?
  int days(weekday - (t.tm_wday));
  if (days < 0)
    days += 7;

  // Positive offset (3rd thursday).
  if (weekday_offset > 0) {
    // How many weeks must we advance (no more than 5 possible).
    int weeks((weekday_offset > 5) ? 5 : weekday_offset);
    days += ((weeks - 1) * 7);

    // Make the new time.
    t.tm_mon = month;
    t.tm_year = year;
    t.tm_mday = days + 1;
    t.tm_isdst = -1;
    midnight = mktime(&t);

    // If we rolled over to the next month, time is invalid, assume the
    // user's intention is to keep it in the current month.
    if (t.tm_mon != month)
      midnight = (time_t)-1;
  }
  // Negative offset (last thursday, 3rd to last tuesday).
  else {
    // Find last instance of weekday in the month.
    days += (5 * 7);
    do {
      // Back up a week.
      days -= 7;

      // Make the new time.
      t.tm_mon = month;
      t.tm_year = year;
      t.tm_mday = days + 1;
      t.tm_isdst = -1;
      midnight = mktime(&t);
    } while ((midnight == (time_t)-1)
             || (t.tm_mon != month));

    // Now that we know the last instance of the weekday, back up more.
    days = ((weekday_offset + 1) * 7);
    t.tm_mon = month;
    t.tm_year = year;
    // Beware to roll over the whole month.
    if (-days >= t.tm_mday)
      t.tm_mday = t.tm_mday % 7;
    else
      t.tm_mday += days;
    t.tm_isdst = -1;
    midnight = mktime(&t);
  }

  return (midnight);
}

// TO TIME_T

/**
 *  Calculate start time and end time for date range calendar date.
 *
 *  @param[in]  ti     Time informations.
 *  @param[out] start  Variable to fill start time.
 *  @param[out] end    Variable to fill end time.
 *
 *  @return True on success, otherwise false.
 */
bool daterange::_calendar_date_to_time_t(time_t& start,
                                         time_t& end) const {
  tm t;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_isdst = -1;

  t.tm_mday = _month_day_start;
  t.tm_mon = _month_start;
  t.tm_year =  _year_start - 1900;
  if ((start = mktime(&t)) == (time_t)-1)
    return (false);

  if (_year_end) {
    t.tm_mday = _month_day_end;
    t.tm_mon = _month_end;
    t.tm_year = _year_end - 1900;
    t.tm_hour = 23;
    t.tm_min = 59;
    t.tm_sec = 59;
    /*
    ** We don't have to care about DST even if it would occur at
    ** midnight because end time is used as the upper bound of the date
    ** range. This make it invalid for use as midnight but perfectly
    ** valid to check that we're less than or equal to 23:59:59, which
    ** value is provided by mktime().
    */
    if ((end = mktime(&t)) == (time_t)-1)
      return (false);
    ++end;
  }
  else
    end = (time_t)-1;

  return (true);
}

/**
 *  Calculate start time and end time for date range month date.
 *
 *  @param[in]  ti     Time informations.
 *  @param[out] start  Variable to fill start time.
 *  @param[out] end    Variable to fill end time.
 *
 *  @return True on success, otherwise false.
 */
bool daterange::_month_date_to_time_t(time_info const& ti,
                                      time_t& start,
                                      time_t& end) const {
  // what year should we use?
  int year(std::max(ti.preftime.tm_year, ti.curtime.tm_year));
  // advance an additional year if we already passed
  // the end month date
  if (_month_end < ti.curtime.tm_mon
      || (_month_end == ti.curtime.tm_mon
          && _month_day_end < ti.curtime.tm_mday))
    ++year;
  start = calculate_time_from_day_of_month(year, _month_start, _month_day_start);

  // start date was bad.
  if (!start)
    return (false);

  // use same year as was calculated for start time above
  end = calculate_time_from_day_of_month(year, _month_end, _month_day_end);
  // advance a year if necessary: august 5 - february 2
  if (end < start)
    end = calculate_time_from_day_of_month( ++year, _month_end, _month_day_end);

  // end date was bad - see if we can handle the error
  if (!end) {
    // end date can't be helped, so skip it
    if (_month_day_end < 0)
      return (false);
    // else end date slipped past end of month, so use last
    // day of month as end date
    end = calculate_time_from_day_of_month(year, _month_end, -1);
  }
  return (true);
}

/**
 *  Calculate start time and end time for date range month day.
 *
 *  @param[in]  ti     Time informations.
 *  @param[out] start  Variable to fill start time.
 *  @param[out] end    Variable to fill end time.
 *
 *  @return True on success, otherwise false.
 */
bool daterange::_month_day_to_time_t(time_info const& ti,
                                     time_t& start,
                                     time_t& end) const {
  // What year/month should we use ?
  int year;
  int month;
  if (ti.preferred_time > ti.current_time) {
    year = ti.preftime.tm_year;
    month = ti.preftime.tm_mon;
    // Advance an additional month (and possibly the year) if
    // we already passed the end day of month.
    if (ti.preftime.tm_mday > _month_day_end) {
      if (month != 11)
        ++month;
      else {
        month = 0;
        ++year;
      }
    }
  }
  else {
    year = ti.curtime.tm_year;
    month = ti.curtime.tm_mon;
    // Advance an additional month (and possibly the year) if
    // we already passed the end day of month.
    if (ti.curtime.tm_mday > _month_day_end) {
      if (month != 11)
        ++month;
      else {
        month = 0;
        ++year;
      }
    }
  }

  // Compute start date.
  start = calculate_time_from_day_of_month(year, month, _month_day_start);
  if (start == (time_t)-1)
    return (false);

  // Use same year and month as was calculated for start time above.
  end = calculate_time_from_day_of_month(year, month, _month_day_end);
  if (end == (time_t)-1) {
    // End date can't be helped, so skip it.
    if (_month_day_end < 0)
      return (false);

    // Else end date slipped past end of month,
    // so use first day of next month.
    if (month != 11)
      ++month;
    else {
      month = 0;
      ++year;
    }
    end = calculate_time_from_day_of_month(year, month, 0);
  }
  else
    end = _add_round_days_to_midnight(end, 24 * 60 * 60);
  return (true);
}

/**
 *  Calculate start time and end time for date range month week day.
 *
 *  @param[in]  ti     Time informations.
 *  @param[out] start  Variable to fill start time.
 *  @param[out] end    Variable to fill end time.
 *
 *  @return True on success, otherwise false.
 */
bool daterange::_month_week_day_to_time_t(time_info const& ti,
                                         time_t& start,
                                         time_t& end) const {
  // What year should we use?
  int year(std::max(ti.preftime.tm_year, ti.curtime.tm_year));

  while (true) {
    // Calculate time of specified weekday of specific month.
    start = calculate_time_from_weekday_of_month(
              year,
              _month_start,
              _week_day_start,
              _week_day_start_offset);
    if ((time_t)-1 == start)
      return (false);

    // Use same year as was calculated for start time above.
    end = calculate_time_from_weekday_of_month(
            year,
            _month_end,
            _week_day_end,
            _week_day_end_offset);

    // Advance a year if necessary :
    // thursday 2 august - monday 3 february
    if ((end != (time_t)-1) && (end < start))
      end = calculate_time_from_weekday_of_month(
              year + 1,
              _month_end,
              _week_day_end,
              _week_day_end_offset);

    if ((time_t)-1 == end) {
      // End date can't be helped, so skip it.
      if (_week_day_end_offset < 0)
        return (false);

      // Else end date slipped past end of month, so use last day
      // of month as end date.
      int end_month;
      int end_year;
      if (_month_end != 11) {
        end_month = _month_end + 1;
        end_year = year;
      }
      else {
        end_month = 0;
        end_year = year + 1;
      }
      end = calculate_time_from_day_of_month(
              end_year,
              end_month,
              0);
      if ((time_t)-1 == end)
        return (false);
    }
    else
      end = _add_round_days_to_midnight(end, 24 * 60 * 60);

    // We should have an interval that includes or is above
    // preferred time.
    if (ti.preferred_time < end)
      break ;
    // Advance to next year if we've passed this month
    // weekday already this year.
    else
      ++year;
  }

  return (true);
}

/**
 *  Calculate start time and end time for date range week day.
 *
 *  @param[in]  ti     Time informations.
 *  @param[out] start  Variable to fill start time.
 *  @param[out] end    Variable to fill end time.
 *
 *  @return True on success, otherwise false.
 */
bool daterange::_week_day_to_time_t(time_info const& ti,
                                    time_t& start,
                                    time_t& end) const {
  // What year/month should we use ?
  int year;
  int month;
  if (ti.preferred_time > ti.current_time) {
    year = ti.preftime.tm_year;
    month = ti.preftime.tm_mon;
  }
  else {
    year = ti.curtime.tm_year;
    month = ti.curtime.tm_mon;
  }

  while (true) {
    // Calculate time of specified weekday of month.
    start = calculate_time_from_weekday_of_month(
              year,
              month,
              _week_day_start,
              _week_day_start_offset);

    // Use same year and month as was calculated for start time above.
    end = calculate_time_from_weekday_of_month(
            year,
            month,
            _week_day_end,
            _week_day_end_offset);
    if (end == (time_t)-1) {
      // End date can't be helped, so skip it.
      if (_week_day_end_offset < 0)
        return (false);

      // Else end date slipped past end of month, so use last day
      // of month as end date.
      int end_month;
      int end_year;
      if (month != 11) {
        end_month = month + 1;
        end_year = year;
      }
      else {
        end_month = 0;
        end_year = year + 1;
      }
      end = calculate_time_from_day_of_month(end_year, end_month, 0);
    }
    else
      end = _add_round_days_to_midnight(end, 24 * 60 * 60);

    // Error checking.
    if (((time_t)-1 == start)
        || ((time_t)-1 == end)
        || (start > end))
      return (false);

    // We should have an interval that includes or is above
    // preferred time.
    if (ti.preferred_time < end)
      break ;
    // Advance to next month (or year) if we've passed this weekday of
    // this month already.
    else {
      month = ti.preftime.tm_mon;
      if (month != 11)
        ++month;
      else {
        month = 0;
        ++year;
      }
    }
  }

  return (true);
}

/**
 *  Calculate start time and end time for date range.
 *
 *  @param[in]  preferred_time  Preferred time.
 *  @param[out] start  Variable to fill start time.
 *  @param[out] end    Variable to fill end time.
 *
 *  @return True on success, otherwise false.
 */
bool daterange::to_time_t(time_t const preferred_time,
                          time_t& start,
                          time_t& end) const {
  bool ret = false;

  // Compute time information.
  time_info ti;
  ti.preferred_time = preferred_time;
  ti.current_time = time(NULL);
  localtime_r(&ti.current_time, &ti.curtime);
  localtime_r(&preferred_time, &ti.preftime);
  ti.preftime.tm_sec = 0;
  ti.preftime.tm_min = 0;
  ti.preftime.tm_hour = 0;
  ti.midnight = mktime(&ti.preftime);

  switch (_type) {
  case calendar_date:
    ret = _calendar_date_to_time_t(start, end);
    break;
  case month_date:
    ret = _month_date_to_time_t(ti, start, end);
    break;
  case month_day:
    ret = _month_day_to_time_t(ti, start, end);
    break;
  case month_week_day:
    ret = _month_week_day_to_time_t(ti, start, end);
    break;
  case week_day:
    ret = _week_day_to_time_t(ti, start, end);
    break;
  default:
    break;
  }
  if (!ret)
    return (false);

  // If skipping days...
  if (_skip_interval > 1) {
    // Advance to the next possible skip date
    if (start < ti.preferred_time) {
      // How many days have passed between skip start date
      // and preferred time ?
      unsigned long days((ti.midnight - (unsigned long)start)
                         / (3600 * 24));

      // Advance start date to next skip day
      if (!(days % _skip_interval))
        start = _add_round_days_to_midnight(start, days * 24 * 60 * 60);
      else
        start = _add_round_days_to_midnight(
                  start,
                  ((days - (days % _skip_interval) + _skip_interval)
                   * 24 * 60 * 60));
    }
  }

  return (true);
}
