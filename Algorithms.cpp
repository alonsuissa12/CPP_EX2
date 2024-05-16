// 211344015 alonsuissa12@gmail.com

#include "Algorithms.hpp"

#define LOG(x) std::cout << x
#define LOGln(x) std::cout << x << std::endl
using namespace ariel;

// check if the graph is connected by BFS.
int Algorithms::isConnected(Graph &g) {

    int startVertex = 0;
    if (g.isDirected()) // if it's a directed graph we will check if we can get to every vertex from every vertex
        startVertex = g.numOfVertices() - 1;

    for (int i = startVertex; i >= 0; --i) {
        // 0-unvisited, 1-visited, 2-done
        int vertexState[(unsigned int) g.numOfVertices()];

        for (int j = 0; j < g.numOfVertices(); ++j) {
            vertexState[j] = 0;
        }
        std::queue<int> q;
        vertexState[i] = 1;
        q.push(i);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            std::vector<int> neighbors = g.neighborsOf(v);
            for (int neighbor: neighbors) { //for every unvisited neighbor add it to the queue and mark it
                if (vertexState[neighbor] == 0) {
                    q.push(neighbor);
                    vertexState[neighbor] = 1;
                }
            }
            vertexState[v] = 2; //done with v
        }

        for (int j = 0; j < g.numOfVertices(); ++j) {
            // if there is a vertex that stayed unvisited the graph is not connected
            if (vertexState[j] == 0)
                return 0;
        }
    }
    return 1;

}

// a struct to implement minimum heap that's comparing by a given vector.
struct MinHeapComparator {
    const std::vector<int> *distance;

    explicit MinHeapComparator(const std::vector<int> *dist) : distance(dist) {}

    bool operator()(const int &a, const int &b) const {
        return (*distance)[(unsigned int) a] > (*distance)[(unsigned int) b];
    }
};

// a function to return and print the path from a start vertex to an end vertx in a Graph. using dijkstra/bellman-ford
// (bellman ford if the graph contains negative edges) algorithms to find the path.
std::vector<int> Algorithms::shortestPath(Graph &g, int start, int end) {

    std::vector<int> path; // answer to return
    int maxInt = std::numeric_limits<int>::max();
    std::vector<int> distance((unsigned int) g.numOfVertices(), maxInt);
    std::vector<int> prev((unsigned int) g.numOfVertices(), -1);
    distance[(unsigned int) start] = 0;

    if (!g.includeNegative()) {
        // Dijkstra
        std::priority_queue<int, std::vector<int>, MinHeapComparator> minHeap(
                (MinHeapComparator(&distance)));

        minHeap.push(start);
        std::vector<std::vector<int>> adjacencyMatrix = g.allEdges();

        while (!minHeap.empty()) {
            int curVertex = minHeap.top();
            minHeap.pop();
            for (unsigned int i = 0; i < g.numOfVertices(); ++i) {
                // if they are neighbors
                if (adjacencyMatrix[(unsigned int) curVertex][i] != 0) {

                    // if it's better to go through the current vertex
                    if (distance[(unsigned int) curVertex] + adjacencyMatrix[(unsigned int) curVertex][i] <
                        distance[i]) {

                        distance[i] = distance[(unsigned int) curVertex] + adjacencyMatrix[(unsigned int) curVertex][i];
                        prev[i] = curVertex;
                        minHeap.push((int) i);

                    }
                }
            }

        }


    } else {
        //Bellman-Ford

        std::vector<std::vector<int>> adjMatrix = g.allEdges();
        for (unsigned int i = 0; i < g.numOfVertices() - 1; ++i) {
            for (unsigned int j = 0; j < g.numOfVertices(); ++j) {
                for (unsigned int k = 0; k < g.numOfVertices(); ++k) {
                    if (adjMatrix[j][k] != 0) {
                        if (distance[j] + adjMatrix[j][k] < distance[k]) {
                            prev[k] = (int) j;
                            distance[k] = distance[j] + adjMatrix[j][k];
                        }
                    }
                }
            }
        }

        // if we still can find better way to a vertex --> there is a negative cycle
        for (unsigned int i = 0; i < g.numOfVertices(); ++i) {
            for (unsigned int j = 0; j < g.numOfVertices(); ++j) {
                if (adjMatrix[i][j] != 0 && adjMatrix[i][j] + distance[i] < distance[j]) {
                    path.push_back(-1);
                    LOGln("there is a negative cycle! no shortest path! ");
                    return path;

                }
            }
        }

    }
    int currentV = end;
    while (currentV != -1) {
        path.insert(path.begin(), currentV);
        currentV = prev[(unsigned int) currentV];
    }
    if (path.size() == 1 & end != start) {
        LOGln("there is no path! ");
        path.pop_back();
        path.push_back(-1);

    } else {
        // Print the path
        printPath(path);
        LOGln("totalWeight: " << distance[(unsigned) end]);
    }
    return path;
}

