// 211344015 alonsuissa12@gmail.com

/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"

using ariel::Algorithms;


using namespace std;

int main() {
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout << g1; // Should print the graph: 0 <--[1]--> 1 , 1 <--[1]--> 2


    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together to get: [0, 2, 1], [2, 0, 3], [1, 3, 0]
    cout << g3;                 // Should print the graph: 0 <--[2]--> 1 , 0 <--[1]--> 2 , 1 <--[3]--> 2


    g1 *= -2;        // Multiply the graph by -2 to get: [0, -2, 0], [-2, 0, -2], [0, -2, 0]
    cout << g1;       // Should print the matrix of the graph: 0 <--[-2]--> 1 , 1 <--[-2]--> 2


    g1 /= -2;
    ariel::Graph g4 = g1 * g2; // Multiply the two graphs together to get:  [0, 0, 2], [1, 0, 1], [1, 0, 0]
    cout << g4;           // Should print the graph: 0 --[2]--> 2 , 1 --[1]--> 0 , 1 --[1]--> 2 , 2 --[1]--> 0


    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2); // Load the graph to the object.
    try {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e) {
        cout << e.what() << endl; // can't multiply matrices with different sizes!

    }

    vector<vector<int>> m7 = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
    ariel::Graph g7(m7);
    cout << "is connected: " << ariel::Algorithms::isConnected(g7) << endl; // should print 0
    cout << "is contain Cycle: " << ariel::Algorithms::isContainsCycle(g7)<< endl; // should print 0
    cout << "is bipartite: " << (ariel::Algorithms::isBipartite(g7).first.size() == g7.numOfVertices()) << endl; // should print 1
    cout << "is contains negative cycle: "; ariel::Algorithms::negativeCycle(g7); // should print there is no negative cycle
    cout << "shortest path from 1 to 3: "; ariel::Algorithms::shortestPath(g7,1,3);  // should print there is no path

    cout<< "\ng7++\n" << endl;
    g7++;

    cout << "is connected: " << ariel::Algorithms::isConnected(g7) << endl; // should print 1
    cout << "is contain Cycle: "; ariel::Algorithms::isContainsCycle(g7); // should print a cycle
    cout << "is bipartite: " << (ariel::Algorithms::isBipartite(g7).first[0] != ariel::Algorithms::isBipartite(g7).second[0]) << endl; // should print  0
    cout << "is contains negative cycle: "; ariel::Algorithms::negativeCycle(g7)[0] ; // should print there is no negative cycle
    cout << "shortest path from 1 to 3: "; ariel::Algorithms::shortestPath(g7,1,3);  // should print a path and its weight

    cout<< "\ng7 *= -1\n" << endl;
    g7 *= -1;

    cout << "is connected: " << ariel::Algorithms::isConnected(g7) << endl; // should print 1
    cout << "is contain Cycle: "; ariel::Algorithms::isContainsCycle(g7); // should print a cycle
    cout << "is bipartite: " << (ariel::Algorithms::isBipartite(g7).first[0] != ariel::Algorithms::isBipartite(g7).second[0]) << endl; // should print  0
    cout << "is contains negative cycle: "; ariel::Algorithms::negativeCycle(g7); // should print a negative cycle
    cout << "shortest path from 1 to 3: "; ariel::Algorithms::shortestPath(g7,1,3);  // should print there is a negative cycle! no shortest path!

    cout << "\nG7:\n"<<g7; // should print the graph

}
