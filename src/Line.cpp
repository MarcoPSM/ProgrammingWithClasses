//
// Created by marco on 03-02-2023.
//

#include <cmath>
#include "Line.h"

namespace mar {
    Line::Line() :
            a(0.0), b(1.0), c(0.0) {}

    Line::Line(const Line &other) :
            a(other.a), b(other.b), c(other.c) {}

    Line::Line(const Point &p, double angle):
        a(std::sin(angle)),
        b(- std::cos(angle)),
        c(p.getY() * -b - p.getX() * a) {}

    Line::Line(const Point &p1, const Point &p2):
        a(p2.getY()-p1.getY()),
        b(p1.getX()-p2.getX()),
        c(p2.getX()*p1.getY() - p2.getY()*p1.getX()){}

    Line::Line(double a, double b, double c):
        a(a), b(b), c(c) {}

    Line::~Line() {}

    bool Line::operator==(const Line &other) const {
        return a*other.b == b*other.a &&
            a*other.c == c*other.a &&
            b*other.c == c*other.b;
    }

    bool Line::operator!=(const Line &other) const {
        return !operator==(other);
    }

    Line Line::Parallel(const Point &p) const {
        return Line(a, b, -(a*p.getX() + b*p.getY()));
    }

    Line Line::Perpendicular(const Point &p) const {
        return Line(-b, a, -(-b*p.getX() + a*p.getY()));
    }

    double Line::DistanceTo(const Point &p) const {
        return Intersection(Perpendicular(p)).DistanceTo(p);
    }

    double Line::Value(const Point &p) const {
        // ax + by + c
        return a * p.getX() + b * p.getY() + c;
    }

    bool Line::Has(const Point &p) const {
        // ax + by + c = 0
        return Value(p) == 0.0;
    }

    bool Line::SameSide(const Point &p1, const Point &p2) const {
        return Value(p1) * Value(p2) >= 0;
    }

    double Line::Angle() const {
        return b==0.0 ? 3.1415926535 / 2 : std::atan(-a/b);
    }

    double Line::Y0() const {
        return -c/b;
    }

    double Line::X0() const {
        return -c/a;
    }

    bool Line::Vertical() const {
        return b==0.0;
    }

    bool Line::Horizontal() const {
        return a==0.0;
    }

    bool Line::IsParallel(const Line &other) const {
        return a*other.b == b*other.a;
    }

    Point Line::Intersection(const Line &other) const {
        double x = (b*other.c - c*other.b) / (a*other.b - b*other.a);
        double y = (a*other.c - c*other.a) / (b*other.a - a*other.b);
        return Point(x, y);
    }

    void Line::Translate(double dx, double dy) {
        c -= a*dx + b*dy;
    }

    void Line::Scale(double fx, double fy) {
        a *= fy;
        b *= fx;
        c *= fx*fy;
    }

    void Line::Rotate(double angle) {
        double a0 = a;
        double b0 = b;
        a = a0 * std::cos(angle) - b0 * std::sin(angle);
        b = a0 * std::sin(angle) - b0 * std::cos(angle);
    }

    void Line::Write(std::ostream &output) const {
        output << a << " " << b << " " << c;
    }

    void Line::WriteLine(std::ostream &output) const {
        Write(output);
        output << std::endl;
    }
} // mar