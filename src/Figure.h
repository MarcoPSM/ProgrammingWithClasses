//
// Created by marco on 19-02-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_FIGURE_H
#define PROGRAMACAOCOMCLASSES_FIGURE_H

#include <iostream>

namespace mar {

    class Point;
    class Line;

    class Figure {
    public:
        virtual ~Figure();

        virtual void Scale(double dx, double dy) = 0;
        virtual void Translate(double dx, double dy) = 0;
        virtual void Rotate(double angle) = 0;
        virtual void Write(std::ostream& output) const = 0;
        virtual void WriteLine(std::ostream& output) const = 0;

        virtual void RotateAround(double angle, const Point &p);
        virtual void Mirror(const Line &l);
    };

}

#endif //PROGRAMACAOCOMCLASSES_FIGURE_H
