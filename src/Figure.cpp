//
// Created by marco on 19-02-2023.
//

#include "Figure.h"
#include "Point.h"
#include "Line.h"

namespace mar {

    mar::Figure::~Figure() {};

    void Figure::RotateAround(double angle, const Point &p) {
        Translate(-p.getX(), -p.getY());
        Rotate(angle);
        Translate(p.getX(), p.getY());
    }

    void Figure::Mirror(const Line &l) {
        Point p(l.Intersection(l.Perpendicular(Point())));
        Translate(-p.getX(), -p.getY());
        Rotate(-l.Angle());
        Scale(1.0, -1.0);
        Rotate(l.Angle());
        Translate(p.getX(), p.getY());
    }
}