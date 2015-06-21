#ifndef POINT_H
#define POINT_H
#include <ostream>

using namespace std;

/// This class creates a representation of a 2D point on a Cartesian plane with x and y coordinates
///
class Point
{
    public:

        /// \brief
        /// Creates a point and sets x and y coordinates
        ///
        /// \param xCoord double - value of x coordinate
        /// \param yCoord double - value of y coordinate
        ///
        Point(double, double);

        /// \brief
        /// There was no dynamically created items in this class so there is no need for a destructor method body
        ///
        ~Point();

        /// \brief
        /// Determines and returns the distance between two points
        ///
        /// \param nextPoint Point* - the other point to be used to calculate the distance between the two
        /// \return double - the distance between the two points
        ///
        double distanceTo(Point*);

        /// \brief
        /// Returns output containing a string representation of the point class detailing its coordinates
        ///
        /// \param out ostream& - the output to be displayed to the user
        /// \param point Point& - the current point object
        ///
        friend ostream& operator<<(ostream&, Point&);
    private:
        double xCoord;
        double yCoord;
};

#endif // POINT_H
