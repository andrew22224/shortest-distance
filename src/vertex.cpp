#include "vertex.h"

/// This class creates a vertex represnting a city on a graph and encapsulates information used in
/// various shortest path algorithims
///

/// \brief
/// No argument constructor and left with an empty body
///
Vertex::Vertex() {}

/// \brief
/// There was no dynamically created items in this class so there is no need for a destructor method body
///
Vertex::~Vertex() {}

/// \brief
/// Creates a vertex with a unique identifier
///
/// \param identifier unsigned int - an identifier unique to the vertex
///
Vertex::Vertex(unsigned int identifier) {
    this->identifier = identifier;
}

/// \brief
/// Returns the unique identifier of the vertex
///
/// \return unsigned int - an identifier unique to the vertex
///
unsigned int Vertex::getId() {
    return this->identifier;
}

/// \brief
/// Adds a vertex as being adjacent to the current vertex
///
/// \param identifier unsigned int - the identifier of the adjacent vertex
///
void Vertex::addAdjacency(unsigned int identifier) {
    this->adjacencies.insert(identifier);
}

/// \brief
/// Returns all vertices adjacent to the current vertex
///
/// \return set<unsigned int>* - a pointer to a set of adjacent vertices to the current vertex
///
set<unsigned int>* Vertex::getAdjacencies() {
    return &this->adjacencies;
}

/// \brief
/// Sets whether or not the vertex has been discovered
///
/// \param discovered bool - is true if the vertex has been discovered and false if not
///
void Vertex::setDiscovered(bool discovered) {
    this->discovered = discovered;
}

/// \brief
/// Returns whether or not the vertex is discovered
///
/// \return bool - a value representing whether the vertex is discovered
///
bool Vertex::isDiscovered() {
    return this->discovered;
}

/// \brief
/// Sets a vertex identifier as the predecessor of the current vertex
///
/// \param predecessorId unsigned int - the identifier of the predecessor vertex
///
void Vertex::setPredecessorId(unsigned int predecessorId) {
    this->predecessorId = predecessorId;
}

/// \brief
/// Returns the predecessor identifier of the current vertex
///
/// \return unsigned int - the identifier of the predecessor vertex
///
unsigned int Vertex::getPredecessorId() {
    return this->predecessorId;
}

/// \brief
/// Sets the minimum distance from the source to the current vertex
///
/// \param minDistance double - the value of the minimum distance
///
void Vertex::setMinDistance(double minDistance) {
    this->minDistance = minDistance;
}

/// \brief
/// Returns the minimum distance from the source to the current vertex
///
/// \return double - the value of the minimum distance
///
double Vertex::getMinDistance() {
    return this->minDistance;
}

/// \brief
/// Compares two vertices and returns true if the first's minimum distance is greater than
/// the second
///
/// \param firstVertex Vertex* - a pointer to the first vertex to be compared
/// \param secondVertex Vertex* - a pointer to the second vertex to be compared
/// \return bool - returns true if the first vertex has a larger minimum distance than the second
///
bool Vertex::operator()(Vertex* firstVertex, Vertex* secondVertex) {
    return firstVertex->getMinDistance() >= secondVertex->getMinDistance();
}

/// \brief
/// Returns output containing a string representation of the vertex class detailing its identifier
///
/// \param out ostream& - the output to be displayed to the user
/// \param vertex Vertex& - the current vertex object
///
ostream& operator<<(ostream& out, Vertex& vertex) {
    out << "Identifier " << vertex.getId();
    return out;
}
