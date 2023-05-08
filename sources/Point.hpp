#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>

class Point {
public:
    Point(double x, double y);
    double distance(const Point& other) const;
    void print() const;
    Point moveTowards(const Point& source, const Point& dest, double distance) const;

    double getX() const { return m_x; }
    double getY() const { return m_y; }
private:
    double m_x;
    double m_y;
};

#endif // POINT_HPP