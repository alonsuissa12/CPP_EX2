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
            {6, 0, 5},
            {2, 2, 0}};
    vector<vector<int>> expectedGraph4 = {
            {0,  2, 16},
            {12, 0, 10},
            {4,  4, 0}};
    CHECK_EQ((g2 * g5 * (-1)).allEdges(), expectedGraph3);
    CHECK_EQ((g2 * g5 * (-2)).allEdges(), expectedGraph4);

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
            {0,  -2, -2},
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
    g1 *= 1;
    CHECK_EQ(g1.allEdges(), expected1.allEdges());


    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 *= g2;
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
            {12, 0, 10},
            {4,  4, 0}};
    g2 *= -2;
    CHECK_EQ(g2.allEdges(), expectedGraph3);


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
    CHECK_EQ(g1.allEdges(), (+g1).allEdges());
    CHECK_EQ(g2.allEdges(), (+g2).allEdges());
    CHECK_EQ((g1 * (-1)).allEdges(), (-g1).allEdges());
    CHECK_EQ((g2 * (-1)).allEdges(), (-g2).allEdges());

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
            {0,  0, -1},
            {0,  0, 0},
            {-1, 0, 0}};
    vector<vector<int>> expectedGraph2 = {
            {0, 0, 0},
            {0, 0, 1},
            {0, 1, 0}};

    CHECK_EQ((--g1).allEdges(), expectedGraph1);
    CHECK_EQ((--g2).allEdges(), expectedGraph2);
    CHECK_EQ((g1--).allEdges(), expectedGraph1);
    CHECK_EQ((g2--).allEdges(), expectedGraph2);

    vector<vector<int>> expectedGraph3 = {
            {0,  -1, -1},
            {-1, 0,  0},
            {-1, 0,  0}};
    CHECK_EQ(g2.allEdges(), expectedGraph3);
    vector<vector<int>> expectedGraph4 = {
            {0,  -4, -4},
            {-4, 0,  -3},
            {-4, -3, 0}};
    CHECK_EQ((-- -- --g2).allEdges(), expectedGraph4);

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

    CHECK_EQ((++g1).allEdges(), expectedGraph1);
    CHECK_EQ((++g2).allEdges(), expectedGraph2);
    CHECK_EQ((g1++).allEdges(), expectedGraph1);
    CHECK_EQ((g2++).allEdges(), expectedGraph2);

    vector<vector<int>> expectedGraph3 = {
            {0, 3, 3},
            {3, 0, 4},
            {3, 4, 0}};
    CHECK_EQ(g2.allEdges(), expectedGraph3);
    vector<vector<int>> expectedGraph4 = {
            {0, 6, 6},
            {6, 0, 7},
            {6, 7, 0}};
    CHECK_EQ((++ ++ ++g2).allEdges(), expectedGraph4);
}
//v
TEST_CASE("Test < and >")
{
    ariel::Graph g1;
    vector<vector<int>> m1 = {
            {0, 0,  0, 0, 1, 1},
            {0, 0,  0, 1, 0, 2},
            {0, 0,  0, 1, 2, 0},
            {0, 0,  0, 0, 1, 0},
            {0, -1, 0, 0, 0, 0},
            {2, 0,  0, 0, 1, 0}};
    g1.loadGraph(m1);
    ariel::Graph g2;
    vector<vector<int>> m2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(m2);

    vector<vector<int>> m3 = {
            {0, -1},
            {2, 0}};
    ariel::Graph g3(m3);
    vector<vector<int>> m4 = {
            {0, 0},
            {3, 0}};
    ariel::Graph g4(m4);
    vector<vector<int>> m5 = {
            {0, 0, 0},
            {0, 0, 0},
            {1, 0, 0}};
    ariel::Graph g5(m5);
    vector<vector<int>> m6 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    ariel::Graph g6(m6);


    vector<vector<int>> m7 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0}};

    vector<vector<int>> m8 = {
            {0, 0, 0},
            {1, 0, 1},
            {0, 0, 0}};

    ariel::Graph g7(m7);
    ariel::Graph g8(m8);
    CHECK((g8 < g7));
    CHECK((g3 < g1));
    CHECK((g2 < g1));
    CHECK((g1 > g3));
    CHECK((g1 > g2));

    CHECK_FALSE((g2 > g1));
    CHECK_FALSE((g3 > g1));
    CHECK_FALSE((g1 < g2));
    CHECK_FALSE((g1 < g3));

    CHECK((g2 > g3));
    CHECK((g3 > g4));
    CHECK((g4 < g3));
    CHECK((g3 > g5));
    CHECK((g5 < g3));
    CHECK((g6 < g4));
    CHECK((g4 > g6));


}
//v
TEST_CASE("Test <= and >=")
{
    ariel::Graph g1;
    vector<vector<int>> m1 = {
            {0, 0,  0, 0, 1, 1},
            {0, 0,  0, 1, 0, 2},
            {0, 0,  0, 1, 2, 0},
            {0, 0,  0, 0, 1, 0},
            {0, -1, 0, 0, 0, 0},
            {2, 0,  0, 0, 1, 0}};
    g1.loadGraph(m1);
    ariel::Graph g2;
    vector<vector<int>> m2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(m2);

    vector<vector<int>> m3 = {
            {0, -1},
            {2, 0}};
    ariel::Graph g3(m3);
    vector<vector<int>> m4 = {
            {0, 0},
            {3, 0}};
    ariel::Graph g4(m4);
    vector<vector<int>> m5 = {
            {0, 0, 0},
            {0, 0, 0},
            {1, 0, 0}};
    ariel::Graph g5(m5);
    vector<vector<int>> m6 = {
            {0, 0, 1},
            {0, 0, 0},
            {0, 0, 0}};
    ariel::Graph g6(m6);

    CHECK((g3 <= g3));
    CHECK((g4 >= g4));
    CHECK((g6 <= g5));
    CHECK((g6 <= g5));

    CHECK((g3 <= g1));
    CHECK((g2 <= g1));
    CHECK((g1 >= g3));
    CHECK((g1 >= g2));

    CHECK_FALSE((g2 >= g1));
    CHECK_FALSE((g3 >= g1));
    CHECK_FALSE((g1 <= g2));
    CHECK_FALSE((g1 <= g3));

    CHECK((g2 >= g3));
    CHECK((g3 >= g4));
    CHECK((g4 <= g3));
    CHECK((g3 >= g5));
    CHECK((g5 <= g3));
    CHECK((g6 <= g3));
    CHECK((g3 >= g6));


}
//v
TEST_CASE("Test == and !=")
{
    ariel::Graph g1;
    vector<vector<int>> m1 = {
            {0, 0,  0, 0, 1, 1},
            {0, 0,  0, 1, 0, 2},
            {0, 0,  0, 1, 2, 0},
            {0, 0,  0, 0, 1, 0},
            {0, -1, 0, 0, 0, 0},
            {2, 0,  0, 0, 1, 0}};
    g1.loadGraph(m1);
    ariel::Graph g2;
    vector<vector<int>> m2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(m2);

    vector<vector<int>> m3 = {
            {0, 0},
            {3, 0}};
    ariel::Graph g3(m3);
    vector<vector<int>> m4 = {
            {0, 0},
            {3, 0}};
    ariel::Graph g4(m4);
    vector<vector<int>> m5 = {
            {0, 0, 0},
            {0, 0, 0},
            {1, 0, 0}};
    ariel::Graph g5(m5);
    vector<vector<int>> m6 = {
            {0, 0, 2},
            {0, 0, 0},
            {0, 0, 0}};
    ariel::Graph g6(m6);

    CHECK((g3 == g4));
    CHECK((g1 == g1));
    CHECK((g6 == g5));
    CHECK((g6 == g5));

    CHECK((g1 != g2));
    CHECK((g3 != g5));
    CHECK((g4 != g6));


}
//v
TEST_CASE("Test /=")
{
    ariel::Graph g1;
    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);
    ariel::Graph g2;
    vector<vector<int>> m2 = {
            {0, 10, 1},
            {4, 0,  2},
            {1, 2,  0}};
    g2.loadGraph(m2);

    g1 /= 2;
    g2 /= 2;


    vector<vector<int>> expectedGraph1 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    vector<vector<int>> expectedGraph2 = {
            {0, 5, 0},
            {2, 0, 1},
            {0, 1, 0}};
    CHECK_EQ(g2.allEdges(), expectedGraph2);
    CHECK_EQ(g1.allEdges(), expectedGraph1);


}
//v
TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);
    ariel::Graph g2;
    vector<vector<int>> m2 = {
            {0, 1, 1, 1},
            {1, 0, 2, 1},
            {1, 2, 0, 1},
            {1, 2, 0, 0}};
    g2.loadGraph(m2);
    ariel::Graph g5;
    vector<vector<int>> m5 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g5.loadGraph(m5);


    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> m6 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0}};
    g6.loadGraph(m6);
    vector<vector<int>> m7 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0}};
    ariel::Graph g7;
    CHECK_THROWS(g1 + g6);
    CHECK_THROWS(g1 - g6);
    CHECK_THROWS(g1 += g6);
    CHECK_THROWS(g1 -= g6);
    CHECK_THROWS((g5 * g1));
    CHECK_THROWS((g1 * g2));
    CHECK_THROWS((g5 *= g1));
    CHECK_THROWS(g7.loadGraph(m7));
    CHECK_THROWS(g1 /= 0);

}