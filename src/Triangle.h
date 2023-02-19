//
// Created by marco on 03-02-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_TRIANGLE_H
#define PROGRAMACAOCOMCLASSES_TRIANGLE_H

#include "Point.h"
#include "Polygon.h"

namespace mar {

    class Triangle : public Polygon {
    private:
        /*
        Point p0;
        Point p1;
        Point p2;
         */
    public:
        Triangle();
        Triangle(const Point& p0, const Point& p1, const Point& p2);
        Triangle(const Triangle& other);
        virtual ~Triangle();

        virtual double Base() const;
        virtual double Height() const;
        virtual double Area() const;
        //virtual double Perimeter() const;
        virtual bool IsOK() const;
        /*
        virtual bool Contains(const Point& p) const;
        virtual bool Contains(const Triangle& other) const;

        virtual void Translate(double dx, double dy);
        virtual void Scale(double fx, double fy);
        virtual void Rotate(double angle);

        virtual void Write(std::ostream& output) const;
        virtual void WriteLine(std::ostream& output = std::cout) const;
         */
    };

}

#endif //PROGRAMACAOCOMCLASSES_TRIANGLE_H

