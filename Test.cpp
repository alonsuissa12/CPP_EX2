// 211344015 alonsuissa12@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
//v
TEST_CASE("Test graph addition (+)") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph1 = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};
    CHECK_EQ(g3.allEdges(), expectedGraph1);
    vector<vector<int>> expectedGraph2 = {
            {0, 6, 3},
            {6, 0, 9},
            {3, 9, 0}};
    CHECK_EQ((g3 + g3 + g3).allEdges(), expectedGraph2);
    ariel::Graph g4;
    vector<vector<int>> matrix4 = {
            {0,  -1, -1},
            {-1, 0,  -2},
            {-1, -2, 0}};
    g4.loadGraph(matrix4);
    vector<vector<int>> expectedGraph3 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    CHECK_EQ((g4 + g2).allEdges(), expectedGraph3);
}

//v
TEST_CASE("Test -") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph1 = {
            {0,  0,  -1},
            {0,  0,  -1},
            {-1, -1, 0}};
    CHECK_EQ(g3.allEdges(), expectedGraph1);
    vector<vector<int>> expectedGraph2 = {
            {0, 0, 1},
            {0, 0, 1},
            {1, 1, 0}};
    CHECK_EQ((g3 - g3 - g3).allEdges(), expectedGraph2);

    vector<vector<int>> expectedGraph3 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    CHECK_EQ((g2 - g2).allEdges(), expectedGraph3);

    ariel::Graph g4;
    vector<vector<int>> matrix4 = {
            {0,  -1, -1},
            {-1, 0,  -2},
            {-1, -2, 0}};
    g4.loadGraph(matrix4);
    vector<vector<int>> expectedGraph4 = {
            {0, 2, 2},
            {2, 0, 4},
            {2, 4, 0}};
    CHECK_EQ((g2 - g4).allEdges(), expectedGraph4);


}
//v
TEST_CASE("Test graph multiplication (*) ")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph1 = {
            {0, 0, 2},
            {1, 0, 1},
            {1, 0, 0}};
    CHECK_EQ(g4.allEdges(), expectedGraph1);
    ariel::Graph g5;
    vector<vector<int>> M5 = {
            {0,  -2, -5},
            {-1, 0,  -8},
            {-3, -1, 0}};
    g5.loadGraph(M5);
    vector<vector<int>> expectedGraph2 = {
            {0,  -1, -8},
            {-6, 0,  -5},
            {-2, -2, 0}};

    CHECK_EQ((g2 * g5).allEdges(), expectedGraph2);
    vector<vector<int>> expectedGraph3 = {
            {0, 1, 8},
            {6, 0,  5},
            {2, 2, 0}};
    vector<vector<int>> expectedGraph4 = {
            {0, 2, 16},
            {12, 0,  10},
            {4, 4, 0}};
    CHECK_EQ((g2*g5*(-1)).allEdges(),expectedGraph3);
    CHECK_EQ((g2*g5*(-2)).allEdges(),expectedGraph4);

}
//v
TEST_CASE("Test +=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph1 = {
            {0, 0, 2},
            {1, 0, 1},
            {1, 0, 0}};
    CHECK_EQ(g4.allEdges(), expectedGraph1);
    ariel::Graph g5;
    vector<vector<int>> M5 = {
            {0,  -2, -5},
            {-1, 0,  -8},
            {-3, -1, 0}};
    g5.loadGraph(M5);
    vector<vector<int>> expectedGraph2 = {
            {0,  -1, -8},
            {-6, 0,  -5},
            {-2, -2, 0}};

    CHECK_EQ((g2 * g5).allEdges(), expectedGraph2);


}
//v
TEST_CASE("Test -=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    g2 -= g1;
    vector<vector<int>> expectedGraph1 = {
            {0, 0, 1},
            {0, 0, 1},
            {1, 1, 0}};
    CHECK_EQ(g2.allEdges(), expectedGraph1);

    vector<vector<int>> expectedGraph2 = {
            {0,  -1, -1},
            {-1, 0,  -1},
            {-1, -1, 0}};
    g2 -= g2;
    g2 -= 1;
    CHECK_EQ(g2.allEdges(), expectedGraph2);
    ariel::Graph g4;
    vector<vector<int>> matrix4 = {
            {0,  -1, -1},
            {-1, 0,  -2},
            {-1, -2, 0}};
    g4.loadGraph(matrix4);
    vector<vector<int>> expectedGraph3 = {
            {0,  -2, -2 },
            {-2, 0,  -1},
            {-2, -1, 0}};
    g2 -= g4;
    g2 -= 2;

    CHECK_EQ(g2.allEdges(), expectedGraph3);

}
//v
TEST_CASE("Test *=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph expected1(graph1);
    g1 *=1;
    CHECK_EQ(g1.allEdges(),expected1.allEdges());


    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 *=  g2;
    vector<vector<int>> expectedGraph1 = {
            {0, 0, 2},
            {1, 0, 1},
            {1, 0, 0}};
    CHECK_EQ(g1.allEdges(), expectedGraph1);

    ariel::Graph g5;
    vector<vector<int>> M5 = {
            {0,  -2, -5},
            {-1, 0,  -8},
            {-3, -1, 0}};
    g5.loadGraph(M5);

    vector<vector<int>> expectedGraph2 = {
            {0,  -1, -8},
            {-6, 0,  -5},
            {-2, -2, 0}};
    g2 *= g5;
    CHECK_EQ(g2.allEdges(), expectedGraph2);

    vector<vector<int>> expectedGraph3 = {
            {0,  2, 16},
            {12, 0,  10},
            {4, 4, 0}};
    g2 *= -2;
    CHECK_EQ(g2.allEdges(), expectedGraph3);




}

