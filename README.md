# Maze-Path-Finder-
Maze Path Finder and Rescue Planning System using Data Structures in C++
# Maze Path Finder & Rescue Planning System

A Data Structures-I course project developed in C++ that uses a maze environment to demonstrate and apply important data structures and algorithms.

## 📌 Project Overview

The **Maze Path Finder & Rescue Planning System** is a menu-driven C++ application that represents a maze as a graph and provides different methods to explore the maze, find routes, compare routes, and simulate rescue-oriented navigation.

The project is designed to demonstrate Data Structures-I concepts through one practical application instead of implementing each data structure as an isolated program.

## 🎯 Objectives

* Represent a maze using a two-dimensional array.
* Represent the maze as a graph.
* Explore the maze using **DFS** and **BFS**.
* Find shortest/minimum-cost paths using **Dijkstra's Algorithm**.
* Reconstruct and display the selected path.
* Maintain route history using a linked list.
* Use hashing for fast coordinate/route lookup.
* Use a Binary Search Tree for route/checkpoint searching.
* Rank routes using sorting algorithms.
* Use a min-heap/priority queue for shortest-path processing.
* Analyze the time complexity of the implemented algorithms.

## 🧩 Data Structures and Algorithms

| Data Structure / Algorithm | Application                                         |
| -------------------------- | --------------------------------------------------- |
| 2D Array                   | Maze representation                                 |
| Graph                      | Representation of connections between cells         |
| Adjacency List             | Primary graph representation                        |
| Adjacency Matrix           | Graph representation demonstration                  |
| DFS                        | Deep exploration of the maze                        |
| BFS                        | Level-wise exploration and unweighted shortest path |
| Stack                      | Path reconstruction and DFS                         |
| Queue                      | BFS traversal                                       |
| Dijkstra                   | Minimum-cost path finding                           |
| Min Heap                   | Priority queue for Dijkstra                         |
| Linked List                | Route history                                       |
| Hash Table                 | Fast lookup of coordinates/routes                   |
| BST                        | Route/checkpoint search                             |
| Merge Sort                 | Route ranking                                       |
| Quick Sort                 | Route ranking and comparison                        |

## 🗺️ Maze Representation

The maze is represented using a grid.

```text
S 0 0 1 0
1 0 0 1 0
0 0 1 0 0
0 1 0 0 0
0 0 0 1 D
```

Where:

* `S` = Source
* `D` = Destination
* `0` = Open/walkable cell
* `1` = Wall/blocked cell
* `4` = Optional checkpoint
* `5` = Final path

## ⚙️ Main Features

### 1. Maze Creation

Create or load a maze and define the source and destination.

### 2. Maze Validation

Check whether the maze and source/destination positions are valid.

### 3. Graph Construction

Convert walkable maze cells into graph vertices and connect adjacent cells.

### 4. DFS Exploration

Explore the maze using Depth First Search.

### 5. BFS Exploration

Explore the maze level by level using Breadth First Search.

### 6. Dijkstra Shortest Path

Find a minimum-cost route when different cells have different movement costs.

### 7. Path Reconstruction

Reconstruct the final path from the destination back to the source.

### 8. Route History

Store completed routes using a linked list.

### 9. Fast Search

Use hashing and a Binary Search Tree for searching stored route/checkpoint information.

### 10. Route Ranking

Sort routes according to distance or cost using sorting algorithms.

## 🏗️ Project Architecture

```text
                +----------------------+
                |    Menu / User Input |
                +----------+-----------+
                           |
                           v
                +----------------------+
                |     Maze Manager     |
                |    2D Array/Grid     |
                +----------+-----------+
                           |
                           v
                +----------------------+
                |    Graph Builder     |
                | Adjacency List/Matrix|
                +----------+-----------+
                           |
              +------------+------------+
              |                         |
              v                         v
        +-----------+             +-------------+
        | DFS / BFS |             |  Dijkstra   |
        |Stack/Queue|             |  + Min Heap |
        +-----+-----+             +------+------+
              |                          |
              +------------+-------------+
                           |
                           v
                +----------------------+
                |    Route Manager     |
                | Stack + Linked List  |
                +----------+-----------+
                           |
                           v
                +----------------------+
                | Search / Analysis    |
                | Hash + BST + Sorting |
                +----------------------+
```

## 📁 Project Structure

```text
Maze-Path-Finder/
│
├── README.md
│
├── src/
│   ├── main.cpp
│   ├── Maze.cpp
│   ├── Maze.h
│   ├── Graph.cpp
│   ├── Graph.h
│   ├── BFS.cpp
│   ├── BFS.h
│   ├── DFS.cpp
│   ├── DFS.h
│   ├── Dijkstra.cpp
│   ├── Dijkstra.h
│   ├── MinHeap.cpp
│   ├── MinHeap.h
│   ├── Stack.cpp
│   ├── Stack.h
│   ├── LinkedList.cpp
│   ├── LinkedList.h
│   ├── HashTable.cpp
│   ├── HashTable.h
│   ├── BST.cpp
│   ├── BST.h
│   ├── Sorting.cpp
│   └── Sorting.h
│
├── data/
│   └── mazes.txt
│
├── screenshots/
│
├── docs/
│
└── report/
```

> The project structure will be updated as new modules are implemented.

## 🚀 How to Run

### Requirements

* C++ compiler
* VS Code or any C++ IDE
* Git

### Compile

From the project root directory:

```bash
g++ src/main.cpp -o maze
```

### Run

On Windows:

```bash
maze.exe
```

On Linux/macOS:

```bash
./maze
```

## 📊 Complexity Analysis

The project will analyze the complexity of the major algorithms.

| Algorithm                  | Typical Complexity              |
| -------------------------- | ------------------------------- |
| Maze Traversal             | O(R × C)                        |
| DFS                        | O(V + E)                        |
| BFS                        | O(V + E)                        |
| Dijkstra + Binary Min Heap | O((V + E) log V)                |
| Hash Table Lookup          | Average O(1)                    |
| BST Search                 | Average O(log V), Worst O(V)    |
| Merge Sort                 | O(n log n)                      |
| Quick Sort                 | O(n log n) average, O(n²) worst |
| Heap Insert/Remove         | O(log n)                        |

## 🧪 Testing

The project will be tested using different maze conditions, including:

* Source and destination being the same.
* No possible path between source and destination.
* Open maze.
* Multiple possible routes.
* Mazes containing cycles.
* Isolated regions.
* Single-row and single-column mazes.
* Minimum-size mazes.
* Hash collisions.
* BST search and deletion.
* Sorting routes with duplicate costs.

## 🔮 Future Scope

Possible future enhancements include:

* Graphical user interface.
* Eight-direction movement.
* A* path-finding algorithm.
* Multiple rescuers.
* Multiple starting points.
* Dynamic obstacles.
* Importing maze layouts from files.
* Step-by-step visualization of BFS, DFS and Dijkstra.

## 👨‍💻 Project Information

**Course:** Data Structures-I
**Language:** C++
**Project:** Maze Path Finder & Rescue Planning System
**Project Type:** Academic Course Project

## 📚 Topics Covered

This project demonstrates practical applications of:

* Arrays
* Pointers and Dynamic Memory
* Recursion
* Linked Lists
* Stacks
* Queues
* Hashing
* Trees / BST
* Heaps
* Sorting
* Graphs
* BFS
* DFS
* Dijkstra's Algorithm

## 📌 Development Approach

The project is being developed incrementally.

The core path-finding functionality will be implemented first, followed by supporting data structures and additional analysis features.

---

**Status:** 🚧 In Development

