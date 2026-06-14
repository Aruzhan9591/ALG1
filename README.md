# ALG1
# Bipartite Graph Detection

## Overview

This project was developed as part of the **Algorithms I** course at VSB – Technical University of Ostrava.

The program determines whether a given graph is bipartite. The graph is loaded from an input file in the form of an adjacency matrix, and a Breadth-First Search (BFS) algorithm is used to verify whether the vertices can be divided into two disjoint sets such that no edge connects vertices within the same set.

## Features

* Loading graphs from text files
* Representation using an adjacency matrix
* Bipartite graph verification
* Breadth-First Search (BFS) implementation
* Support for multiple test files
* Console output of results

## Technologies Used

* C++
* Object-Oriented Programming
* Graph Theory
* Breadth-First Search (BFS)
* Makefile
* Doxygen

## Project Structure

```text
main.cpp      - Program entry point and command-line processing
graph.cpp     - Graph implementation and BFS algorithm
graph.h       - Graph class declaration
Makefile      - Build configuration
Doxyfile      - Documentation configuration
*.txt         - Test graph files
```

## Compilation

Compile the project using:

```bash
make
```

Or manually:

```bash
g++ -Wall -Wextra -pedantic -std=c++17 -c main.cpp
g++ -Wall -Wextra -pedantic -std=c++17 -c graph.cpp
g++ -Wall -Wextra -pedantic -std=c++17 main.o graph.o -o bipartite
```

## Usage

Run the program with a graph file:

```bash
./bipartite graph.txt
```

Example:

```bash
./bipartite BipartiteGraph1.txt
```

The program displays the adjacency matrix and reports whether the graph is bipartite.

## Documentation

Generate project documentation using Doxygen:

```bash
doxygen Doxyfile
```

The generated documentation can be found in:

```text
html/index.html
```

## Learning Outcomes

Through this project, I gained experience in:

* Graph algorithms
* Breadth-First Search (BFS)
* Graph traversal techniques
* Object-oriented programming in C++
* Software documentation with Doxygen
* Building projects using Makefiles

## Author

**Aruzhan Abilmazhinova**

Bachelor's Degree in Computational and Applied Mathematics

Faculty of Electrical Engineering and Computer Science (FEI)

VSB – Technical University of Ostrava
