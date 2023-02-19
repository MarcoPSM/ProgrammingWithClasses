//
// Created by marco on 03-02-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_LINE_H
#define PROGRAMACAOCOMCLASSES_LINE_H

#include "Point.h"

namespace mar {

    class Line : public Figure {
    private:
        double a, b, c;
    public:
        Line();
        Line(const Point& p1, const Point& p2); // pre p1 != p2
        Line(const Point& p, double angle);
        Line(const Line& other);
        Line(double a, double b, double c); // pre a!=0.0 || b!=0.0
        virtual ~Line();

        virtual bool operator== (const Line& other) const;
        virtual bool operator!= (const Line& other) const;

        virtual Line Parallel(const Point& p) const;
        virtual Line Perpendicular(const Point& p) const;
        virtual double DistanceTo(const Point& p) const;

        virtual double Angle() const;
        virtual double X0() const; // pre !Vertica()
        virtual double Y0() const; // pre !horizontal()

        virtual bool Vertical() const;
        virtual bool Horizontal() const;

        virtual bool Has(const Point& p) const;
        virtual bool SameSide(const Point& p1, const Point& p2) const;

        virtual bool IsParallel(const Line& other) const;
        virtual Point Intersection(const Line& other) const; // !IsParallel(other)

        virtual void Translate(double dx, double dy);
        virtual void Scale(double fx, double fy);
        virtual void Rotate(double angle);

        virtual void Write(std::ostream& output) const;
        virtual void WriteLine(std::ostream& output = std::cout) const;

    private: // functions
        virtual double Value(const Point& p) const;

    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_LINE_H
