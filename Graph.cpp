// 211344015 alonsuissa12@gmail.com
#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.hpp"

#define DEBUG(x) std::cout << x << std::endl
using namespace ariel;

// Constructor 1
Graph::Graph() {
    numVertices = 0;
    directed = false;
    wighted = false;
    negative = false;
}

// Constructor 2
Graph::Graph(const std::vector<std::vector<int>> &matrix) {
    if (matrix.empty()) {
        numVertices = 0;
        return;
    }

    if (matrix[0].size() != matrix.size())
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");

    for (unsigned int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] != 0)
            throw std::invalid_argument("Invalid graph: No self Edges allowed.");
    }

    numVertices = static_cast<int>(matrix.size());
    auto iulnumVertices = (unsigned int) numVertices;
    adjacencyMatrix.resize(iulnumVertices, std::vector<int>(iulnumVertices, 0));
    for (unsigned int i = 0; i < iulnumVertices; ++i) {
        for (unsigned int j = 0; j < iulnumVertices; ++j) {
            adjacencyMatrix[i][j] = matrix[i][j];
        }
    }

    negative = includeNegativeSelf();
    directed = isDirectedSelf();
    wighted = isWeightedSelf();
}

void Graph::loadGraph(const std::vector<std::vector<int>> &matrix) {

    if (!matrix.empty() && matrix[0].size() != matrix.size())
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] != 0)
            throw std::invalid_argument("Invalid graph: No self Edges allowed.");
    }
    numVertices = static_cast<int>(matrix.size());
    auto iuNumOfVertices = (int unsigned) numVertices;
    adjacencyMatrix.resize(iuNumOfVertices, std::vector<int>(iuNumOfVertices, 0));
    for (unsigned int i = 0; i < iuNumOfVertices; ++i) {
        for (unsigned int j = 0; j < iuNumOfVertices; ++j) {
            adjacencyMatrix[i][j] = matrix[i][j];
        }
    }
    negative = includeNegativeSelf();
    directed = isDirectedSelf();
    wighted = isWeightedSelf();
}


bool Graph::isDirected() const {
    return directed;
}

bool Graph::isWeighted() const {
    return wighted;
}

bool Graph::includeNegative() const {
    return negative;
}

void Graph::printGraph() {
    if (isDirected()) {
        for (unsigned int i = 0; i < numVertices; ++i) {
            bool vertexPrinted = false;
            for (unsigned int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    vertexPrinted = true;
                    std::cout << i << " --[" << adjacencyMatrix[i][j] << "]--> " << j << "\n";
                }
            }
            if (!vertexPrinted)
                std::cout << i << std::endl;
        }
    } else {
        for (unsigned int i = 0; i < numVertices; ++i) {
            bool vertexPrinted = false;
            for (unsigned int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    vertexPrinted = true;
                    if (j > i)
                        std::cout << i << " <--[" << adjacencyMatrix[i][j] << "]--> " << j << "\n";
                }
            }
            if (!vertexPrinted)
                std::cout << i << std::endl;
        }
    }
}

int Graph::numOfVertices() const {
    return numVertices;
}

// return array of neighbors of v
std::vector<int> Graph::neighborsOf(int v) {
    std::vector<int> neighbors;
    for (int unsigned long i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[(int unsigned long) v][i] != 0)
            neighbors.push_back((int) i);
    }
    return neighbors;
}

// return a copy of adjacency matrix represents the graph
std::vector<std::vector<int>> Graph::allEdges() const {
    std::vector<std::vector<int>> copyMatrix((int unsigned long) numVertices,
                                             std::vector<int>((int unsigned long) numVertices));

    for (int unsigned long i = 0; i < numVertices; ++i) {
        for (int unsigned long j = 0; j < numVertices; ++j) {
            copyMatrix[i][j] = (int) adjacencyMatrix[i][j];
        }
    }
    return copyMatrix;
}

//checks if the graph is directed
bool Graph::isDirectedSelf() {
    for (unsigned int i = 0; i < numVertices; i++) {
        for (unsigned int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return true;
            }
        }
    }
    return false;
}

//checks if the graph is weighted
bool Graph::isWeightedSelf() {
    for (int unsigned long i = 0; i < numVertices; i++) {
        for (int unsigned long j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1)
                return true;
        }
    }
    return false;
}

