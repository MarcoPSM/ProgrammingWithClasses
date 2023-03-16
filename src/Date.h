//
// Created by marco on 12-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_DATE_H
#define PROGRAMACAOCOMCLASSES_DATE_H

#include <iostream>

namespace mar {
    // Note: all int arguments must be non-negative
    class Date {
    private:
        int count; // number of days since first
        // invariant count >= 0;
    public:
        enum WeekdayType {
            MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
        };

        Date();
        Date(const Date& other);
        Date(int year, int month, int day); // pra Valid(year, month, day);
        Date(int year, int dayNumber); // pre Valid(year) && dayNumber <= DaysInYear(year);
        Date(int year, int week, WeekdayType weekday); // pre Valid(year) && week>=1;
        virtual ~Date();

        virtual void Copy(const Date& other);
        virtual Date& operator = (const Date& other);
        virtual void Set(int year, int month, int day); // pra Valid(year, month, day);
        virtual void Set(int year, int dayNumber); // pre Valid(year) && dayNumber <= DaysInYear(year);
        virtual void Set(int year, int week, WeekdayType weekday); // pre Valid(year) && week>=1;

        virtual int Count() const;
        virtual int Century() const;
        virtual int DayNumber() const;
        virtual int MonthSize() const;
        virtual int YearSize() const;
        virtual int CenturySize() const;

        virtual int Year() const;
        virtual int Month() const;
        virtual int Day() const;
        virtual int WeekNumber() const;
        virtual int WeekYear() const;
        virtual WeekdayType Weekday() const;
        virtual bool Weekend() const;
        virtual bool Workday() const;
        virtual bool Holiday() const;

        virtual const Date& First() const;
        virtual int DaysSince(const Date& other) const;
        virtual int DaysTo(const Date& other) const;
        virtual int Age(const Date& other) const;

        virtual void Forth();
        virtual void Back(); // pre (operator > First());
        virtual void Add(int x);
        virtual void Subtract(int x); // pre DaysSince(First()) >= x;

        virtual bool InLeapYear() const;

        virtual bool operator == (const Date& other) const;
        virtual bool operator != (const Date& other) const;
        virtual bool operator <= (const Date& other) const;
        virtual bool operator < (const Date& other) const;
        virtual bool operator >= (const Date& other) const;
        virtual bool operator > (const Date& other) const;
        virtual const Date& operator ++ (int);
        virtual const Date& operator -- (int); // pre (operator > First());
        virtual Date& operator += (int x);
        virtual Date& operator -= (int x); // pre x <= Count();
        virtual Date operator + (int x) const;
        virtual Date operator - (int x) const; // pre x <= Count();
        virtual int operator - (const Date& other) const;

        virtual void Write(std::ostream& output = std::cout) const;
        virtual void WriteLine(std::ostream& output = std::cout) const;
        virtual void Accept(const std::string& prompt, const std::string& errorMessage);

        friend std::ostream& operator << (std::ostream& output, const Date& d);

        virtual void AddWeek(int x = 1);
        virtual void SubtractWeek(int x = 1); // pre Count() >= 7*x;
        virtual void ReachForward(WeekdayType weekday);
        virtual void ReachBackward(WeekdayType weekday); // pre Count() >= 7;


    private: // Static data members
        static const int firstYear;
        static const int firstCentury;
        static const Date first;
        static const WeekdayType firstWeekday;
        static const int daysInMonth[2][12];
        static const int accumulated[2][12];
        static const int fourYears;
        static const int oneCentury;
        static const int fourCenturies;

    public: // Static
        static int Count(int y, int m, int d); // pre Valid(y, m, d);

        static int DaysInMonth(int y, int m); // pre Valid(y, m);
        static int DaysInYear(int y); // pre Valid(y);
        static int DaysInCentury(int c); // pre c >= Century(first.Year());

        static int FirstDayOfYear(int y);
        static int FirstDayOfMonth(int y, int m);
        static int FirstDayOfCentury(int c);
        static int FirstYearOfCentury(int c);
        static int CenturyOf(int y); // pre Valid(y);

        static bool LeapYear(int y); // pre Valid(y);
        static bool Valid(int y, int m, int d);
        static bool Valid(int y, int m);
        static bool Valid(int y);

    };


} // mar

#endif //PROGRAMACAOCOMCLASSES_DATE_H