TEST_CASE("Test /=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);


    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};

}
//v
TEST_CASE("Test unary - and +")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;

    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK_EQ(g1.allEdges(),(+g1).allEdges());
    CHECK_EQ(g2.allEdges(),(+g2).allEdges());
    CHECK_EQ((g1*(-1)).allEdges(),(-g1).allEdges());
    CHECK_EQ((g2*(-1)).allEdges(),(-g2).allEdges());

    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};

}
//v
TEST_CASE("Test --")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);


    vector<vector<int>> expectedGraph1 = {
            {0, 0, -1},
            {0, 0, 0},
            {-1, 0, 0}};
    vector<vector<int>> expectedGraph2 = {
            {0, 0, 0},
            {0, 0, 1},
            {0, 1, 0}};

    CHECK_EQ((--g1).allEdges(),expectedGraph1);
    CHECK_EQ((--g2).allEdges(),expectedGraph2);
    CHECK_EQ((g1--).allEdges(),expectedGraph1);
    CHECK_EQ((g2--).allEdges(),expectedGraph2);

    vector<vector<int>> expectedGraph3 = {
            {0, -1, -1},
            {-1, 0, 0},
            {-1, 0, 0}};
    CHECK_EQ(g2.allEdges(),expectedGraph3);
    vector<vector<int>> expectedGraph4 = {
            {0, -4, -4},
            {-4, 0, -3},
            {-4, -3, 0}};
    CHECK_EQ((------g2).allEdges(),expectedGraph4);

}
//v
TEST_CASE("Test ++")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);


    vector<vector<int>> expectedGraph1 = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    vector<vector<int>> expectedGraph2 = {
            {0, 2, 2},
            {2, 0, 3},
            {2, 3, 0}};

    CHECK_EQ((++g1).allEdges(),expectedGraph1);
    CHECK_EQ((++g2).allEdges(),expectedGraph2);
    CHECK_EQ((g1++).allEdges(),expectedGraph1);
    CHECK_EQ((g2++).allEdges(),expectedGraph2);

    vector<vector<int>> expectedGraph3 = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    CHECK_EQ(g2.allEdges(),expectedGraph3);
    vector<vector<int>> expectedGraph4 = {
            {0, 6, 6},
            {6, 0, 7},
            {6, 7, 0}};
    CHECK_EQ((++++++g2).allEdges(),expectedGraph4);
}

TEST_CASE("Test < and >")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);


    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};

}

TEST_CASE("Test <= and >=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);


    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};

}

TEST_CASE("Test == and !=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);


    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};

}

TEST_CASE("Test print (<<) ")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);


    vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 3},
            {1, 3, 0}};

}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1, 1},
            {1, 0, 2, 1},
            {1, 2, 0, 1},
            {1, 2, 0, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS((g5 * g1));
    CHECK_THROWS((g1 * g2));

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}