//
// Created by m1martin on 28-04-2024
//

#include "Clonable.h"

namespace mar {

template <class T> class Predicate : public Clonable {
public:
    virtual Clonable *Clone() const { return new Predicate<T>(*this); }
    virtual bool      Good(const T &) const { return true; }
    virtual bool      Bad(const T &x) const { return !Good(x); }
    virtual bool      operator()(const T &x) const { return Good(x); }
};

} // namespace mar