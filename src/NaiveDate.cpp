//
// Created by marco on 27-02-2023.
//

#include "NaiveDate.h"
#include <ctime>

const int mar::NaiveDate::firstYear = 1901;
const mar::NaiveDate mar::NaiveDate::first(NaiveDate::firstYear, 1, 1);
const mar::NaiveDate::WeekdayType mar::NaiveDate::firstWeekDay = TUESDAY;
const int mar::NaiveDate::daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

mar::NaiveDate::NaiveDate() {
    time_t time0 = ::time(0);
    struct ::tm *now = ::localtime(&time0);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}

mar::NaiveDate::NaiveDate(const mar::NaiveDate &other):
    year(other.year), month(other.month), day(other.day) {

}

mar::NaiveDate::NaiveDate(int year, int month, int day):
        year(year), month(month), day(day) {

}

mar::NaiveDate::~NaiveDate() {

}

int mar::NaiveDate::Year() const {
    return year;
}

int mar::NaiveDate::Month() const {
    return month;
}

int mar::NaiveDate::Day() const {
    return day;
}

int mar::NaiveDate::Century() const {
    return CenturyOf(year);
}


void mar::NaiveDate::Write(std::ostream &output) const {
    output << year << "-" << month << "-" << day;
}

void mar::NaiveDate::WriteLine(std::ostream &output) const {
    Write(output);
    output << std::endl;
}

void mar::NaiveDate::Forth() {
    if (day < MonthSize()) {
        day++;
    } else {
        day = 1;
        if (month < 12) {
            month++;
        } else {
            month = 1;
            year++;
        }
    }
}

void mar::NaiveDate::Back() {
    if (day >1) {
        day--;
    } else {
        if (month > 1) {
            month--;
        } else {
            month = 12;
            year--;
        }
        day = MonthSize();
    }
}

bool mar::NaiveDate::InLeapYear() const {
    return LeapYear(year);
}

int mar::NaiveDate::YearSize() const {
    return DaysInYear(year);
}

int mar::NaiveDate::CenturySize() const {
    return 100;
}

int mar::NaiveDate::MonthSize() const {
    return DaysInMonth(year, month);
}

bool mar::NaiveDate::operator==(const mar::NaiveDate &other) const {
    return this->day == other.day &&
            this->month == other.month &&
            this->year == other.year;
}

bool mar::NaiveDate::operator!=(const mar::NaiveDate &other) const {
    return ! operator == (other);
}

bool mar::NaiveDate::operator<=(const mar::NaiveDate &other) const {
    return this->year < other.year ||
            this->year == other.year && (
                    this->month < other.month ||
                    this->month == other.month &&
                    this->day <= other.day);
}

bool mar::NaiveDate::operator<(const mar::NaiveDate &other) const {
    return operator<=(other) && !operator==(other);
}

bool mar::NaiveDate::operator>=(const mar::NaiveDate &other) const {
    return !operator<=(other) || operator==(other);
}

bool mar::NaiveDate::operator>(const mar::NaiveDate &other) const {
    return !operator<=(other);
}

int mar::NaiveDate::DaysTo(const NaiveDate &other) const {
    int result = 0;
    NaiveDate temp(*this);
    while (temp < other) {
        temp.Forth();
        result++;
    }
    return result;
}

int mar::NaiveDate::DaysSince(const NaiveDate &other) const {
    return other.DaysTo(*this);
}

mar::NaiveDate::WeekdayType mar::NaiveDate::Weekday() const {
    return static_cast<WeekdayType>((Count() + firstWeekDay) % 7);
}

int mar::NaiveDate::Age(const NaiveDate &other) const {
    return this->year - other.year - (this->month < other.month ||
                                        this->month == other.month &&
                                        this->day < other.day);
}

const mar::NaiveDate& mar::NaiveDate::First() const {
    return first;
}

int mar::NaiveDate::Count() const {
    return DaysSince(first);
}

bool mar::NaiveDate::IsValid() const {
    return Valid(year, month, day);
}

bool mar::NaiveDate::LeapYear(int y) {
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}

int mar::NaiveDate::DaysInMonth(int y, int m) {
    return daysInMonth[m-1]+(m==2 && LeapYear(y));
}

int mar::NaiveDate::DaysInYear(int y) {
    return 365 + LeapYear(y);
}

int mar::NaiveDate::CenturyOf(int y) {
    return (y-1) / 100 + 1;
}

int mar::NaiveDate::DaysInCentury(int c) {
    return 365 * 100 + 25 - (c % 4 != 0);
}

bool mar::NaiveDate::Valid(int y, int m, int d) {
    return Valid(y, m) && 1 <= d && d <= DaysInMonth(y, m);
}
bool mar::NaiveDate::Valid(int y, int m) {
    return Valid(y) && 1 <= m && m <= 12;
}
bool mar::NaiveDate::Valid(int y) {
    return firstYear <= y;
}