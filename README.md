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

In the Graph Manipulation Project, certain functions are declared as `friend` functions for operator overloading because they need access to the private variables of the `Graph` class, even though they don't logically belong to the `Graph` class itself. Here's why:

1. **Accessing Private Variables**:
   - Operator overloading functions like `+`, `-`, `*`, and `/` require access to the private variables of the `Graph` class to perform their operations.
   - These operators need to access the adjacency matrix or other internal data structures of the `Graph` class to carry out their functionality.

2. **Logical Association**:
   - While these operators are crucial for manipulating and interacting with graph objects, they may not logically belong as member functions of the `Graph` class.
   - For example, adding or subtracting two graphs is a binary operation that involves two graph objects. It's more intuitive to implement these operations as standalone functions rather than as member functions of one of the graph objects.

3. **Maintaining Encapsulation**:
   - Declaring these functions as `friend` allows them to access the private variables of the `Graph` class without violating encapsulation.
   - By making them `friend` functions, the Graph class explicitly grants access to these specific functions, maintaining control over which external functions can interact with its private members.

By using `friend` functions for operator overloading, the Graph Manipulation Project achieves a balance between encapsulation and functionality, ensuring that essential operations can be performed on graph objects without compromising data integrity or security.


### Algorithms

The project includes an Algorithms class that provides several graph algorithms for analysis:

- **Connectivity**: Determines whether a graph is connected.
- **Cycle Detection**: Identifies cycles within a graph.
- **Shortest Path**: Finds the shortest path between two vertices.
- **Bipartiteness Check**: Determines whether a graph is bipartite.
- **Negative Cycle Detection**: Identifies negative cycles in the graph.

## Usage

#### Running on Linux with Makefile

To run the Graph Manipulation Project on Linux using the provided Makefile, follow these steps:

2. **Compile the Source Files**:
   - Open a terminal window and navigate to the project directory.
   - Use the `make` command to compile the source files:
     ```bash
     make
     ```
   - This will generate an executable binary files named `demo` and `test`.

3. **Execute the Program**:
   - After successful compilation, run the program by executing the generated binary:
     ```bash
     ./demo
     ```
   -for running the `demo` file.
   or:
     ```bash
     ./test
     ```
   -for running the `test` file.

4. **Explore Graph Operations and Algorithms**:
   - Once the program is running, follow the on-screen instructions to interact with the graph operations and algorithms demonstrated in the `Demo.cpp` file.

By following these steps, you can easily compile and run the Graph Manipulation Project on a Linux system using the provided Makefile.

### Graph Operations

1. Create a graph instance and load data using the provided methods.
2. Perform graph manipulation operations using overloaded operators (`+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=`, `++`, `--`).
3. Utilize graph algorithms from the Algorithms class for analysis.

there are some examples in the demo file.


## Contributors

ALON SUISSA
