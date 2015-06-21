#include "graph.h"
#include "disjointset.h"
#include <iomanip>

/// This class creates a graph containing all vertex and the edges connecting them
///

const double INFINITY = 1000.0;

/// \brief
/// Creates a graph with the number of vertices specified
///
/// \param numVertices unsigned int - the number of vertices within the graph
///
Graph::Graph(unsigned int numVertices) {
    this->numVertices = numVertices;

    // Initializes the size of the second dimension of the array to the number of vertices
    weights = new double*[numVertices];

    // Initializes the size of the first dimension of the array to the number of vertices
    for (unsigned int x = 0; x < numVertices; x++) {
        weights[x] = new double[numVertices];

        for (unsigned int y = 0; y < numVertices; y++) {
            // Set the diagonal weights of the array to 0
            if (x == y) {
                weights[x][y] = 0;
            }
            // Set all other weights to INFINITY value until changed later
            else {
                weights[x][y] = INFINITY;
            }
        }
    }
}

/// \brief
/// Deletes the weights in the 2 dimensional array
///
/// \param numVertices unsigned int - the number of vertices within the graph
///
Graph::~Graph() {

    // Deletes two dimensional array
    for (unsigned int x = 0; x < numVertices; x++) {
        delete weights[x];
    }

    delete weights;
}

/// \brief
/// Adds a vertex to the vector containing all the vertices of the graph
///
/// \param vertex Vertex* - the vertex to add to the vector
///
void Graph::addVertex(Vertex* vertex) {

    // Checks if the graph doesn't already contain all vertices
    if (this->vertices.size() < numVertices) {

        // Add vertex to the vector
        this->vertices.push_back(vertex);
    }
}

/// \brief
/// Returns a pointer to a vertex from the vertices vector with the identifer given as input
///
/// \param identifier int - the identifier of the vertex to be returned
/// \return Vertex* - a pointer to the vertex with the correct identifier
///
Vertex* Graph::getVertex(int identifier) {

    // Checks if not trying to access a vertex that doesn't exist
    if ((unsigned int) identifier < this->vertices.size()) {
        return this->vertices[identifier];
    }
    else {
        return NULL;
    }
}

/// \brief
/// Adds an edge connecting two vertices to the graph
///
/// \param edge *Edge - a pointer to the edge object to be added
///
void Graph::addEdge(Edge* edge) {

    // Add edge to priority queue
    this->edges.push(edge);
    unsigned int sourceId = edge->getSource()->getId();
    unsigned int destinationId = edge->getDestination()->getId();

    // Sets weight in both x,y and y,x coordinate positions for edge
    this->weights[sourceId][destinationId] = edge->getWeight();
    this->weights[destinationId][sourceId] = edge->getWeight();
}

/// \brief
/// Uses Kruskal’s algorithm to find the minimum spanning tree of the graph
///
/// \return double - the cost of the minimum spanning tree of the graph
///
double Graph::minimumSpanningTreeCost() {

    // Minimum cost to be accumulated througout method
    double minimumCost = 0;

    // DisjointSet object constructed
    DisjointSet* dSet = new DisjointSet(this->vertices.size());

    unsigned int edgeCount = 0;
    Edge* currentEdge;
    Vertex* currentEdgeSource;
    Vertex* currentEdgeDestination;

    // Iterate through all edges and checks if the vertices are not in the same set, joins them
    while (edges.size() > 0 && edgeCount < this->vertices.size() - 1) {

        // Creates method variables for the edge and it's source and destination vertices
        currentEdge = this->edges.top();
        currentEdgeSource = currentEdge->getSource();
        currentEdgeDestination = currentEdge->getDestination();

        edges.pop();

        // Checks if the vertices are not already in the same set
        if (!dSet->sameComponent(currentEdgeSource->getId(), currentEdgeDestination->getId())) {
            edgeCount++;

            // Joins the vertices to the same set
            dSet->join(currentEdgeSource->getId(), currentEdgeDestination->getId());

            currentEdgeDestination->addAdjacency(currentEdgeSource->getId());
            currentEdgeSource->addAdjacency(currentEdgeDestination->getId());

            // Add edge weight to minimum cost value
            minimumCost += currentEdge->getWeight();
        }
    }

    // Deletes dynamically create disjointSet
    delete dSet;

    return minimumCost;
}

