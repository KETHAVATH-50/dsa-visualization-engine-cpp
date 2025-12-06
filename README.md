# C++17 Algorithm Execution Tracer

I made this while going over basic graph and sorting algorithms. I felt like using a debugger didn’t really show what was happening in the algorithm (like how the BFS queue grows or how quicksort picks pivots). So I wrote a simple tracer that prints the important steps to the terminal. Nothing fancy, just something that helped me understand things better.

## Design Notes

### 1. Keeping the algorithms clean
The algorithms themselves don’t print anything. They only send small “events” like Swap(i, j) or PushToQueue(node). Then the logger prints them. This made the algorithm code easier for me to read and test.

### 2. Only logging useful steps
Instead of printing whole arrays or lists every time, I only log the parts that actually matter:
- when something gets pushed into the BFS queue
- when quicksort does a partition
- when an edge gets relaxed in dijkstra
- swaps in the sorting algorithms

It keeps the output shorter and easier to follow.

### 3. Only C++17
I didn’t use any libraries besides the STL.

## Algorithms Included

**Graphs**
- bfs
- dfs
- Dijkstra

**Sorting**
- quicksort
- mergesort
- heapsort
- bubble sort

## Building and Running

Needs a C++17 compiler and make.

To build:
```bash
make
```

### General Command Line Format

The program takes the algorithm type, the input file, and a speed setting.

```
./dsa_visualize [category] [input_file] [speed]
```

Example:
```
./dsa_visualize bfs samples/graph1.txt normal
```

For sorting, there is one extra argument for the sorting method:
```
./dsa_visualize sort quick samples/arr1.txt fast
```

Speed modes: slow, normal, fast, none

## Input Formats

Graph (u v edges):
```
0 1
0 2
1 3
2 3
3 4
```

Array:
```
5 2 9 1 5 6
```
## Project Layout

```
dsa-visualize-cpp/
  src/
    main.cpp
    logger.cpp
    logger.h
    graph.cpp
    graph.h
    sort.cpp
    sort.h
  samples/
    graph1.txt
    arr1.txt
  Makefile
  README.md
```

## Things I might add later
- A* search
- json event output (for maybe a web ui later)
- a mode that pauses after each event so you can step manually
