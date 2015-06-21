#include "edge.h"

/// This class creates a representation an edge conneting two vertices
///

/// \brief
/// No argument constructor and left with an empty body
///
Edge::Edge() {

}

/// \brief
/// There was no dynamically created items in this class so there is no need for a destructor method body
///
Edge::~Edge() {}

/// \brief
/// Creates an edge object connecting two vertex as its input paramters as well as specifying the weight of
/// the edge itself
///
/// \param source Vertex* - a pointer to the source vertex of the edge
/// \param destination Vertex* - a pointer to the destination vertex of the edge
/// \param weight double - the weight of the edge
///
Edge::Edge(Vertex* source, Vertex* destination, double weight) {
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

/// \brief
/// Gets the edge's source vertex
///
/// \return Vertex* - returns a pointer to the source vertex
///
Vertex* Edge::getSource() {
    return this->source;
}

/// \brief
/// Gets the edge's destination vertex
///
/// \return Vertex* - returns a pointer to the destination vertex
///
Vertex* Edge::getDestination() {
    return this->destination;
}

/// \brief
/// Gets the edge's weight
///
/// \return double - returns the edge's weight
///
double Edge::getWeight() {
    return this->weight;
}

/// \brief
/// Compares two edges and returns true if the first's weight
///
/// \param firstEdge Edge* - a pointer to the first edge to be compared
/// \param secondEdge Edge* - a pointer to the second edge to be compared
/// \return bool - returns true if the first edge has a larger weight than the second
///
bool Edge::operator()(Edge* firstEdge, Edge* secondEdge) {
    return firstEdge->weight >= secondEdge->weight;
}

/// \brief
/// Returns output containing a string representation of the edge class detailing its source, destination and weight
///
/// \param out ostream& - the output to be displayed to the user
/// \param edge Edge& - the current edge object
///
ostream& operator<<(ostream& out, Edge& edge) {
    out << "Source: " << edge.getSource() << ", Distance: " << edge.getDestination() << ", Weight: " << edge.weight << endl;
    return out;
}
