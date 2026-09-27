# Maze Path Finder & Rescue Planning System

A Data Structures-I course project developed in C++ that represents a maze as a graph and demonstrates multiple data structures and algorithms through a practical route-finding application.

## 📌 Project Overview

The **Maze Path Finder & Rescue Planning System** is a menu-driven C++ application that models a maze as a graph and provides different methods to explore the maze and find routes.

The project demonstrates important Data Structures-I concepts including:

- Graphs
- DFS
- BFS
- Dijkstra's Algorithm
- Priority Queue / Min Heap
- Linked List
- Hash Table
- Binary Search Tree
- Merge Sort
- Quick Sort
- 2D Arrays
- Recursion
- Queues

Instead of implementing each data structure as an isolated program, the project combines them into one practical maze navigation system.

---

## 🎯 Objectives

- Represent a maze using a two-dimensional array.
- Convert the maze into a graph using an adjacency list.
- Explore the maze using DFS and BFS.
- Find minimum-cost routes using Dijkstra's Algorithm.
- Reconstruct and display the discovered paths.
- Store route history using a linked list.
- Search route information using hashing.
- Search route information using a Binary Search Tree.
- Sort stored routes using Merge Sort and Quick Sort.
- Compare BFS and Dijkstra based on number of moves and route cost.
- Display project statistics and algorithm complexity.

---

## 🧩 Data Structures and Algorithms

| Data Structure / Algorithm | Application |
|---|---|
| 2D Array | Maze representation |
| Graph | Representation of maze connectivity |
| Adjacency List | Primary graph representation |
| DFS | Depth-first maze exploration |
| BFS | Breadth-first exploration and unweighted shortest path |
| Queue | BFS traversal |
| Recursion | DFS traversal |
| Dijkstra | Minimum-cost path finding |
| Priority Queue / Min Heap | Dijkstra processing |
| Linked List | Route history |
| Hash Table | Fast route lookup |
| Binary Search Tree | Route searching |
| Merge Sort | Sorting routes by cost |
| Quick Sort | Sorting routes by number of moves |

---

## 🗺️ Maze Representation

The maze is represented using a 2D grid.

### Cell Encoding

| Value | Meaning |
|---|---|
| `0` | Normal path, cost 1 |
| `1` | Wall / blocked cell |
| `2` | Source |
| `3` | Destination |
| `4` | Checkpoint |
| `6` | Difficult path, cost 2 |
| `7` | Hazard path, cost 5 |
| `*` | Displayed path |

Example:

```text
S . 2 # . . .
# # 2 # . # .
. . . . 2 # .
. # # # 2 # .
. . . . 5 . .
. # # # # # .
. . . . . . D
````

Where:

* `S` = Source
* `D` = Destination
* `#` = Wall
* `.` = Normal path
* `2` = Difficult path
* `5` = Hazard path
* `*` = Calculated route

---

## ⚙️ Main Features

### 1. Maze Display

Displays the current maze and identifies different cell types.

### 2. Graph Construction

Converts walkable maze cells into graph vertices and connects adjacent cells using an adjacency list.

### 3. DFS Traversal

Uses recursive Depth First Search to explore the maze and determine whether the destination can be reached.

### 4. BFS Traversal

Uses a queue to explore the maze level by level.

BFS also reconstructs and displays the path from the source to the destination.

### 5. Dijkstra's Algorithm

Finds a minimum-cost route when different cells have different movement costs.

The project uses a priority queue to process vertices according to their current minimum cost.

### 6. Route Visualization

The calculated BFS path can be displayed directly on the maze.

### 7. Route History

Completed BFS and Dijkstra routes are stored using a linked list.

Each route stores:

* Route ID
* Algorithm
* Number of moves
* Total cost
* Path

### 8. Hash Table

A hash table with linear probing is used to store and search route information.

### 9. Binary Search Tree

A Binary Search Tree is used to store route information and perform route searches.

### 10. Route Sorting

Routes can be sorted using:

* **Merge Sort** — by total cost
* **Quick Sort** — by number of moves

### 11. Route Comparison

The system compares BFS and Dijkstra routes using:

* Number of moves
* Total weighted cost

### 12. Project Statistics

The application displays:

* Maze dimensions
* Number of cells
* Number of vertices
* Number of walls
* Normal cells
* Difficult cells
* Hazard cells
* Source and destination
* Stored routes
* Algorithm complexity
* Data structures used

---

## 🏗️ Project Architecture

