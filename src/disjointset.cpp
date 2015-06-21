#include "disjointset.h"

/// This class is used to see which set an element is in and is called in the minimum spanning cost
/// as a part of Kruskal’s algorithm
///

/// \brief
/// Creates a disjoint set by initializing two arrays; one for size and one for vertex identifiers
///
/// \param size int - the desired size of the disjoint set
///
DisjointSet::DisjointSet(int size)
{
    // Create arrays to hold sizes and identifiers of vertex
    this->id = new int[size];
    this->sizes = new int[size];

    // Traverse the id array and set item values to i and all sizes to 1
    for (int i = 0; i < size; i++) {
        id[i] = i;
        this->sizes[i] = 1;
    }
}

/// \brief
/// Deletes the dynamically created arrays containing sizes and vertex identifiers
///
DisjointSet::~DisjointSet() {

    // Deletes the two arrays
    delete this->id;
    delete this->sizes;
}


/// \brief
/// Searches through disjoint set to find vertex identifier i
///
/// \param i int - the vertex identifier being searched for
/// \return int - the identifier of the parent value of i
///
int DisjointSet::find(int i) {

    // Checks that i is not equal to its parent vertex
    while (i != id[i]) {

        // Sets the parent vertex to the grandparent vertex's value
        id[i] = id[id[i]];

        // Sets the vertex to its parent vertex value
        i = id[i];
    }
    return i;
}

/// \brief
/// Joins the sets containing the two vertex identifiers
///
/// \param vertexOne int - the first vertex identifier
/// \param vertexTwo int - the second vertex identifier
///
void DisjointSet::join(int vertexOne, int vertexTwo) {

    int i = find(vertexOne);
    int j = find(vertexTwo);

    // Break out of method if the two vertex identifiers are the same
    if (i == j) {
        return;
    }

    // Sets the parent of the vertex with a smaller size value to the other vertex
    if (sizes[i] < sizes[j]) {
        id[i] = j;

        // Increase larger size vertex by the size of the smaller vertex
        sizes[j] += sizes[i];
    }
    else {
        id[j] = i;
        sizes[i] += sizes[j];
    }
}

/// \brief
/// Returns true if two identifiers are in the same set or not
///
/// \param vertexOne int - the first vertex identifier
/// \param vertexOne int - the first vertex identifier
/// \return bool - true if both identifiers are in the same set
///
bool DisjointSet::sameComponent(int vertexOne, int vertexTwo) {
    return find(vertexOne) == find(vertexTwo);
}
