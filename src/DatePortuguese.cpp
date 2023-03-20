//
// Created by marco on 17-03-2023.
//

#include "DatePortuguese.h"
#include <iomanip>

namespace mar {
    const std::string DatePortuguese::monthNames[] = {
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio",
            "Junho", "Julho", "Agosto", "Setembro", "Outubro",
            "Novembro", "Dezembro"
    };
    const std::string DatePortuguese::weekdayNames[] = {
        "segunda-feira", "terça-feira", "quarta-feira",
        "quinta-feira", "sexta-feira", "sábado", "domingo",
    };

    DatePortuguese::FormatType DatePortuguese::format = DEFAULT;
    char DatePortuguese::separator = '/';
    bool DatePortuguese::enabledHolidays = true;


    DatePortuguese::DatePortuguese():
        Date() {

    }

    DatePortuguese::DatePortuguese(const DatePortuguese &other):
        Date(other) {

    }

    DatePortuguese::DatePortuguese(int year, int month, int day):
        Date(year, month, day) {

    }

    DatePortuguese::DatePortuguese(int year, int dayNumber):
        Date(year, dayNumber) {

    }

    DatePortuguese::DatePortuguese(const Date &other):
        Date(other) {

    }

    DatePortuguese::~DatePortuguese() {

    }



    const std::string &DatePortuguese::MonthName() const {
        return MonthName(Month());
    }

    const std::string &DatePortuguese::WeekdayName() const {
        return WeekdayName(Weekday());
    }

    bool DatePortuguese::Holiday() const {
        return EnabledHolidays() &&
                (NewYear() || Liberty() || Workers()
                || Nation() || Assumption() || Republic()
                || AllSaints() || Independence() || OurLady()
                || Christmas() || Carnival() || GoodFriday()
                || Easter() || CorpusChristi());
    }

    bool DatePortuguese::NewYear() const {
        return operator==(NewYear(Year()) );
    }

    bool DatePortuguese::Liberty() const {
        return operator==(Liberty(Year()) );
    }

    bool DatePortuguese::Workers() const {
        return operator==(Workers(Year()) );
    }

    bool DatePortuguese::Nation() const {
        return operator==(Nation(Year()) );
    }

    bool DatePortuguese::Assumption() const {
        return operator==(Assumption(Year()) );
    }

    bool DatePortuguese::Republic() const {
        return operator==(Republic(Year()) );
    }

    bool DatePortuguese::AllSaints() const {
        return operator==(AllSaints(Year()) );
    }

    bool DatePortuguese::Independence() const {
        return operator==(Independence(Year()) );
    }

    bool DatePortuguese::OurLady() const {
        return operator==(OurLady(Year()) );
    }

    bool DatePortuguese::Christmas() const {
        return operator==(Christmas(Year()) );
    }

    bool DatePortuguese::Carnival() const {
        return operator==(Carnival(Year()) );
    }

    bool DatePortuguese::GoodFriday() const {
        return operator==(GoodFriday(Year()) );
    }

    bool DatePortuguese::Easter() const {
        return operator==(Easter(Year()) );
    }

    bool DatePortuguese::CorpusChristi() const {
        return operator==(CorpusChristi(Year()) );
    }


    void DatePortuguese::Write(std::ostream &output) const {
        switch (format) {
            case DEFAULT:
                Date::Write(output);
                break;
            case STANDARD:
                output << std::setfill('0')
                        << std::setw(2) << Year() % 100 << separator
                        << std::setw(2) << Month() << separator
                        << std::setw(2) << Day()
                        << std::setfill(' ');
                break;
            case STANDARD_FULL:
                output << std::setfill('0')
                       << std::setw(4) << Year() << separator
                       << std::setw(2) << Month() << separator
                       << std::setw(2) << Day()
                       << std::setfill(' ');
                break;
            case TEXT_WITH_WEEKDAY:
                output << WeekdayName() << ", ";
            case TEXT:
                output << Day() << " de "
                    << MonthName() << " de "
                    << Year();
                break;
            case ARMY: {
                const std::string &monthName = MonthName();
                output << std::setfill('0')
                       << std::setw(2) << Day()
                       << monthName[0]
                       << static_cast<char>(::toupper(monthName[1]))
                       << static_cast<char>(::toupper(monthName[2]))
                       << std::setw(2) << Year() % 100
                       << std::setfill(' ');
            }
                break;
            case NUMERIC:
                output << Year() * 10000 + Month() * 100 + Day();
                break;
        }
    }




    const std::string &DatePortuguese::MonthName(int m) {
        return monthNames[m-1];
    }

    const std::string &DatePortuguese::WeekdayName(Date::WeekdayType wd) {
        return weekdayNames[wd];
    }

    void DatePortuguese::SetFormat(DatePortuguese::FormatType newFormat) {
        format = newFormat;
    }

    DatePortuguese::FormatType DatePortuguese::Format() {
        return format;
    }

    void DatePortuguese::SetSeparator(char newSeparator) {
        separator = newSeparator;
    }

    char DatePortuguese::Separator() {
        return separator;
    }

    void DatePortuguese::SetEnableHolidays(bool b) {
        enabledHolidays = b;
    }

    bool DatePortuguese::EnabledHolidays() {
        return enabledHolidays;
    }

    DatePortuguese DatePortuguese::NewYear(int y) const {
        return DatePortuguese(y, 1, 1);
    }

    DatePortuguese DatePortuguese::Liberty(int y) const {
        return DatePortuguese(y, 4, 25);
    }

    DatePortuguese DatePortuguese::Workers(int y) const {
        return DatePortuguese(y, 5, 1);
    }

    DatePortuguese DatePortuguese::Nation(int y) const {
        return DatePortuguese(y, 6, 10);
    }

    DatePortuguese DatePortuguese::Assumption(int y) const {
        return DatePortuguese(y, 8, 15);
    }

    DatePortuguese DatePortuguese::Republic(int y) const {
        return DatePortuguese(y, 10, 5);
    }

    DatePortuguese DatePortuguese::AllSaints(int y) const {
        return DatePortuguese(y, 11, 1);
    }

    DatePortuguese DatePortuguese::Independence(int y) const {
        return DatePortuguese(y, 12, 1);
    }

    DatePortuguese DatePortuguese::OurLady(int y) const {
        return DatePortuguese(y, 12, 8);
    }

    DatePortuguese DatePortuguese::Christmas(int y) const {
        return DatePortuguese(y, 12, 25);
    }

    DatePortuguese DatePortuguese::Carnival(int y) const {
        return Easter(y) - 47;
    }

    DatePortuguese DatePortuguese::GoodFriday(int y) const {
        return Easter(y) - 2;
    }

    DatePortuguese DatePortuguese::Easter(int y) const {
        int a = y % 19;
        int b = y / 100;
        int c = y % 100;
        int d = b / 4;
        int e = b % 4;
        int f = (b + 8) / 25;
        int g = (b - f + 1) / 3;
        int h = (19 * a + b - d - g + 15) % 30;
        int i = c / 4;
        int k = c % 4;
        int l = (32 + 2 * e + 2 * i - h - k) % 7;
        int m = (a + 11 * h + 22 * l) / 451;
        int n = h + 1 - 7 * m + 114;
        DatePortuguese result(y, n / 31, n % 31 + 1);
        result--;
        result.ReachForward(SUNDAY);
        return result;
    }

    DatePortuguese DatePortuguese::CorpusChristi(int y) const {
        return Easter(y) + 60;
    }


} // mar