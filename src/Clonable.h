//
// Created by marco on 25-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_CLONABLE_H
#define PROGRAMACAOCOMCLASSES_CLONABLE_H

namespace mar{
    class Clonable {
    public:
        virtual Clonable* Clone() const = 0;
        virtual ~Clonable() {};
    };
}
#endif //PROGRAMACAOCOMCLASSES_CLONABLE_H