/// \brief
/// Uses Dijkstra's algorithm to find the shortest path between the source vertex
/// and all other vertices
///
/// \param sourceId unsigned int - the identifier of the source vertex
///
void Graph::dijkstra(unsigned int sourceId) {

    // Queue of vertices not yet visited by algorithim
    priority_queue<Vertex*, vector<Vertex*>, Vertex> unvisitedVerticesQueue;

    Vertex* u;
    Vertex* v;

    // Iterate through all vertices in the graph
    for (unsigned int i = 0; i < vertices.size(); i++) {
        vertices[i]->setDiscovered(false);
        vertices[i]->setPredecessorId(sourceId);
        vertices[i]->setMinDistance(weights[sourceId][i]);

        // Add to queue
        unvisitedVerticesQueue.push(vertices[i]);
    }

    // Iterate through all vertices in queue until empty
    while (unvisitedVerticesQueue.size() > 0) {

        // Access, store and remove highest priority item in queue
        u = unvisitedVerticesQueue.top();
        unvisitedVerticesQueue.pop();
        u->setDiscovered(true);

        // Iterate through all vertices in the graph
        for (unsigned int vId = 0; vId < this->numVertices; vId++) {

            v = this->getVertex((int) vId);

            // Check if the vertex is not the same as the current popped item from queue and that they connect with an edge
            if (vId != u->getId() && this->weights[u->getId()][vId] != INFINITY) {

                // Check that the vertex isn't discovered already and if not set it as the successor to the popped vertex
                if (v->isDiscovered() == false) {
                    if (u->getMinDistance() + this->weights[u->getId()][vId] < v->getMinDistance()) {
                        v->setMinDistance(u->getMinDistance() + this->weights[u->getId()][vId]);
                        v->setPredecessorId(u->getId());
                        unvisitedVerticesQueue.push(v);
                    }
                }
            }
        }
    }

    // Output successful paths from each vertex to the source in this method
    outputPaths(sourceId);
}

/// \brief
/// Uses Breadth First Search algorithm to find the shortest path between the source vertex
/// and all other vertices using only the vertices present in the minimum spanning tree
///
/// \param sourceId unsigned int - the identifier of the source vertex
///
void Graph::bfs(unsigned int sourceId) {
    Vertex* current;

    // Iterate through all vertices in graph
    for (unsigned int i = 0; i < vertices.size(); i++) {

        vertices[i]->setDiscovered(false);
        vertices[i]->setMinDistance(weights[sourceId][i]);
    }

    // Queue of vertices not yet visited by algorithim
    queue<Vertex*> unvisitedVerticesQueue;

    // Set source to discovered and add to queue to begin algorithim
    vertices[sourceId]->setDiscovered(true);
    unvisitedVerticesQueue.push(vertices[sourceId]);

    // Iterate through until the queue is empty
    while (unvisitedVerticesQueue.size() > 0) {

        // Access, store and remove first element of queue
        current = unvisitedVerticesQueue.front();
        unvisitedVerticesQueue.pop();

        // Create set of adjacent vertices to the current vertex and iterator of set
        set<unsigned int> adjSet = *current->getAdjacencies();
        set<unsigned int>::iterator Iterator;

        // Iterate through set
        for (Iterator = adjSet.begin(); Iterator != adjSet.end(); Iterator++) {

            unsigned int vId = *Iterator;
            Vertex* v = this->getVertex(vId);

            // For each adjacent vertex check if it has already been discovered
            if (v->isDiscovered() == false) {

                v->setPredecessorId(current->getId());
                v->setDiscovered(true);
                v->setMinDistance(current->getMinDistance() + this->weights[current->getId()][vId]);

                // Add adjacent vertex to queue to continue the BFS method
                unvisitedVerticesQueue.push(v);
            }
        }
    }

    // Output successful paths from each vertex to the source in this method
    outputPaths(sourceId);
}

/// \brief
/// Returns output containing a string representation of the graph in a dimensional array of weights
///
/// \param out ostream& - the output to be displayed to the user
/// \param vertex Vertex& - the current graph object
///
ostream& operator<<(ostream& out, Graph& graph) {

    // Fix spacing so output is aligned correctly
    out << fixed << setprecision(2);

    // Iterate through all vertices in two dimensional array
    for (unsigned int x = 0; x < graph.numVertices; x++) {
            for (unsigned int y = 0; y < graph.numVertices; y++) {
                out << " " << setw(6);

                // Check if vertices are connected with an edge
                if (graph.weights[x][y] != INFINITY) {

                    // Output edge weight
                    out << graph.weights[x][y];
                }
                else {
                    out << "-";
                }
            }
            out << endl;
    }
    return out;
}

/// \brief
/// Generates string output for the user to be used when displaying paths found using
/// Dijkstra's and Breadth First Search algorithims
///
/// \param sourceId unsigned int - the indentifier of the source vertex
///
void Graph::outputPaths(unsigned int sourceId) {

    Vertex* u;

    // Fix spacing so output is aligned correctly
    cout << fixed << setprecision(2);

    // Iterate through all vertices in the graph
    for (unsigned int i = 0; i < vertices.size(); i++) {

        // The vertex who's path to the source is trying to be identified
        u = vertices[i];

        // Check that the vertex is not the source
        if (u->getId() != sourceId) {

            // The destination vertex does not connect to any other vertex
            if (u->getMinDistance() == INFINITY) {
                cout << "NO PATH  from " << sourceId << " to " << u->getId() << endl;
            }

            // The destination vertex does connect to other vertices
            else {

                // Create vector to hold identifiers of the path
                vector<unsigned int> pathIds;
                cout << "Distance from " << sourceId << " to " << u->getId() << " = " << setw(6) << u->getMinDistance() << " travelling via " << sourceId << " ";

                // Traverse through path using predecessor identifiers
                while (u->getId() != sourceId) {

                    // Add identifier to the vector and change u to next predecessor
                    pathIds.push_back(u->getId());
                    u = vertices[u->getPredecessorId()];
                }

                // Iterate through vector containing path and display to user
                for (unsigned int i = 1; i <= pathIds.size(); i++) {

                    cout << pathIds[pathIds.size() - i] << " ";
                }

                cout << endl;
            }
        }
    }
}
