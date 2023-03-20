//
// Created by marco on 17-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_DATESPECIAL_H
#define PROGRAMACAOCOMCLASSES_DATESPECIAL_H

#include "DatePortuguese.h"

namespace mar {

    class DateSpecial: public DatePortuguese {
    private:
    public:
        DateSpecial();
        DateSpecial(const DateSpecial& other);
        DateSpecial(int year, int month, int day); // Valid(year, month, day);
        virtual ~DateSpecial();

        virtual bool Friday13() const;
        virtual void ReachFirstMillenaryAfter(const DatePortuguese& other); // pre operator <= (other);

        virtual void AdvanceToWorkingDay();
        virtual void AdvanceToWorkingDay(int x);
        virtual void ReturnToWork(int x);
        virtual bool Bridge() const;

        virtual void WriteBridges(std::ostream& output, int n) const;
        virtual int DaysAway(int n) const;


        virtual void WriteCalendarDay(std::ostream& output) const;
        virtual void WriteCalendarMonth(std::ostream& output) const;

    public: // static
        static DateSpecial DepartForVacations(int y, int n);
        static void SplitStream(std::istream& input, std::ostream& output, int size); // pre size > 0;
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_DATESPECIAL_H
