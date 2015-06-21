#include <cmath>
#include "point.h"

/// This class creates a representation of a 2D point on a Cartesian plane with x and y coordinates
///

/// \brief
/// Creates a point and sets x and y coordinates
///
/// \param xCoord double - value of x coordinate
/// \param yCoord double - value of y coordinate
///
Point::Point(double xCoord, double yCoord) {
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

/// \brief
/// There was no dynamically created items in this class so there is no need for a destructor method body
///
Point::~Point() {}

/// \brief
/// Determines and returns the distance between two points
///
/// \param nextPoint Point* - the other point to be used to calculate the distance between the two
/// \return double - the distance between the two points
///
double Point::distanceTo(Point* nextPoint) {
    return sqrt(pow(this->xCoord - nextPoint->xCoord, 2) + pow(this->yCoord - nextPoint->yCoord, 2));
}

/// \brief
/// Returns output containing a string representation of the point class detailing its coordinates
///
/// \param out ostream& - the output to be displayed to the user
/// \param point Point& - the current point object
///
ostream& operator<<(ostream& out, Point& point) {
    out << point.xCoord << " " << point.yCoord;
    return out;
}
