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

### Operator Overloading Explanation

In the Graph Manipulation Project, operator overloading is utilized to provide intuitive and concise syntax for performing graph manipulation operations. Here's an explanation of why certain functions are overloaded as member functions and why some are declared as `friend` functions:

1. **Member Functions**: 
   - Member functions are overloaded for operators that primarily operate on the internal state of the `Graph` class.
   - These operators directly manipulate the graph data structure and its properties.
   - Overloading these operators as member functions allows them to access the private members of the `Graph` class directly.

2. **Friend Functions**:
   - Friend functions are used to overload operators that require access to the private members of the `Graph` class but do not directly modify its state.
   - These operators often perform operations that involve two `Graph` objects or combine a `Graph` object with another data type.
   - By declaring them as `friend` functions, they gain access to the private members of the `Graph` class without being members of the class itself.
   - This approach maintains encapsulation while providing access to necessary internal details for specific operations.

For example:
- **Member Function Overloading**: Operators like `+=`, `-=` are overloaded as member functions because they directly modify the state of the graph object.
- **Friend Function Overloading**: Operators like `+`, `-`, `*`, `/` are overloaded as friend functions because they require access to the internal structure of the graph objects but do not directly modify their state.

By carefully selecting between member functions and friend functions for operator overloading, the Graph Manipulation Project ensures a balance between encapsulation and flexibility in utilizing operators for graph manipulation.


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