```text
                 +----------------------+
                 |      Main Menu       |
                 |      User Input      |
                 +----------+-----------+
                            |
                            v
                 +----------------------+
                 |        Maze          |
                 |     2D Array/Grid    |
                 +----------+-----------+
                            |
                            v
                 +----------------------+
                 |  Graph Construction  |
                 |    Adjacency List    |
                 +----------+-----------+
                            |
              +-------------+-------------+
              |             |             |
              v             v             v
          +-------+      +-------+   +-----------+
          |  DFS  |      |  BFS  |   | Dijkstra  |
          |Recursion|    | Queue |   | Priority  |
          +---+---+      +---+---+   |   Queue   |
              |              |        +-----+-----+
              |              |              |
              +--------------+--------------+
                             |
                             v
                  +----------------------+
                  |    Route History     |
                  |     Linked List      |
                  +----------+-----------+
                             |
                  +----------+-----------+
                  |                      |
                  v                      v
            +-----------+          +-----------+
            | Hash Table|          |    BST    |
            |  Search   |          |  Search   |
            +-----------+          +-----------+
                  |
                  v
            +-----------+
            |  Sorting  |
            | Merge/Quick|
            +-----------+
```

---

## 📁 Project Structure

```text
Maze-Path-Finder-
│
├── README.md
├── .gitignore
│
├── src/
│   ├── main.cpp
│   ├── Maze.cpp
│   ├── Maze.h
│   ├── Graph.cpp
│   ├── Graph.h
│   ├── RouteHistory.cpp
│   ├── RouteHistory.h
│   ├── RouteHash.cpp
│   ├── RouteHash.h
│   ├── RouteBST.cpp
│   ├── RouteBST.h
│   ├── RouteSorter.cpp
│   └── RouteSorter.h
│
├── data/
├── screenshots/
├── docs/
└── report/
```

---

## 🚀 How to Run

### Requirements

* C++ compiler
* VS Code or another C++ IDE
* Git

### Compile

Open the terminal in the project root directory and run:

```bash
g++ src/main.cpp src/Maze.cpp src/Graph.cpp src/RouteHistory.cpp src/RouteHash.cpp src/RouteBST.cpp src/RouteSorter.cpp -o maze
```

### Run on Windows

```powershell
.\maze.exe
```

### Run on Linux/macOS

```bash
./maze
```

---

## 🖥️ Main Menu

The application provides the following options:

```text
1. Display Maze
2. Display Graph
3. Run DFS
4. Run BFS
5. Run Dijkstra
6. Display Route History
7. Display Hash Table
8. Search Route using Hashing
9. Display BST
10. Search Route using BST
11. Sort Routes by Cost
12. Sort Routes by Moves
13. Display Project Statistics
14. Compare BFS and Dijkstra
0. Exit
```

---

## 📊 Complexity Analysis

| Algorithm / Operation     | Complexity                      |
| ------------------------- | ------------------------------- |
| Maze traversal            | O(R × C)                        |
| DFS                       | O(V + E)                        |
| BFS                       | O(V + E)                        |
| Dijkstra with binary heap | O((V + E) log V)                |
| Hash Search               | Average O(1)                    |
| BST Search                | Average O(log V), Worst O(V)    |
| Merge Sort                | O(n log n)                      |
| Quick Sort                | Average O(n log n), Worst O(n²) |
| Heap operation            | O(log n)                        |

Where:

* `V` = number of vertices
* `E` = number of edges
* `R` = number of maze rows
* `C` = number of maze columns
* `n` = number of routes

---

## 🔬 BFS vs Dijkstra

The project demonstrates the difference between unweighted and weighted path finding.

### BFS

BFS focuses on finding a path with the minimum number of moves in an unweighted graph.

### Dijkstra

Dijkstra focuses on finding a path with the minimum total weighted cost.

For the current sample maze:

```text
BFS
Moves: 12
Cost: 20

Dijkstra
Moves: 16
Cost: 18
```

This demonstrates that a route with fewer moves does not necessarily have the minimum weighted cost.

---

## 🧪 Testing

The implemented system has been tested for:

* DFS traversal
* BFS traversal
* BFS path reconstruction
* Dijkstra minimum-cost path
* Graph adjacency list
* Route history
* Hash table insertion and display
* Hash table search
* Hash search for unavailable route
* BST insertion and display
* BST search
* BST search for unavailable route
* Merge Sort by cost
* Quick Sort by moves
* Project statistics
* BFS vs Dijkstra comparison

---

## 🔮 Future Scope

Possible future improvements include:

* Graphical user interface
* User-defined maze input
* Loading maze layouts from files
* Eight-direction movement
* A* path-finding algorithm
* Multiple rescuers
* Multiple starting points
* Dynamic obstacles
* Step-by-step visualization of algorithms
* More advanced rescue planning features

---

## 📚 Topics Covered

This project demonstrates practical applications of:

* Arrays
* Pointers
* Recursion
* Linked Lists
* Queues
* Hashing
* Trees / BST
* Heaps
* Sorting
* Graphs
* DFS
* BFS
* Dijkstra's Algorithm
* Algorithm Complexity

---

## 👨‍💻 Project Information

**Course:** Data Structures-I

**Language:** C++

**Project:** Maze Path Finder & Rescue Planning System

**Project Type:** Academic Course Project

---

## 📌 Project Status

**Core implementation completed and tested.**

The current version includes maze representation, graph construction, DFS, BFS, Dijkstra, route history, hashing, BST, sorting, statistics, and route comparison.

```