void Algorithms::printPath(std::vector<int> &path) {
    for (unsigned int i = 0; i < path.size(); ++i) {
        LOG(path[i]);
        if (i + 1 != path.size())
            LOG("-->");
        else
            LOG("\n");

    }
}

// Function to check (using DFS) if a graph contains a cycle of at least 3 vertexes
int Algorithms::isContainsCycle(Graph &g) {
    auto unsignedNumOfVertices = (unsigned int) g.numOfVertices();
    std::vector<int> visited(unsignedNumOfVertices, 0); // 0: not visited, 1: visited
    std::vector<int> timeDetection(unsignedNumOfVertices, -1); // Time of discovery
    std::vector<int> timeEnd(unsignedNumOfVertices, -1); // Time of exploration finish
    std::vector<int> prev(unsignedNumOfVertices, -1); // Previous vertex in exploration path
    int answer[2] = {-1, -1}; // Stores the start and end of the cycle if found
    int timer = 1; // Timer for discovery and finish times
    int isCycleExist = -1; // Flag indicating if a cycle is found

    for (unsigned int i = 0; i < g.numOfVertices(); i++) {
        if (!visited[i] && isCycleExist < 1) {
            isCycleExist = isContainsCycleRec(g, (int) i, &timer, &visited, &timeDetection, &timeEnd, &prev,
                                              (int *) &answer);
        }
    }

    if (isCycleExist) {
        printCycle((int *) &answer, &prev);
    }
    return isCycleExist;
}

// Recursive function to detect a cycle starting from a given vertex
int Algorithms::isContainsCycleRec(Graph &g, int start, int *timer, std::vector<int> *visited, std::vector<int> *timeDetection,
                       std::vector<int> *timeEnd, std::vector<int> *prev, int *answer) {
    auto uiStart = (unsigned int) start;
    (*timeDetection)[uiStart] = *timer;
    (*timer)++;
    (*visited)[uiStart] = 1;

    for (int neighbor: g.neighborsOf(start)) {
        auto uineighbor = (unsigned int) neighbor;
        if (!(*visited)[uineighbor]) {
            (*prev)[uineighbor] = start;
            int returnVal = isContainsCycleRec(g, neighbor, timer, visited, timeDetection, timeEnd, prev, answer);
            if (returnVal == 1) // if a cycle already found
                return 1;
        } else {
            //if we found a vertex that is neighbor of us and was detected before us and didn't finish yet
            if ((*timeEnd)[uineighbor] == -1 && neighbor != (*prev)[uiStart] &&
                (*timeDetection)[uineighbor] < (*timeDetection)[(unsigned int)start]) {
                answer[0] = neighbor;
                answer[1] = start;
                return 1;
            }
        }
    }

    (*timeEnd)[uiStart] = *timer;
    (*timer)++;
    return 0;
}

// Function to print the cycle
void Algorithms::printCycle(const int *startEnd, const std::vector<int> *prev) {
//    int curVertex = startEnd[1];
//    while (curVertex != startEnd[0]) {
//        LOG(curVertex << " --> ");
//        curVertex = (*prev)[(long unsigned int) curVertex];
//    }
//    LOGln(startEnd[0] << " --> " << startEnd[1] ;
std::vector<int> cycle;
    int curVertex = startEnd[0]; //start
    // build the cycle
    int curVOfCycle = startEnd[1]; //end
    cycle.push_back(curVertex);
    while (curVertex != curVOfCycle) {
        cycle.insert(cycle.begin(),curVOfCycle);
        curVOfCycle = (*prev)[(unsigned int) curVOfCycle];
    }
    cycle.insert(cycle.begin(),curVertex);
    //print the cycle
    printCycle(cycle);

}

// Function to print the cycle
void Algorithms::printCycle(const std::vector<int> &cycle) {
    for (unsigned int i = 0; i < cycle.size(); ++i) {
        if (1 + i < cycle.size()){
            LOG(cycle[i] << " --> ");
        } else{
            LOGln(cycle[i]);
        }
    }


}


// Function to divide the graph into two groups of vertices such that the graph is Bipartite
std::pair<std::vector<int>, std::vector<int>> Algorithms::isBipartite(Graph &g) {
    std::vector<std::vector<int>> adjacencyMatrix = g.allEdges();
    std::pair<std::vector<int>, std::vector<int>> division;
    int numVertices = g.numOfVertices();

    std::vector<int> groupA, groupB;
    std::vector<int> color((long unsigned int) numVertices, -1); // -1: not colored, 0: group A, 1: group B
    std::queue<int> q;
    for (unsigned int start = 0; start < numVertices; ++start) {
        if (color[start] == -1) {
            color[start] = 0; // start coloring from group A
            q.push((int) start);
            groupA.push_back((int) start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (unsigned int v = 0; v < numVertices; ++v) {
                    if (adjacencyMatrix[(long unsigned int) u][v] ||
                        adjacencyMatrix[v][(long unsigned int) u]) { // for bipartite we ignore direction
                        if (color[v] == -1) {
                            color[v] = 1 - color[(unsigned int) u]; // color opposite to u
                            q.push((int) v);
                            if (color[v] == 0)
                                groupA.push_back((int) v);
                            else
                                groupB.push_back((int) v);
                        } else if (color[v] == color[(unsigned int) u]) { // the graph is not Bipartite
                            std::vector<int> a = {0};
                            division = std::make_pair(a, a);
                            return division;
                        }
                    }
                }
            }
        }
    }
    division = std::make_pair(groupA, groupB);
    return division;
}

