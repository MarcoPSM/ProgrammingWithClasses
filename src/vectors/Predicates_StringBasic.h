//
// Created by m1martin on 28-04-2024
//

#include "Predicate.h"
#include "StringBasic.h"

namespace mar {

// EndingBy predicate
class EndingBy : public Predicate<StringBasic> {
private:
    StringBasic s;

public:
    EndingBy(const StringBasic &s);
    virtual bool      Good(const StringBasic &x) const;
    virtual Clonable *Clone() const;
};

// StartingBy predicate
class StartingBy : public Predicate<StringBasic> {
private:
    StringBasic s;

public:
    StartingBy(const StringBasic &s);
    virtual bool      Good(const StringBasic &x) const;
    virtual Clonable *Clone() const;
};

// HavingAllFrom predicate
class HavingAllFrom : public Predicate<StringBasic> {
private:
    StringBasic s;

public:
    HavingAllFrom(const StringBasic &s);
    virtual bool      Good(const StringBasic &x) const;
    virtual Clonable *Clone() const;
};

// NotHavingAnyFrom predicate
class NotHavingAnyFrom : public Predicate<StringBasic> {
private:
    StringBasic s;

public:
    NotHavingAnyFrom(const StringBasic &s);
    virtual bool      Good(const StringBasic &x) const;
    virtual Clonable *Clone() const;
};

// Palindromic
class Palindromic : public Predicate<StringBasic> {
public:
    virtual bool      Good(const StringBasic &x) const;
    virtual Clonable *Clone() const;
};

// RepeatingChar
class RepeatingChar : public Predicate<StringBasic> {
private:
    int n;

public:
    RepeatingChar(int n);
    virtual bool      Good(const StringBasic &x) const;
    virtual Clonable *Clone() const;
};

} // namespace mar