//
// Created by marco on 22-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRING_H
#define PROGRAMACAOCOMCLASSES_STRING_H

#include <string>

namespace mar {

class string: public std::string {
    public:
        string(const std::string& x);
        string();
        virtual ~string();

        virtual string applied(void (string::*f)()) const;

        virtual bool ends_by(const std::string& s) const;
        virtual bool starts_by(const std::string& s) const;
        virtual bool is_blank() const;
        virtual void trim_left();
        virtual void trim_right();
        virtual void trim();
        virtual void trim_all();
        virtual void detab(int x);

        virtual void reverse();
        virtual bool is_palindrome() const;

        virtual std::string first() const;
        virtual std::string last() const;

        virtual void prune_all(const std::string& s);
        virtual void replace_all(const std::string& s, const std::string& r);

};

} // mar

#endif //PROGRAMACAOCOMCLASSES_STRING_H