// returns a string represents the partition
std::string Algorithms::groupsToString(const std::pair<std::vector<int>, std::vector<int>> &groups) {
    std::stringstream result;
    if (groups.first[0] == 0 && groups.second[0] == 0)
        result << "The graph is not bipartite";
    else {
        std::vector<int> A = groups.first;
        std::vector<int> B = groups.second;
        result << "The graph is bipartite: A={";
        for (unsigned int i = 0; i < A.size(); ++i) {
            if (i + 1 < A.size())
                result << A[i] << ", ";
            else
                result << A[i] << "}";
        }
        result << ", B={";
        for (unsigned int i = 0; i < B.size(); ++i) {
            if (i + 1 < B.size())
                result << B[i] << ", ";
            else
                result << B[i] << "}";
        }
    }
    return result.str();
}

// prints the graph partition (if exists)
void Algorithms::printGroups(std::pair<std::vector<int>, std::vector<int>> &groups) {
    if (groups.first[0] == 0 && groups.second[0] == 0)
        LOGln("the graph is not bipartite");
    else {
        std::vector<int> A = groups.first;
        std::vector<int> B = groups.second;
        LOG("\"The graph is bipartite: A={");
        for (unsigned int i = 0; i < A.size(); ++i) {
            if (i + 1 < A.size())
                LOG(A[i] << ", ");
            else
                LOG(A[i] << "}");
        }
        LOG(", B={");
        for (unsigned int i = 0; i < B.size(); ++i) {
            if (i + 1 < B.size())
                LOG(B[i] << ", ");
            else
                LOG(B[i] << "}\n");
        }
    }
}

std::vector<int> Algorithms::negativeCycle(Graph &g) {
    auto numOfVertices = (unsigned int) g.numOfVertices();


    std::vector<int> negCycle; //answer to return
    if (!g.includeNegative()) {
        negCycle.push_back(-1);
        LOGln("there is no negative cycle");
        return negCycle;
    } else {
        // Step 1: Add a demo vertex and edges with weight 0
        std::vector<std::vector<int>> adjMatrix = g.allEdges();

        // Resize the adjacency matrix to (numOfVertices + 1) x (numOfVertices + 1)
        adjMatrix.resize(numOfVertices + 1, std::vector<int>(numOfVertices + 1, 0));

        std::vector<int> distance(numOfVertices + 1, 0);
        std::vector<int> prev(numOfVertices + 1, (int) numOfVertices);

        // Bellman-Ford
        for (unsigned int i = 0; i < numOfVertices - 1; ++i) {
            for (unsigned int j = 0; j < numOfVertices; ++j) {
                for (unsigned int k = 0; k < numOfVertices; ++k) {
                    if (adjMatrix[j][k] != 0 || j == numOfVertices) {
                        if (distance[j] + adjMatrix[j][k] < distance[k]) {
                            prev[k] = (int) j;
                            distance[k] = distance[j] + adjMatrix[j][k];
                        }
                    }
                }
            }
        }
        int curVertex = -1;
        // if we still can find better way to a vertex --> there is a negative cycle
        for (unsigned int i = 0; i < numOfVertices; ++i) {
            for (unsigned int j = 0; j < numOfVertices; ++j) {

                if (adjMatrix[i][j] != 0 && adjMatrix[i][j] + distance[i] < distance[j])
                    curVertex = (int) i;
            }
        }

        if (curVertex == -1) { // no negative cycle
            negCycle.push_back(-1);
            LOGln("there is no negative cycle");
            return negCycle;
        }
        auto iulCurVertex = (unsigned int) curVertex;
        // retrieve back n times to find a vertex in the negative circle
        for (int i = 0; i < numOfVertices; ++i) {
            curVertex = prev[iulCurVertex];
        }
        // build the cycle
        int curVOfCycle = prev[(unsigned int) curVertex];
        negCycle.push_back(curVertex);
        while (curVertex != curVOfCycle) {
            negCycle.insert(negCycle.begin(),curVOfCycle);
            curVOfCycle = prev[(unsigned int) curVOfCycle];
        }
        negCycle.insert(negCycle.begin(),curVertex);
        //print the cycle
        LOG("there is a negative cycle: ");
        printCycle(negCycle);

        return negCycle;

    }
}


