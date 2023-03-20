//
// Created by marco on 17-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_DATEPORTUGUESE_H
#define PROGRAMACAOCOMCLASSES_DATEPORTUGUESE_H

#include "Date.h"
#include <string>

namespace mar {

    class DatePortuguese: public Date{

    public:
        enum FormatType { DEFAULT, STANDARD, STANDARD_FULL, TEXT,
                TEXT_WITH_WEEKDAY, ARMY, NUMERIC};

        DatePortuguese();
        DatePortuguese(const DatePortuguese& other);
        DatePortuguese(int year, int month, int day); // pre Valid(year, month, day);
        DatePortuguese(int year, int dayNumber); // pre Valid(year) && dayNumber <= DaysInYear();
        DatePortuguese(const Date& other);
        virtual ~DatePortuguese();

        virtual const std::string& MonthName() const;
        virtual const std::string& WeekdayName() const;
        virtual bool Holiday() const;
        virtual bool NewYear() const; // pre EnabledHolidays();
        virtual bool Liberty() const; // pre EnabledHolidays();
        virtual bool Workers() const; // pre EnabledHolidays();
        virtual bool Nation() const; // pre EnabledHolidays();
        virtual bool Assumption() const; // pre EnabledHolidays();
        virtual bool Republic() const; // pre EnabledHolidays();
        virtual bool AllSaints() const; // pre EnabledHolidays();
        virtual bool Independence() const; // pre EnabledHolidays();
        virtual bool OurLady() const; // pre EnabledHolidays();
        virtual bool Christmas() const; // pre EnabledHolidays();
        virtual bool Carnival() const; // pre EnabledHolidays();
        virtual bool GoodFriday() const; // pre EnabledHolidays();
        virtual bool Easter() const; // pre EnabledHolidays();
        virtual bool CorpusChristi() const; // pre EnabledHolidays();

        virtual void Write(std::ostream& output = std::cout) const;

    public: // static
        static const std::string& MonthName(int m);
        static const std::string& WeekdayName(WeekdayType wd);
        static void SetFormat(FormatType newFormat);
        static FormatType Format();
        static void SetSeparator(char newSeparator);
        static char Separator();
        static void SetEnableHolidays(bool b = true);
        static bool EnabledHolidays();
        virtual DatePortuguese NewYear(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Liberty(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Workers(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Nation(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Assumption(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Republic(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese AllSaints(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Independence(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese OurLady(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Christmas(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Carnival(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese GoodFriday(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese Easter(int y) const; // pre EnabledHolidays();
        virtual DatePortuguese CorpusChristi(int y) const; // pre EnabledHolidays();

    private: // static data members
        static const std::string monthNames[];
        static const std::string weekdayNames[];
        static FormatType format;
        static char separator;
        static bool enabledHolidays;
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_DATEPORTUGUESE_H
