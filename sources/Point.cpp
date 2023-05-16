#include <iostream>
#include <cmath>
#include "Point.hpp"


Point::Point(double xxx, double yyy) : m_x(xxx), m_y(yyy) {}

double Point::distance(const Point& other) const {
        double dx = m_x - other.m_x;
        double dy = m_y - other.m_y;
        return std::sqrt((dx * dx) + (dy * dy));
}

void Point::print() const {
        std::cout << "(" << m_x << ", " << m_y << ")";
}

Point Point::moveTowards(const Point& source, const Point& dest, double distance) 
{
    // Calculate the distance between the source and destination points
    double dx = dest.m_x - source.m_x;
    double dy = dest.m_y - source.m_y;
    double dist = std::sqrt(dx * dx + dy * dy);

    if (dist <= distance) {
        // Destination point is within or equal to the given distance from the source point
        return dest;
    }
    else if (dist == 0) {
        // Source and destination points are the same, return the source point
        return source;
    }
    else {

        // Destination point is farther than the given distance from the source point
        //so we need to move towards it,we will move as given distance.
        double ratio = distance / dist;
        double x = source.m_x + ratio * dx;
        double y = source.m_y + ratio * dy;
        return Point(x, y);
    }
    
}

    

