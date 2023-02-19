//
// Created by marco on 13-02-2023.
//

#include "Polygon.h"
#include "Triangle.h"
#include "Line.h"

namespace mar {
    Polygon::Polygon():
        count(3),
        vertices(3) {}
    Polygon::Polygon(int count):
        count(count),
        vertices(count) {
        Point p(1.0, 0.0);
        for (int i = 0; i < count; ++i) {
            (vertices[i] = p).Rotate(i * 2 * 3.1415926535 / count);
        }
    }
    Polygon::Polygon(int count, const Point *points):
        count(count),
        vertices() {
        vertices.reserve(count);
        for (int i = 0; i < count; ++i) {
            vertices.push_back(points[i]);
        }
    }

    Polygon::Polygon(int count, const double *x, const double *y):
        count(count),
        vertices() {
        vertices.reserve(count);
        for (int i = 0; i < count; ++i) {
            vertices.push_back(Point(x[i], y[i]));
        }
    }
    Polygon::Polygon(const Polygon &other):
        count(other.count),
        vertices(other.vertices) {}

    Polygon::~Polygon() {}

    int Polygon::Count() const {
        return count;
    }

    const Point &Polygon::Vertex(int x) const {
        return vertices[x];
    }

    const Point &Polygon::operator[](int x) const {
        return vertices[x];
    }

    void Polygon::Set(const Point &p, int x) {
        vertices[x] = p;
    }

    double Polygon::Perimeter() const {
        double result = 0.0;
        for (int i = 0; i < count; ++i) {
            result += vertices[i].DistanceTo(vertices[(i+1)%count]);
        }
        return result;
    }

    double Polygon::Area() const {
        double result = 0.0;
        for (int i = 2; i < count; ++i) {
            result += Triangle(vertices[0], vertices[i-1], vertices[i]).Area();
        }
        return result;
    }

    bool Polygon::Contains(const Point &p) const {
        for (int i = 0; i < count; ++i) {
            if (!Line(vertices[i], vertices[(i+1)%count]).SameSide(vertices[(i+2)%count], p)) {
                return false;
            }
        }
        return true;
    }

    bool Polygon::Contains(const Polygon &other) const {
        for (int i = 0; i < count; ++i) {
            if (!Contains(other.vertices[i])) {
                return false;
            }
        }
        return true;
    }

    bool Polygon::IsConvex() const {
        for (int i = 0; i < count; ++i) {
            if (vertices[i] == vertices[(i+1)%count]) {
                return false;
            }
            Line side(vertices[i], vertices[(i+1)%count]);
            if (side.Has(vertices[(i+2)%count])) {
                return false;
            }
            for (int j = 0; j < count; ++j) {
                if (!side.SameSide(vertices[(i+2)%count], vertices[(i+j)%count])) {
                    return false;
                }
            }
        }
        return true;
    }

    void Polygon::Scale(double fx, double fy) {
        for (int i = 0; i < count; ++i) {
            vertices[i].Scale(fx, fy);
        }
    }

    void Polygon::Translate(double dx, double dy) {
        for (int i = 0; i < count; ++i) {
            vertices[i].Translate(dx, dy);
        }
    }

    void Polygon::Rotate(double angle) {
        for (int i = 0; i < count; ++i) {
            vertices[i].Rotate(angle);
        }
    }

    void Polygon::Write(std::ostream &output) const {
        output << count;
        for (int i = 0; i < count; ++i) {
            output << " ";
            vertices[i].Write(output);
        }
    }

    void Polygon::WriteLine(std::ostream &output) const {
        Write(output);
        output << std::endl;
    }
}