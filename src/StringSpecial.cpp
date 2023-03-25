//
// Created by marco on 25-03-2023.
//

#include "StringSpecial.h"

void mar::StringSpecial::EraseMiddleNames() {
    Erase(Position(" ") + 1, LastPosition(" "));
}
