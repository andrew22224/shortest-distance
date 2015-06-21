#ifndef VERTEX_H
#define VERTEX_H
#include <set>
#include <ostream>

using namespace std;

/// This class creates a vertex represnting a city on a graph and encapsulates information used in
/// various shortest path algorithims
///
class Vertex
{
    public:

        /// \brief
        /// No argument constructor and left with an empty body
        ///
        Vertex();

        /// \brief
        /// There was no dynamically created items in this class so there is no need for a destructor method body
        ///
        ~Vertex();

        /// \brief
        /// Creates a vertex with a unique identifier
        ///
        /// \param identifier unsigned int - an identifier unique to the vertex
        ///
        Vertex(unsigned int identifier);

        /// \brief
        /// Returns the unique identifier of the vertex
        ///
        /// \return unsigned int - an identifier unique to the vertex
        ///
        unsigned int getId();

        /// \brief
        /// Adds a vertex as being adjacent to the current vertex
        ///
        /// \param identifier unsigned int - the identifier of the adjacent vertex
        ///
        void addAdjacency(unsigned int identifier);

        /// \brief
        /// Returns all vertices adjacent to the current vertex
        ///
        /// \return set<unsigned int>* - a pointer to a set of adjacent vertices to the current vertex
        ///
        set<unsigned int>* getAdjacencies();

        /// \brief
        /// Sets whether or not the vertex has been discovered
        ///
        /// \param discovered bool - is true if the vertex has been discovered and false if not
        ///
        void setDiscovered(bool discovered);

        /// \brief
        /// Returns whether or not the vertex is discovered
        ///
        /// \return bool - a value representing whether the vertex is discovered
        ///
        bool isDiscovered();

        /// \brief
        /// Sets a vertex identifier as the predecessor of the current vertex
        ///
        /// \param predecessorId unsigned int - the identifier of the predecessor vertex
        ///
        void setPredecessorId(unsigned int predecessorId);

        /// \brief
        /// Returns the predecessor identifier of the current vertex
        ///
        /// \return unsigned int - the identifier of the predecessor vertex
        ///
        unsigned int getPredecessorId();

        /// \brief
        /// Sets the minimum distance from the source to the current vertex
        ///
        /// \param minDistance double - the value of the minimum distance
        ///
        void setMinDistance(double minDistance);

        /// \brief
        /// Returns the minimum distance from the source to the current vertex
        ///
        /// \return double - the value of the minimum distance
        ///
        double getMinDistance();

        /// \brief
        /// Compares two vertices and returns true if the first's minimum distance is greater than
        /// the second
        ///
        /// \param firstVertex Vertex* - a pointer to the first vertex to be compared
        /// \param secondVertex Vertex* - a pointer to the second vertex to be compared
        /// \return bool - returns true if the first vertex has a larger minimum distance than the second
        ///
        bool operator()(Vertex*, Vertex*);

        /// \brief
        /// Returns output containing a string representation of the vertex class detailing its identifier
        ///
        /// \param out ostream& - the output to be displayed to the user
        /// \param vertex Vertex& - the current vertex object
        ///
        friend ostream& operator<<(ostream&, Vertex&);



    private:
        unsigned int identifier;
        set<unsigned int> adjacencies;
        bool discovered;
        unsigned int predecessorId;
        double minDistance;
};

#endif // VERTEX_H
