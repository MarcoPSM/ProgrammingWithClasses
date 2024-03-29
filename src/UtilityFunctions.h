//
// Created by marco on 12-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_UTILITYFUNCTIONS_H
#define PROGRAMACAOCOMCLASSES_UTILITYFUNCTIONS_H

#include <iostream>

namespace mar {
    // as funcoes genericas devem ser definidas logo no .h
    template <class T>
    T Min(const T& x, const T& y) {
        return x <= y ? x : y;
    }
    template <class T>
    T Max(const T& x, const T& y) {
        return x <= y ? y : x;
    }; //    int Max(int x, int y);
    template <class T>
    T Min(const T& x, const T& y, const T& z) {
        return Min(Min(x, y), z);
    }
    template <class T>
    T Max(const T& x, const T& y, const T& z) {
        return Max(Max(x, y), z);
    }

    template <class T>
    void Sort(T& x, T& y) {
        if (!(x<y)) {
            std::swap(x, y);
        }
    }
    template <class T>
    void Sort(T& x, T& y, T& z) {
        Sort(y, z);
        Sort(x, y);
        Sort(y, z);
    }
    template <class T>
    bool Sorted(T& x, T& y, T& z) {
        return x<=y && y<=z;
    }

    template <class T>
    T Square(const T &x) {
        return x* x;
    }

    void SkipLine(std::istream& input = std::cin, char delimiter = '\n');

    int CountDigits(int x, int base=10);
}
#endif //PROGRAMACAOCOMCLASSES_UTILITYFUNCTIONS_H