//checks if the graph has negative edges
bool Graph::includeNegativeSelf() {
    for (int unsigned long i = 0; i < numVertices; ++i) {
        for (int unsigned long j = 0; j < numVertices; ++j) {
            if (adjacencyMatrix[i][j] < 0)
                return true;
        }
    }
    return false;
}

//destructor (not really necessary right now)
Graph::~Graph() = default;


//###################################################### OPERATORS #####################################################

namespace ariel {
//override the + operator to add a graph's edges weight to this graph edges weight
    Graph operator+(const Graph &g1, const Graph &g2) {
        int numVertexesG1 = g1.numOfVertices();
        int numVertexesG2 = g2.numOfVertices();
        std::vector<std::vector<int>> adjMatrix1 = g1.allEdges();
        std::vector<std::vector<int>> adjMatrix2 = g2.allEdges();

        if (numVertexesG1 != numVertexesG2) {
            throw std::invalid_argument("Can't add matrices with different sizes");
        }

        std::vector<std::vector<int>> adjMatrix3((unsigned int) numVertexesG1,
                                                 std::vector<int>((unsigned int) numVertexesG1, 0));

        for (unsigned int i = 0; i < numVertexesG1; ++i) {
            for (unsigned int j = 0; j < numVertexesG1; ++j) {
                adjMatrix3[i][j] = adjMatrix1[i][j] + adjMatrix2[i][j];
            }
        }

        Graph g3(adjMatrix3);
        return g3;
    }

//override the - operator to subtract a graph's edges weight from this graph edges weight
    Graph operator-(const Graph &g1, const Graph &g2) {
        int numVertexesG1 = g1.numOfVertices();
        int numVertexesG2 = g2.numOfVertices();
        std::vector<std::vector<int>> adjMatrix1 = g1.allEdges();
        std::vector<std::vector<int>> adjMatrix2 = g2.allEdges();

        if (numVertexesG1 != numVertexesG2) {
            throw std::invalid_argument("Can't subtract matrices with different sizes");
        }

        std::vector<std::vector<int>> adjMatrix3((unsigned int) numVertexesG1,
                                                 std::vector<int>((unsigned int) numVertexesG1, 0));

        for (unsigned int i = 0; i < numVertexesG1; ++i) {
            for (unsigned int j = 0; j < numVertexesG1; ++j) {
                adjMatrix3[i][j] = adjMatrix1[i][j] - adjMatrix2[i][j];
            }
        }

        Graph g3(adjMatrix3);
        return g3;
    }

//override the += operator to add to the graph's edges weight a fixed weight
    Graph &operator+=(Graph &g1, int x) {
        for (unsigned int i = 0; i < g1.numVertices; ++i) {
            for (unsigned int j = 0; j < g1.numVertices; ++j) {
                if (j != i)
                    g1.adjacencyMatrix[i][j] = g1.adjacencyMatrix[i][j] + x;
            }
        }
        g1.negative = g1.includeNegativeSelf();
        g1.wighted = g1.isWeightedSelf();

        return g1;
    }

//override the + operator to unary +
    Graph operator+(const Graph &g) {
        return Graph(g.allEdges());
    }

//override the - operator to unary -
    Graph operator-(Graph &g) {
        Graph g1 = Graph(g.allEdges());
        for (unsigned int i = 0; i < g1.numVertices; ++i) {
            for (unsigned int j = 0; j < g1.numVertices; ++j) {
                g1.adjacencyMatrix[i][j] = g1.adjacencyMatrix[i][j] * (-1);
                if (g1.adjacencyMatrix[i][j] < 0)
                    g1.negative = true;
            }
        }
        return g1;
    }

//return True if g1 containing g2 (and not exactly same) or g1 has more edges or same number of edges and g2 have more vertexes
    bool operator<(const Graph &g1, const Graph &g2) {
        int numVertexesG1 = g1.numOfVertices();
        int numVertexesG2 = g2.numOfVertices();
        std::vector<std::vector<int>> adjMatrix1 = g1.allEdges();
        std::vector<std::vector<int>> adjMatrix2 = g2.allEdges();

        // is g2 contain g1?
        bool contain = numVertexesG1 < numVertexesG2;
        int edgesInG2 = 0;
        int edgesInG1 = 0;
        if (numVertexesG2 - numVertexesG1 > 0) { // needed because the cooperation inside the for is unsigned

            // k and t to move down/right in the big matrix (g2)
            for (unsigned int k = 0; k <= numVertexesG2 - numVertexesG1; k++) {
                for (unsigned int t = 0; t <= numVertexesG2 - numVertexesG1; t++) {
                    contain = true;
                    if (k == 0 && t == 0) {// don't look for exactly same
                        contain = false;
                    }
                    for (unsigned int i = 0; i < numVertexesG1 && contain; ++i) {
                        for (unsigned int j = 0; j < numVertexesG1 && contain; ++j) {


                            if (adjMatrix1[i][j] != adjMatrix2[i + k][j + t]) {
                                contain = false;
                            }
                        }
                    }
                    if (contain) {
                        return true;
                    }
                }
            }
        }
        // is g2 has more edges?
        for (unsigned int i = 0; i < numVertexesG1; ++i) {
            for (unsigned int j = 0; j < numVertexesG1; ++j) {
                if (adjMatrix1[i][j] != 0)
                    edgesInG1++;
            }
        }
        for (unsigned int i = 0; i < numVertexesG2; ++i) {
            for (unsigned int j = 0; j < numVertexesG2; ++j) {
                if (adjMatrix2[i][j] != 0)
                    edgesInG2++;
            }
        }

        if (edgesInG2 > edgesInG1)
            return true;
        if (edgesInG2 == edgesInG1)
            return numVertexesG1 < numVertexesG2;
        return false;
    }

