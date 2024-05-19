# Graph Library

The Graph Library is a C++ library for handling graphs, providing functionalities for creating, manipulating, and analyzing graphs. This README file provides an overview of the library, its functionalities, implementation decisions, and instructions on how to use it.

## Table of Contents
- [Introduction](#introduction)
- [Implementation](#implementation)
- [Operator Overloading](#operator-overloading)
- [How to Use](#how-to-use)
- [Conclusion](#conclusion)

## Introduction

The Graph Library is designed to handle various types of graphs, including directed and undirected, weighted and unweighted, with or without cycles. It provides functionalities for creating graphs, loading data into them, performing operations like addition, subtraction, multiplication, and division on graphs, checking connectivity, finding cycles, finding the shortest path, and determining bipartiteness.

## Implementation

The library is implemented using C++ and consists of three main components:

1. **Graph.hpp**: This header file defines the `Graph` class along with its member functions and operator overloads. It includes functionalities for creating a graph, loading data into it, printing the graph, checking properties like directedness, weightedness, and presence of negative edges, and performing various operations on graphs.

2. **Graph.cpp**: This source file contains the implementation of the member functions and operator overloads defined in `Graph.hpp`. It includes constructors, destructor, methods for loading data, checking properties, performing operations like addition, subtraction, multiplication, and division, and overloads the stream insertion operator for printing graphs.

3. **Algorithms.hpp**: This header file defines the `Algorithms` class, which includes static methods for performing various algorithms on graphs such as checking connectivity, finding cycles, finding the shortest path, determining bipartiteness, and identifying negative cycles.

## Operator Overloading

The `Graph` class overloads several operators to provide intuitive functionality for graph manipulation:

- **`+=`, `-=`, `*=`, `/=`**: These operators are overloaded to perform addition, subtraction, multiplication, and division operations on graphs respectively. They allow modifying the weights of edges in the graph.

- **Unary `+` and `-`**: Unary operators `+` and `-` are overloaded to provide functionality for obtaining the absolute values of graph edge weights and negating them respectively.

- **Binary `+` and `-`**: Binary operators `+` and `-` are overloaded to perform addition and subtraction operations between two graphs. These operators facilitate combining or subtracting the edge weights of two graphs.

- **Comparison Operators**: Various comparison operators (`<`, `>`, `==`, `!=`, `<=`, `>=`) are overloaded to compare graphs based on their adjacency matrices (containity), number of edges, and number of vertices.

## How to Use

To use the Graph Library in your project, follow these steps:

1. Include the `Graph.hpp` header file in your source files.
2. Create instances of the `Graph` class and load data into them using the provided methods.
3. Perform operations on graphs using the overloaded operators or by calling the member functions of the `Graph` class.
4. Utilize the `Algorithms` class to perform various graph algorithms like connectivity checking, cycle detection, shortest path finding, etc.

## Conclusion

The Graph Library provides a comprehensive set of functionalities for handling graphs efficiently in C++. Whether you need to create, manipulate, or analyze graphs, this library offers intuitive interfaces and powerful algorithms to simplify your tasks.

For more detailed usage instructions and examples, refer to the documentation and demo files provided with the library.
