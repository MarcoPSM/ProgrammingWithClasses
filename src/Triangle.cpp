//
// Created by marco on 03-02-2023.
//

#include <cmath>
#include "Triangle.h"
#include "Line.h"


namespace mar {

    Triangle::Triangle() :
        Polygon(3) {
        Set(Point(0.0,0.0), 0);
        Set(Point(1.0,0.0), 1);
        Set(Point(0.0,1.0), 2);
    }

    Triangle::Triangle(const Point &p0, const Point &p1, const Point &p2) :
            Polygon(3) {
        Set(p0, 0);
        Set(p1, 1);
        Set(p2, 2);
    }

    Triangle::Triangle(const Triangle &other) :
            Polygon(other) {}

    Triangle::~Triangle() {}

    double Triangle::Base() const {
        return Vertex(0).DistanceTo(Vertex(1));
    }

    double Triangle::Height() const {
        const Point &p0 = Vertex(0);
        const Point &p1 = Vertex(1);
        const Point &p2 = Vertex(2);
        return p0 == p1 ? p0.DistanceTo(p2) : Line(p0, p1).DistanceTo(p2);
    }
/*
    double Triangle::Perimeter() const {
        return p0.DistanceTo(p1) +
               p1.DistanceTo(p2) +
               p2.DistanceTo(p0);
    }
*/
    double Triangle::Area() const {
        return Base() * Height() / 2;
    }

    bool Triangle::IsOK() const {
        return IsConvex();
    }
/*
    void Triangle::Scale(double fx, double fy) {
        p0.Scale(fx, fy);
        p1.Scale(fx, fy);
        p2.Scale(fx, fy);
    }

    void Triangle::Translate(double dx, double dy) {
        p0.Translate(dx, dy);
        p1.Translate(dx, dy);
        p2.Translate(dx, dy);
    }

    void Triangle::Rotate(double angle) {
        p0.Rotate(angle);
        p1.Rotate(angle);
        p2.Rotate(angle);
    }

    void Triangle::Write(std::ostream &output) const {
        p0.Write(output);
        output << " ";
        p1.Write(output);
        output << " ";
        p2.Write(output);
    }

    void Triangle::WriteLine(std::ostream &output) const {
        Write(output);
        output << std::endl;
    }

    bool Triangle::Contains(const Point &p) const {
        // not defined yet
        return Line(p0,p1).SameSide(p,p2) &&
                Line(p1, p2).SameSide(p,p0) &&
                Line(p2,p0).SameSide(p,p1);
    }

    bool Triangle::Contains(const Triangle &other) const {
        return Contains(other.p0) && Contains(other.p1) && Contains(other.p2);
    }
*/
}