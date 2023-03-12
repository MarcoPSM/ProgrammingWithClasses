//
// Created by marco on 27-02-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_NAIVEDATE_H
#define PROGRAMACAOCOMCLASSES_NAIVEDATE_H

#include <iostream>

namespace mar {

    class NaiveDate {
    private:
        int year;
        int month;
        int day;
        // invariante IsValid();
    public:
        enum WeekdayType {
            MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
        };
        NaiveDate();
        NaiveDate(const NaiveDate& other);
        NaiveDate(int year, int month, int day);
        virtual ~NaiveDate();

        virtual int Year() const;
        virtual int Month() const;
        virtual int Day() const;
        virtual int Century() const;

        virtual bool IsValid() const;
        virtual void Forth();
        virtual void Back();

        virtual void Write(std::ostream& output = std::cout) const;
        virtual void WriteLine(std::ostream& output = std::cout) const;

        virtual WeekdayType Weekday() const;

        virtual int MonthSize() const;
        virtual int YearSize() const;
        virtual int CenturySize() const;

        virtual bool InLeapYear() const;
        virtual int DaysSince(const NaiveDate& other) const;
        virtual int DaysTo(const NaiveDate& other) const;
        virtual int Age(const NaiveDate& other) const;
        virtual const NaiveDate& First() const;
        virtual int Count() const;

        virtual bool operator == (const NaiveDate& other) const;
        virtual bool operator != (const NaiveDate& other) const;
        virtual bool operator <= (const NaiveDate& other) const;
        virtual bool operator < (const NaiveDate& other) const;
        virtual bool operator >= (const NaiveDate& other) const;
        virtual bool operator > (const NaiveDate& other) const;

    private: // Static data members
        static const int firstYear;
        static const NaiveDate first;
        static const WeekdayType firstWeekDay;
        static const int daysInMonth[];
    public: // Static
        static int DaysInMonth(int y, int m); // pre Valid(y, m);
        static int DaysInYear(int y); // pre Valid(y);
        static int CenturyOf(int y); // pre Valid(y);
        static int DaysInCentury(int c); // pre c >= Century(first.Year());
        static bool LeapYear(int y); // pre Valid(y);
        static bool Valid(int y, int m, int d);
        static bool Valid(int y, int m);
        static bool Valid(int y);
    };


}

#endif //PROGRAMACAOCOMCLASSES_NAIVEDATE_H
