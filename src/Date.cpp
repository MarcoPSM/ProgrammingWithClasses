//
// Created by marco on 12-03-2023.
//

#include <ctime>
#include "Date.h"
#include "UtilityFunctions.h"

namespace mar {

    // Static data members

    const int Date::firstYear = 1601;
    const int Date::firstCentury = 17;
    const Date Date::first(Date::firstYear, 1, 1);
    const Date::WeekdayType Date::firstWeekday = MONDAY;
    const int Date::daysInMonth[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    const int Date::accumulated[2][12] = {{31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
                                          {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};
    const int Date::fourYears = 365 * 4 + 1;            //   1461
    const int Date::oneCentury = fourYears * 25 - 1;    //  36524
    const int Date::fourCenturies = oneCentury * 4 + 1; // 146097

    // public methods

    Date::Date() {
        time_t time0 = ::time(0);
        struct ::tm *now = ::localtime(&time0);
        count = Count(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    }
    Date::Date(const Date &other):
        count(other.count) {

    }
    Date::Date(int year, int month, int day):
        count(Count(year, month, day)) {

    }
    Date::Date(int year, int dayNumber):
        count(FirstDayOfYear(year) + dayNumber - 1) {

    }
    Date::Date(int year, int week, WeekdayType weekday):
        count(0) {
        Set(year, week, weekday);
    }

    Date::~Date() noexcept {

    }

    void Date::Copy(const Date &other) {
        count = other.count;
    }

    Date &Date::operator=(const Date &other) {
        Copy(other);
        return *this;
    }

    void Date::Set(int year, int month, int day) {
        count = Count(year, month, day);
    }

    void Date::Set(int year, int dayNumber) {
        count = Count(year, 1, 1) + dayNumber - 1;
    }

    void Date::Set(int year, int week, WeekdayType weekday) {
        Set(year, 1, 1);
        ReachForward(THURSDAY);
        ReachBackward(MONDAY);
        AddWeek(week-1);
        ReachForward(weekday);
    }

    int Date::Count() const {
        return count;
    }

    int Date::Century() const {
        return firstCentury +
            count / fourCenturies * 4 +
            Min(count % fourCenturies / oneCentury, 3);
    }

    int Date::DayNumber() const {
        return count - FirstDayOfYear(Year() ) + 1;
    }

    int Date::MonthSize() const {
        return DaysInMonth(Year(), Month());
    }

    int Date::YearSize() const {
        return DaysInYear(Year());
    }

    int Date::CenturySize() const {
        return DaysInCentury(Century());
    }


    int Date::Year() const {
        int c = Century();
        int days = count - FirstDayOfCentury(c);
        return FirstYearOfCentury(c) +
            days / fourYears * 4 + Min(days % fourYears /365, 3);
    }

    int Date::Month() const {
        bool leap = InLeapYear();
        int dayNumber = DayNumber();
        int result = 1;
        while (accumulated[leap][result-1] < dayNumber) {
            result++;
        }
        return result;
    }

    int Date::Day() const {
        return count - FirstDayOfMonth(Year(), Month()) + 1;
    }

    int Date::WeekNumber() const {
        return DaysSince(Date(WeekYear(), 1, MONDAY)) / 7 + 1;
    }

    int Date::WeekYear() const {
        Date monday(*this);
        monday.ReachBackward(MONDAY);
        int result = monday.Year();
        Date sunday(*this);
        sunday.ReachForward(SUNDAY);
        if (result != sunday.Year() && Date(result+1,1,1).Weekday() <= THURSDAY) {
            result++;
        }
        return result;
    }

    Date::WeekdayType Date::Weekday() const {
        return static_cast<WeekdayType>((Count() + firstWeekday) % 7);
    }

    bool Date::Weekend() const {
        return Weekday() == SATURDAY || Weekday() == SUNDAY;
    }

    bool Date::Workday() const {
        return !Weekend() && !Holiday();
    }

    bool Date::Holiday() const {
        return false;
    }


    const Date &Date::First() const {
        return first;
    }

    int Date::DaysTo(const Date &other) const {
        return other.count - this->count;
    }

    int Date::DaysSince(const Date &other) const {
        return this->count - other.count;
    }

    int Date::Age(const Date &other) const {
        return this->Year() - other.Year() - (this->Month() < other.Month() ||
                                          this->Month() == other.Month() &&
                                          this->Day() < other.Day());
    }

    void Date::Forth() {
        count++;
    }

    void Date::Back() {
        count--;
    }

    void Date::Add(int x) {
        count += x;
    }

    void Date::Subtract(int x) {
        count -= x;
    }

    bool Date::InLeapYear() const {
        return LeapYear(Year());
    }

    bool Date::operator==(const Date &other) const {
        return this->Day() == other.Day() &&
               this->Month() == other.Month() &&
               this->Year() == other.Year();
    }

    bool Date::operator!=(const Date &other) const {
        return ! operator == (other);
    }

    bool Date::operator<=(const Date &other) const {
        return this->Year() < other.Year() ||
               this->Year() == other.Year() && (
                       this->Month() < other.Month() ||
                       this->Month() == other.Month() &&
                       this->Day() <= other.Day());
    }

    bool Date::operator<(const Date &other) const {
        return operator<=(other) && !operator==(other);
    }

    bool Date::operator>=(const Date &other) const {
        return !operator<=(other) || operator==(other);
    }

    bool Date::operator>(const Date &other) const {
        return !operator<=(other);
    }

    const Date &Date::operator++(int) {
        count++;
        return *this;
    }

    const Date &Date::operator--(int) {
        count--;
        return *this;
    }

    Date &Date::operator+=(int x) {
        count += x;
        return *this;
    }

    Date &Date::operator-=(int x) {
        count -= x;
        return *this;
    }

    Date Date::operator+(int x) const {
        Date result(*this);
        result += x;
        return result;
    }

    Date Date::operator-(int x) const {
        Date result(*this);
        result -= x;
        return result;
    }

    int Date::operator-(const Date &other) const {
        return this->count - other.count;
    }

    void Date::Write(std::ostream &output) const {
        output << Year() << "/" << Month() << "/" << Day();
    }

    void Date::WriteLine(std::ostream &output) const {
        Write(output);
        output << std::endl;
    }

    void Date::Accept(const std::string &prompt, const std::string &errorMessage) {
        int y = 0;
        int m = 0;
        int d = 0;
        for (;;) {
            std::cout << prompt;
            std::cin >> y >> m >> d;
            if (std::cin.fail()) {
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<int>::max(), '\n'); // skip to end of line
            if (Date::Valid(y, m, d)) {
                break;
            }
            std::cout << errorMessage << std::endl;
        }
        Set(y, m, d);
    }


    std::ostream& operator << (std::ostream& output, const Date& d) {
        d.Write(output);
        return output;
    }

    void Date::AddWeek(int x) {
        Add(7*x);
    }

    void Date::SubtractWeek(int x) {
        Subtract(7*x);
    }

    void Date::ReachForward(WeekdayType weekday) {
        Add((7 + Weekday() - WeekdayType()) % 7);
    }

    void Date::ReachBackward(WeekdayType weekday) {
        Subtract((7 + Weekday() - WeekdayType()) % 7);
    }


    // static methods
    int Date::DaysInMonth(int y, int m) {
        bool leap = LeapYear(y);
        return daysInMonth[leap][m - 1];
    }

    int Date::DaysInYear(int y) {
        return 365 + LeapYear(y);
    }

    int Date::DaysInCentury(int c) {
        return 365 * 100 + 25 - (c % 4 != 0);
    }

    int Date::Count(int y, int m, int d) {
        return Date::FirstDayOfMonth(y, m) + d - 1;
    }

    bool mar::Date::LeapYear(int y) {
        return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
    }

    int Date::FirstDayOfMonth(int y, int m) {
        bool leap = LeapYear(y);
        return FirstDayOfYear(y) + (accumulated[leap][m-1] - daysInMonth[leap][m-1]);
    }

    int Date::FirstDayOfYear(int y) {
        return FirstDayOfCentury(CenturyOf(y)) +
            (y-1) % 100 / 4 * fourYears + (y-1) % 4 * 365;
    }

    int Date::FirstDayOfCentury(int c) {
        return (c - firstCentury) / 4 * fourCenturies + (c - firstCentury) % 4 * oneCentury;
    }

    int Date::CenturyOf(int y) {
        return (y-1) / 100 + 1;
    }

    int Date::FirstYearOfCentury(int c) {
        return (c - 1) * 100 + 1;
    }

    bool Date::Valid(int y, int m, int d) {
        return Valid(y, m) && 1 <= d && d <= DaysInMonth(y, m);
    }
    bool Date::Valid(int y, int m) {
        return Valid(y) && 1 <= m && m <= 12;
    }
    bool Date::Valid(int y) {
        return firstYear <= y;
    }




} // mar