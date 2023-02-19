//
// Created by marco on 02-02-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_POINT_H
#define PROGRAMACAOCOMCLASSES_POINT_H

#include <iostream>
#include "Figure.h"

namespace mar {

class Point : public Figure {
private:
    double x;
    double y;
public:
    Point();
    Point(const Point& other);
    Point(double x, double y);
    virtual ~Point();

    virtual bool Equal(const Point& other) const;
    virtual bool operator == (const Point& other) const;
    virtual bool operator != (const Point& other) const;

    virtual void Translate(double dx, double dy);
    virtual void Scale(double fx, double fy);
    virtual void Rotate(double angle);
    // O argumento é passado por referencia constante
    // ou seja a função tem acesso à variavel atraves do endereço
    // mas não modifica o argumento
    // o const no final significa que nao modifica este objeto
    virtual double DistanceTo(const Point& other) const;

    virtual void Write(std::ostream& output) const;
    virtual void WriteLine(std::ostream& output = std::cout) const;
    virtual void Read(std::istream& input = std::cin);

    virtual double getX() const;
    virtual double getY() const;
    virtual void setX(double x);
    virtual void setY(double y);
    virtual void set(double x, double y);

    virtual double Angle() const;
    virtual double Modulus() const;
};

}

#endif //PROGRAMACAOCOMCLASSES_POINT_H
