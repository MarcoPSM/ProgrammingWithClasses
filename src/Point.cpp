//
// Created by marco on 02-02-2023.
//

#include "Point.h"
#include <cmath>

namespace mar {

    Point::Point() :
            x(0), y(0) {}

    Point::Point(const Point &other) :
            x(other.x), y(other.y) {}

    Point::Point(double x, double y) :
            x(x), y(y) {}

    Point::~Point() {}

    bool Point::Equal(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool Point::operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool Point::operator!=(const Point &other) const {
        return !operator==(other);
    }

    void Point::Translate(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void Point::Scale(double fx, double fy) {
        x *= fx;
        y *= fy;
    }

    void Point::Rotate(double angle) {
        double x0 = x;
        double y0 = y;
        x = x0 * std::cos(angle) - y0 * std::sin(angle);
        y = x0 * std::sin(angle) - y0 * std::cos(angle);
    }

    double Point::DistanceTo(const Point &other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    void Point::Write(std::ostream &output) const {
        output << x << " " << y;
    }

    void Point::WriteLine(std::ostream &output) const {
        Write(output);
        output << std::endl;
    }

    void Point::Read(std::istream &input) {
        input >> x >> y;
    }

    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

    void Point::setX(double x) {
        this->x = x;
    }

    void Point::setY(double y) {
        this->y = y;
    }

    void Point::set(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double Point::Angle() const {
        return std::atan2(y, x);
    }

    double Point::Modulus() const {
        return std::sqrt(x * x + y * y);
    }

}