
// 211344015 alonsuissa12@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

namespace ariel { class Graph; }


namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        int numVertices;
        bool directed;
        bool wighted;
        bool negative;

        bool isDirectedSelf();

        bool isWeightedSelf();

        bool includeNegativeSelf();

    public:
        //constructor 1
        explicit Graph();

        // Constructor 2
        explicit Graph(const std::vector<std::vector<int>> &matrix);

        //destructor
        ~Graph();

        // load a new data to the graph
        void loadGraph(const std::vector<std::vector<int>> &a);

        //is the graph directed
        bool isDirected() const;

        //is the graph weighted
        bool isWeighted() const;

        //is the graph include negative edges
        bool includeNegative() const;

        int numOfVertices() const;

        // Method to print the graph
        void printGraph();

        // return array of neighbors of v
        std::vector<int> neighborsOf(int);

        //return copy of the adjacency matrix
        std::vector<std::vector<int>> allEdges() const;



        //override the += operator to add to this graph's edges weights some fixed weight
        friend Graph &operator+=(Graph &g1, int x);

        // multiply the graph edges weight with x
        friend Graph &operator*=(Graph &g, int x);

        // divide the graph edges weight with x
        friend Graph &operator/=(Graph &g1, int x);

        // Overloading << operator to display graph
        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

        //override the - operator to unary -
        friend Graph operator-(Graph &g1);
    };


    //override the + operator to add a graph's edges weight to another graph edges weights
    Graph operator+(const Graph &g1, const Graph &g2); //v

    //override the - operator to subtract a graph's edges weight to another graph edges weights
    Graph operator-(const Graph &g1, const Graph &g2); //v

    //override the += operator to add to this graph's edges weights another graph's edges weights
    Graph &operator+=(Graph &g1, const Graph &g2);

    //override the -= operator to subtract to this graph's edges weights some fixed weight
    Graph &operator-=(Graph &g1, int x);

    //override the -= operator to subtract from this graph's edges weights another graph's edges weights
    Graph &operator-=(Graph &g1, const Graph &g2);


    //override the + operator to unary +
    Graph operator+(const Graph &g1);

    // subtract 1 from the graph edges weight
    Graph &operator--(Graph &g1);
    Graph operator--(Graph &g1, int postfix);

    // add 1 to the graph edges weight
    Graph &operator++(Graph &g1);
    Graph operator++(Graph &g1, int postfix) ;

    //returns a new graph which have adjacency matrix equal to the multiplication of the adjacency matrices of g1,g2
    Graph operator*(const Graph &g1, const Graph &g2);

    //return True if g1 containing g2 or g1 has more edges or same number of edges and g2 have more vertexes
    bool operator<(const Graph &g1, const Graph &g2);

    //return True if g2 containing g1 or g2 has more edges or same number of edges and g1 have more vertexes
    bool operator>(const Graph &g1, const Graph &g2);

    //return True if g2 and g1 have exactly the same adjacency matrix or g1 < g2 is false and g1 > g2 is false
    bool operator==(const Graph &g1, const Graph &g2);

    //return True if g2 and g1 doesn't have exactly the same adjacency matrix and g1 < g2 or g1 > g2 is true
    bool operator!=(const Graph &g1, const Graph &g2);

    //return True if g2 and g1 have exactly the same adjacency matrix or and g1 > g2 is false
    bool operator<=(const Graph &g1, const Graph &g2);

    //return True if g1 and g2 have exactly the same adjacency matrix or and g2 > g1 is false
    bool operator>=(const Graph &g1, const Graph &g2);

}


#endif // GRAPH_HPP
