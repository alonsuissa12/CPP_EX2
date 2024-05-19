# Graph Manipulation Project

## Overview

This project implements a Graph data structure along with various operations for manipulation and analysis. The primary goal is to provide a flexible and efficient tool for working with graphs, allowing users to perform tasks such as graph addition, subtraction, multiplication, division, finding cycles, checking connectivity, and more.

## Implementation

### Graph Structure

The Graph class is the core component of this project. It is implemented using an adjacency matrix representation for efficient edge lookups and modifications. Key features of the Graph class include:

- **Constructor**: Supports the creation of an empty graph or initialization from a provided adjacency matrix.
- **Edge Manipulation**: Allows loading new data into the graph, accessing neighbors of a vertex, and retrieving the adjacency matrix.
- **Graph Properties**: Provides methods to determine whether the graph is directed, weighted, or contains negative edges.
- **Operator Overloading**: Implements various operators for graph manipulation, such as addition, subtraction, multiplication, and division. Unary operators for negation and increment/decrement are also supported.

### Algorithms

The project includes an Algorithms class that provides several graph algorithms for analysis:

- **Connectivity**: Determines whether a graph is connected.
- **Cycle Detection**: Identifies cycles within a graph.
- **Shortest Path**: Finds the shortest path between two vertices.
- **Bipartiteness Check**: Determines whether a graph is bipartite.
- **Negative Cycle Detection**: Identifies negative cycles in the graph.

## Usage

### Running the Project

To run the project, compile the provided source files (`Graph.hpp`, `Graph.cpp`, `Algorithms.hpp`, `Demo.cpp`) using a C++ compiler. Execute the compiled binary to see the demonstration of various graph operations and algorithms.

### Graph Operations

1. Create a graph instance and load data using the provided methods.
2. Perform graph manipulation operations using overloaded operators (`+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=`, `++`, `--`).
3. Utilize graph algorithms from the Algorithms class for analysis.

## File Structure

The project consists of the following files:

- `Graph.hpp`: Header file containing the declaration of the Graph class.
- `Graph.cpp`: Source file implementing the functionalities of the Graph class.
- `Algorithms.hpp`: Header file containing declarations of graph algorithms.
- `Demo.cpp`: Source file demonstrating the usage of the graph operations and algorithms.

## Contributors

[Your Name]: [Your Email]

## License

[Include License Information]

Feel free to adjust the README according to your preferences and project details.
