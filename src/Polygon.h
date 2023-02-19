//
// Created by marco on 13-02-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_POLYGON_H
#define PROGRAMACAOCOMCLASSES_POLYGON_H

#include "Point.h"
#include <vector>

namespace mar {
    class Polygon : public Figure{
    private:
        int count; // invariant count >= 3;
        std::vector<Point> vertices;
    public:
        Polygon();
        explicit Polygon(int count);
        Polygon(int count, const Point points[]);
        Polygon(int count, const double x[], const double y[]);
        Polygon(const Polygon& other);
        virtual ~Polygon();

        virtual int Count() const;
        virtual const Point& Vertex(int x) const; // pre 0<= x && x < Count();
        virtual const Point& operator[](int x) const; // pre 0<= x && x < Count();
        virtual void Set(const Point& p, int x); // pre 0<= x && x < Count();

        virtual bool IsConvex() const;
        virtual double Area() const; //pre IsConvex
        virtual double Perimeter() const;

        virtual bool Contains(const Point& p) const;
        virtual bool Contains(const Polygon& other) const;

        virtual void Scale(double fx, double fy);
        virtual void Rotate(double angle);
        virtual void Translate(double dx, double dy);

        virtual void Write(std::ostream& output) const;
        virtual void WriteLine(std::ostream& output) const;
    };

}

#endif //PROGRAMACAOCOMCLASSES_POLYGON_H
