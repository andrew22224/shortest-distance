#ifndef EDGE_H
#define EDGE_H
#include <ostream>
#include "vertex.h"

using namespace std;

/// This class creates a representation an edge conneting two vertices
///
class Edge
{
    public:

        /// \brief
        /// No argument constructor and left with an empty body
        ///
        Edge();

        /// \brief
        /// There was no dynamically created items in this class so there is no need for a destructor method body
        ///
        ~Edge();

        /// \brief
        /// Creates an edge object connecting two vertex as its input paramters as well as specifying the weight of
        /// the edge itself
        ///
        /// \param source Vertex* - a pointer to the source vertex of the edge
        /// \param destination Vertex* - a pointer to the destination vertex of the edge
        /// \param weight double - the weight of the edge
        ///
        Edge(Vertex*, Vertex*, double);

        /// \brief
        /// Gets the edge's source vertex
        ///
        /// \return Vertex* - returns a pointer to the source vertex
        ///
        Vertex* getSource();

        /// \brief
        /// Gets the edge's destination vertex
        ///
        /// \return Vertex* - returns a pointer to the destination vertex
        ///
        Vertex* getDestination();

        /// \brief
        /// Gets the edge's weight
        ///
        /// \return double - returns the edge's weight
        ///
        double getWeight();

        /// \brief
        /// Compares two edges and returns true if the first's weight
        ///
        /// \param firstEdge Edge* - a pointer to the first edge to be compared
        /// \param secondEdge Edge* - a pointer to the second edge to be compared
        /// \return bool - returns true if the first edge has a larger weight than the second
        ///
        bool operator()(Edge*, Edge*);

        /// \brief
        /// Returns output containing a string representation of the edge class detailing its source, destination and weight
        ///
        /// \param out ostream& - the output to be displayed to the user
        /// \param edge Edge& - the current edge object
        ///
        friend ostream& operator<<(ostream&, Edge&);

    private:
        Vertex* source;
        Vertex* destination;
        double weight;
};

#endif // EDGE_H
