//
// Created by m1martin on 14-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_COUNT_H
#define PROGRAMACAOCOMCLASSES_COUNT_H

namespace mar {

    class Count {
    private:
        int value;

    public:
        Count(); // post IsZero();
        Count(const Count& other);
        virtual ~Count();

        virtual void Increment();
        virtual void Decrement();
        virtual void Reset(); // post IsZero();
        virtual int Value() const;
        virtual bool IsZero() const;
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_COUNT_H
