#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include "vertex.h"
#include "edge.h"

using namespace std;


/// This class creates a graph containing all vertex and the edges connecting them
///
class Graph
{
    public:

        /// \brief
        /// Creates a graph with the number of vertices specified
        ///
        /// \param numVertices unsigned int - the number of vertices within the graph
        ///
        Graph(unsigned int numVertices);

        /// \brief
        /// Deletes the weights in the 2 dimensional array
        ///
        /// \param numVertices unsigned int - the number of vertices within the graph
        ///
        ~Graph();

        /// \brief
        /// Adds a vertex to the vector containing all the vertices of the graph
        ///
        /// \param vertex Vertex* - the vertex to add to the vector
        ///
        void addVertex(Vertex* vertex);

        /// \brief
        /// Returns a pointer to a vertex from the vertices vector with the identifer given as input
        ///
        /// \param identifier int - the identifier of the vertex to be returned
        /// \return Vertex* - a pointer to the vertex with the correct identifier
        ///
        Vertex* getVertex(int identifier);

        /// \brief
        /// Adds an edge connecting two vertices to the graph
        ///
        /// \param edge *Edge - a pointer to the edge object to be added
        ///
        void addEdge(Edge* edge);

        /// \brief
        /// Uses Kruskal’s algorithm to find the minimum spanning tree of the graph
        ///
        /// \return double - the cost of the minimum spanning tree of the graph
        ///
        double minimumSpanningTreeCost();

        /// \brief
        /// Uses Dijkstra's algorithm to find the shortest path between the source vertex
        /// and all other vertices
        ///
        /// \param sourceId unsigned int - the identifier of the source vertex
        ///
        void dijkstra(unsigned int);

        /// \brief
        /// Uses Breadth First Search algorithm to find the shortest path between the source vertex
        /// and all other vertices using only the vertices present in the minimum spanning tree
        ///
        /// \param sourceId unsigned int - the identifier of the source vertex
        ///
        void bfs(unsigned int);

        /// \brief
        /// Returns output containing a string representation of the graph in a dimensional array of weights
        ///
        /// \param out ostream& - the output to be displayed to the user
        /// \param vertex Vertex& - the current graph object
        ///
        friend ostream& operator<<(ostream&, Graph&);

    private:
        unsigned int numVertices;
        double** weights;
        priority_queue<Edge*, vector<Edge*>, Edge> edges;
        vector<Vertex*> vertices;

        /// \brief
        /// Generates string output for the user to be used when displaying paths found using
        /// Dijkstra's and Breadth First Search algorithims
        ///
        /// \param sourceId unsigned int - the indentifier of the source vertex
        ///
        void outputPaths(unsigned int sourceId);
};
#endif // GRAPH_H