    //return True if g2 and g1 have exactly the same adjacency matrix or g1 < g2 is false and g1 > g2 is false
    bool operator==(const Graph &g1, const Graph &g2) {
        int numVertexesG1 = g1.numOfVertices();
        int numVertexesG2 = g2.numOfVertices();
        std::vector<std::vector<int>> adjMatrix1 = g1.allEdges();
        std::vector<std::vector<int>> adjMatrix2 = g2.allEdges();
        bool equal = (numVertexesG1 == numVertexesG2);
        for (unsigned int i = 0; i < numVertexesG1 && equal; ++i) {
            for (unsigned int j = 0; j < numVertexesG1 && equal; ++j) {
                equal = (adjMatrix1[i][j] == adjMatrix2[i][j]);
            }
        }
        if (equal)
            return true;
        return ((!(g1 < g2)) && (!(g2 < g1))); // is no one bigger then the other?
    }

    // multiply the graph edges weight with x
    Graph &operator*=(Graph &g1, int x) {
        for (unsigned int i = 0; i < g1.numVertices; ++i) {
            for (unsigned int j = 0; j < g1.numVertices; ++j) {
                g1.adjacencyMatrix[i][j] *= x;
            }
        }
        g1.directed = g1.isDirectedSelf();
        g1.wighted = g1.isWeightedSelf();
        g1.negative = g1.includeNegativeSelf();
        return g1;
    }

    Graph operator*=(Graph &g1, const Graph &g2) {
        Graph g = g1 * g2;
        g1.loadGraph(g.allEdges());
        return g;
    }


    // divide the graph edges weight with x
    Graph &operator/=(Graph &g1, int x) {
        if (x == 0)
            throw std::invalid_argument("cannot divide by 0");
        for (unsigned int i = 0; i < g1.numVertices; ++i) {
            for (unsigned int j = 0; j < g1.numVertices; ++j) {
                g1.adjacencyMatrix[i][j] /= x;
            }
        }
        g1.directed = g1.isDirectedSelf();
        g1.wighted = g1.isWeightedSelf();
        g1.negative = g1.includeNegativeSelf();
        return g1;
    }

