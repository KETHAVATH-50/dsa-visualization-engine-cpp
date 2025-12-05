# 📊 DSA Visualization Engine (C++17)

A modular, production-style C++17 command-line engine that **visualizes the internal execution steps** of classical Data Structures & Algorithms.

It supports:
- **Graph Algorithms:** BFS, DFS, Dijkstra
- **Sorting Algorithms:** Bubble Sort, Quick Sort, Merge Sort, Heap Sort  
- **Step-by-step logging**, **speed control**, and a **clean multi-module architecture**

---

## 🚀 Features
- 🔍 **Real-time step visualization** (each operation logged clearly)
- 📦 **Modular architecture** (graph, sorting, logger, main)
- 🎚 **Speed modes:** `slow`, `normal`, `fast`, `none`
- 🧩 **Clean C++17 STL-based design**
- 📂 **File-based input** for graphs & arrays
- 🧠 Great for **learning**, **debugging**, and **interviews**

---

## 📁 Project Structure
```
dsa-visualization-engine-cpp/
├── src/
│   ├── main.cpp
│   ├── logger.cpp / logger.h
│   ├── graph.cpp  / graph.h
│   ├── sort.cpp   / sort.h
├── samples/
│   ├── graph1.txt
│   └── arr1.txt
├── Makefile
└── README.md
```

---

## 🛠 Build
```bash
make clean
make
```

---

## 🧪 Usage

### ▶ Run BFS
```bash
./dsa_visualize bfs samples/graph1.txt 0 normal
```

### ▶ Run DFS
```bash
./dsa_visualize dfs samples/graph1.txt 0 fast
```

### ▶ Run Dijkstra (unit weights)
```bash
./dsa_visualize dijkstra samples/graph1.txt 0 normal
```

---

## 🔧 Sorting Algorithms

### Bubble Sort
```bash
./dsa_visualize sort bubble samples/arr1.txt slow
```

### Quick Sort
```bash
./dsa_visualize sort quick samples/arr1.txt fast
```

### Merge Sort
```bash
./dsa_visualize sort merge samples/arr1.txt normal
```

### Heap Sort
```bash
./dsa_visualize sort heap samples/arr1.txt normal
```

---

## 📄 Input File Formats

### Graph (directed edges)
```
u v
```
Example:
```
0 1
0 2
1 3
3 4
```

### Array (space separated)
```
5 2 9 1 5 6
```

---

## 🧱 Architecture Overview

### 📝 Logger Module
- Step counter  
- Delay control  
- Message formatting  

### 🔗 Graph Module
- BFS with queue tracing  
- DFS with recursion tracking  
- Dijkstra with PQ + relax logs  

### 🔢 Sorting Module
- Bubble Sort (compare/swap)
- Quick Sort (partition logging)
- Merge Sort (merge writes)
- Heap Sort (heapify + extract)


---

## ✨ Author
**Kethavath Siddu**  
IIT Kharagpur — Computer Science & Engineering

---

