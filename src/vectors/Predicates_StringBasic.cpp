//
// Created by m1martin on 28-04-2024
//

#include "Predicates_StringBasic.h"
#include "StringSpecial.h"

namespace mar {

// EndingBy predicate
EndingBy::EndingBy(const StringBasic &s) : s(s) {}
bool EndingBy::Good(const StringBasic &x) const {
    return x.EndsBy(s);
}
Clonable *EndingBy::Clone() const {
    return new EndingBy(*this);
}

// StartingBy predicate
StartingBy::StartingBy(const StringBasic &s) : s(s) {}
bool StartingBy::Good(const StringBasic &x) const {
    return x.StartsBy(s);
}
Clonable *StartingBy::Clone() const {
    return new StartingBy(*this);
}

// HavingAllFrom predicate
HavingAllFrom::HavingAllFrom(const StringBasic &s)
    : s(s.Applied(&StringBasic::Sort)) {}
bool HavingAllFrom::Good(const StringBasic &x) const {
    return x.Applied(&StringBasic::Sort).Contains(s);
}
Clonable *HavingAllFrom::Clone() const {
    return new HavingAllFrom(*this);
}

// NotHavingAnyFrom predicate
NotHavingAnyFrom::NotHavingAnyFrom(const StringBasic &s) : s(s) {}
bool NotHavingAnyFrom::Good(const StringBasic &x) const {
    return x.PositionIf(s) == -1;
}
Clonable *NotHavingAnyFrom::Clone() const {
    return new NotHavingAnyFrom(*this);
}

// Palindromic
bool Palindromic::Good(const StringBasic &x) const {
    return x == x.Applied(&StringBasic::Reverse);
}

Clonable *Palindromic::Clone() const {
    return new Palindromic(*this);
}

// RepeatingChar
bool RepeatingChar::Good(const StringBasic &x) const {
    // return StringSpecial(x.Applied(&StringBasic::Sort)).MaxRun() >= n;
    return true;
}

Clonable *RepeatingChar::Clone() const {
    return new RepeatingChar(*this);
}

} // namespace mar