    // Overloading << operator to display graph
    std::ostream &operator<<(std::ostream &os, const Graph &g) {
        if (g.isDirected()) {
            for (unsigned int i = 0; i < g.numVertices; ++i) {
                bool vertexPrinted = false;
                for (unsigned int j = 0; j < g.numVertices; ++j) {
                    if (g.adjacencyMatrix[i][j] != 0) {
                        vertexPrinted = true;
                        os << i << " --[" << g.adjacencyMatrix[i][j] << "]--> " << j << "\n";
                    }
                }
                if (!vertexPrinted)
                    os << i << std::endl;
            }
        } else {
            for (unsigned int i = 0; i < g.numVertices; ++i) {
                bool vertexPrinted = false;
                for (unsigned int j = 0; j < g.numVertices; ++j) {
                    if (g.adjacencyMatrix[i][j] != 0) {
                        vertexPrinted = true;
                        if (j > i)
                            os << i << " <--[" << g.adjacencyMatrix[i][j] << "]--> " << j << "\n";
                    }
                }
                if (!vertexPrinted)
                    os << i << std::endl;
            }
        }
        os << "\n";

        return os;
    }

    // returns a new graph which have adjacency matrix equal to the multiplication of the adjacency matrices of g1,g2
    Graph operator*(const Graph &g1, const Graph &g2) {
        auto G1numVertices = (unsigned int) g1.numOfVertices();
        auto G2numVertices = (unsigned int) g2.numOfVertices();
        std::vector<std::vector<int>> adjMatrix1 = g1.allEdges();
        std::vector<std::vector<int>> adjMatrix2 = g2.allEdges();

        if (G1numVertices != G2numVertices) {
            throw std::invalid_argument("can't multiply matrices with different sizes! ");
        }
        std::vector<std::vector<int>> adjMatrix3;
        adjMatrix3.resize(G1numVertices, std::vector<int>(G1numVertices, 0));
        for (unsigned int k = 0; k < G1numVertices; ++k) {
            for (unsigned int i = 0; i < G1numVertices; ++i) {
                for (unsigned int j = 0; j < G1numVertices; ++j) {
                    adjMatrix3[k][i] += adjMatrix1[k][j] * adjMatrix2[j][i];
                }
            }
        }
        // remove self edges if exist
        for (unsigned int i = 0; i < G1numVertices; ++i) {
            adjMatrix3[i][i] = 0;
        }

        Graph g3(adjMatrix3);
        return g3;
    }

    Graph operator*(const Graph &g1, int x) {
        Graph ans;
        ans.loadGraph(g1.allEdges());
        ans *= x;
        return ans;
    }

    // override the += operator to add to this graph's edges weights another graph's edges weights
    Graph &operator+=(Graph &g1, const Graph &g2) {
        g1.loadGraph((g1 + g2).allEdges());
        return g1;
    }

    // override the -= operator to subtract to this graph's edges weights some fixed weight
    Graph &operator-=(Graph &g1, int x) { return g1 += -x; }

    // override the -= operator to subtract from this graph's edges weights another graph's edges weights
    Graph &operator-=(Graph &g1, const Graph &g2) {
        g1.loadGraph((g1 - g2).allEdges());
        return g1;
    }

    // subtract 1 from the graph edges weight
    Graph &operator--(Graph &g1) { return g1 -= 1; }

    Graph operator--(Graph &g1, int postfix) {
        Graph g2 = Graph(g1.allEdges());
        g1 -= 1;
        return g2;
    }

    // add 1 to the graph edges weight
    Graph &operator++(Graph &g1) { return g1 += 1; }

    Graph operator++(Graph &g1, int postfix) {
        Graph g2 = Graph(g1.allEdges());
        g1 += 1;
        return g2;
    }

    //return True if g2 containing g1 or g2 has more edges or same number of edges and g1 have more vertexes
    bool operator>(const Graph &g1, const Graph &g2) { return g2 < g1; }

    //return True if g2 and g1 doesn't have exactly the same adjacency matrix and g1 < g2 or g1 > g2 is true
    bool operator!=(const Graph &g1, const Graph &g2) { return (!(g1 == g2)); }

    //return True if g2 and g1 have exactly the same adjacency matrix or and g1 > g2 is false
    bool operator<=(const Graph &g1, const Graph &g2) { return ((g1 < g2) || (g1 == g2)); }

    //return True if g1 and g2 have exactly the same adjacency matrix or and g2 > g1 is false
    bool operator>=(const Graph &g1, const Graph &g2) { return ((g1 > g2) || (g1 == g2)); }


}


#endif // GRAPH_CPP
