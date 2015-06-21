#ifndef DISJOINTSET_H
#define DISJOINTSET_H

/// This class is used to see which set an element is in and is called in the minimum spanning cost
/// as a part of Kruskal’s algorithm
///
class DisjointSet
{
    public:

        /// \brief
        /// Creates a disjoint set by initializing two arrays; one for size and one for vertex identifiers
        ///
        /// \param size int - the desired size of the disjoint set
        ///
        DisjointSet(int);

        /// \brief
        /// Deletes the dynamically created arrays containing sizes and vertex identifiers
        ///
        ~DisjointSet();

        /// \brief
        /// Searches through disjoint set to find vertex identifier i
        ///
        /// \param i int - the vertex identifier being searched for
        /// \return int - the identifier of the parent value of i
        ///
        int find(int);

        /// \brief
        /// Joins the sets containing the two vertex identifiers
        ///
        /// \param vertexOne int - the first vertex identifier
        /// \param vertexTwo int - the second vertex identifier
        ///
        void join(int, int);

        /// \brief
        /// Returns true if two identifiers are in the same set or not
        ///
        /// \param vertexOne int - the first vertex identifier
        /// \param vertexOne int - the first vertex identifier
        /// \return bool - true if both identifiers are in the same set
        ///
        bool sameComponent(int, int);

    private:
        int* id;
        int* sizes;

};

#endif // DISJOINTSET_H
