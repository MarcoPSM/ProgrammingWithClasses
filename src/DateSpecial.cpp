//
// Created by marco on 17-03-2023.
//

#include "DateSpecial.h"
#include "iomanip"
#include <sstream>

namespace mar {
    DateSpecial::DateSpecial():
        DatePortuguese() {

    }

    DateSpecial::DateSpecial(const DateSpecial &other):
        DatePortuguese(other) {

    }

    DateSpecial::DateSpecial(int year, int month, int day):
        DatePortuguese(year, month, day) {

    }

    DateSpecial::~DateSpecial() {

    }

    bool DateSpecial::Friday13() const {
        return Day() == 13 && Weekday() == FRIDAY;
    }

    void DateSpecial::ReachFirstMillenaryAfter(const DatePortuguese &other) {
        int days = DaysTo(other);
        int daysLeft = 1000 - ((days + 999) % 1000 + 1);
        Add(days + daysLeft);
    }

    void DateSpecial::AdvanceToWorkingDay() {
        do {
            Forth();
        } while (!Workday());
    }

    void DateSpecial::AdvanceToWorkingDay(int x) {
        for (int i = 0; i < x; ++i) {
            AdvanceToWorkingDay();
        }
    }

    void DateSpecial::ReturnToWork(int x) {
        AdvanceToWorkingDay(x + ! Workday());
    }

    bool DateSpecial::Bridge() const {
        return Workday()
            && ! DatePortuguese(operator-(1)).Workday()
            && ! DatePortuguese(operator+(1)).Workday();
    }

    void DateSpecial::WriteBridges(std::ostream &output, int n) const {
        DateSpecial d(*this);
        int count = 0;
        while (count < n) {
            if (d.Bridge()) {
                output << d << std::endl;
                count++;
            }
            d++;
        }
    }

    int DateSpecial::DaysAway(int n) const {
        DateSpecial d(*this);
        d.ReturnToWork(n);
        return DaysTo(d);
    }

    DateSpecial DateSpecial::DepartForVacations(int y, int n) {
        DateSpecial result(y, 1, 1);
        int current = 0;
        for (DateSpecial d(y, 1, 1); d.Year() == y; d++) {
            int temp = d.DaysAway(n);
            if (temp > current) {
                result = d;
                current = temp;
            }
        }
        return result;
    }

    void DateSpecial::WriteCalendarDay(std::ostream &output) const {
        output << std::setw(3);
        if (Holiday()) {
            if (Easter()) {
                output << "P";
            } else if (Christmas()) {
                output << "N";
            } else if (Carnival()) {
                output << "E";
            } else {
                output << "F";
            }
        } else {
            output << Day();
        }
    }

    void DateSpecial::WriteCalendarMonth(std::ostream &output) const {
        int m = Month();
        std::stringstream sst;
        DateSpecial d(Year(), m, 1);
        sst << std::setw(3 * static_cast<int>(d.Weekday())) << "";
        for(;d.Month() == m; d++) {
            d.WriteCalendarDay(sst);
        }
        SplitStream(sst, output, 3*7);
    }

    void DateSpecial::SplitStream(std::istream &input, std::ostream &output, int size) {
        int count = 0;
        char c;
        while (input >> std::noskipws >> c) {
            if (count==size) {
                output << std::endl;
                count = 0;
            }
            output << c;
            count++;
        }
        output << std::endl;
    }

} // mar