# Aristotle's Puzzle Solver
 Highly optimized C++ implementation designed to solve Aristotle's Puzzle efficiently. 

![image](https://github.com/FelixCenusa/Aristotles-Puzzle-Solver/blob/main/asssets/img/AristotlesPuzzleAndMath.jpg)

## Table of Contents
- [Introduction](#introduction)
- [Project Overview](#project-overview)
- [Features](#features)
- [Mathematical Foundation](#mathematical-foundation)
- [Optimization and Complexity](#optimization-and-complexity)
- [Custom Linked List Implementation](#custom-linked-list-implementation)
- [Python to C++ Transition](#python-to-c-transition)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)
- [Gif of program running](#gif-of-program-running)

## Introduction

Welcome to the Aristotle's Puzzle Solver project! This is a highly optimized C++ implementation designed to solve Aristotle's Puzzle efficiently. The project showcases, algorithmic optimizations, custom data structures, object orientation and scalability all aimed at delivering results quickly.

## Project Overview

Aristotle's Puzzle is a classic mathematical problem that involves arranging objects in such a way so that every diagonal sums up to 38. There are a total of 15 diagonals, 5 in each of the three angles you can look at the puzzle. The solver implemented here is designed to find the solution to the puzzle in a minimal amount of time. 

This project originally started as a Python script, but due to the high computational complexity, it was later rewritten in C++ to achieve significant performance improvements.

## Features

- **Efficient C++ implementation**: Drastically reduces execution time from hours to under a second.
- **Custom Linked List**: A self-implemented linked list that accelerates the solving process.
- **Mathematical rigor**: Algorithm written with best solution time oriented mathematics.
- **Scalability**: Designed to handle larger or more complex variants of Aristotle's Puzzle, or variations of it such as calculating a different sum or having different numbers to choose from.
- **Debug printing:** variable debugPrinting can be set to true to see the solution being slowly built. This will affect performance.


## Mathematical Foundation

The puzzle is rooted in combinatorial mathematics. The solver relies on the principles of permutation and backtracking to explore all possible arrangements and validate them against the rules of the puzzle. Given the exponential growth of possible configurations, optimizing the exploration process was crucial. I calculated that the problem space consists of 257,402,880 possible combinations. This is derived from the following multiplication of choices: (19 * 18 * 16 * 14 * 12 * 10 * 7 * 4). Each factor represents the number of valid options available at each step in the puzzle's sequence, (there are "missing" numbers because we get them for "free" when calculating the sum) and the product gives the total number of configurations that need to be explored to find a solution in the worst case scenario.
## Optimization and Complexity

The initial Python implementation, while functional, took several hours to find a solution due to the sheer number of permutations. By rewriting the solver in C++, I reduced the runtime to under a second. This was achieved through:
- **Efficient memory management**: Leveraging C++'s control over memory allocation and deallocation.
- **Algorithmic improvements**: Optimizing the backtracking algorithm and pruning unnecessary branches early.
- **Using best data types**: Home-made linkedList for quick access and storage to the first index, and vectors for where indexing was more important.
- **State Exploration**: Systematically explores potential states using a depth-first search (DFS) approach and prunes mathematically impossible branches.

### Time Complexity

- **Python Implementation**: O(n!) due to the brute-force permutation generation. (admittedly, because I first tried to choose every number randomly)
- **C++ Implementation**: Optimized to approximately O(√k) through custom data structures and strategic pruning of both the solution space and of mathematically known to be impossible branches.
- **Space complexity:** O(n)
	

## Custom Linked List Implementation

A significant part of the optimization came from the custom linked list I implemented. Unlike standard library implementations, my linked list was tailored specifically for the needs of the puzzle solver:

- **Speed**: The custom linked list significantly speeds up node insertion, deletion, and traversal.
- **Memory Efficiency**: Optimized memory management reduces the overall footprint of the program, allowing it to handle larger datasets without slowing down.
## Python to C++ Transition

The initial version of this project was developed in Python. While Python's simplicity allowed for quick prototyping, it became apparent that performance was a critical issue. The C++ version was created to address these concerns:
- **Python Version**: Simple and readable, but inefficient for large-scale computations.
- **C++ Version**: Highly optimized, leveraging low-level memory management and custom data structures.

The transition to C++ resulted in a dramatic performance improvement, reducing the runtime from several hours to under a second.

## Future Enhancements

While the current implementation is highly optimized, there is always room for improvement. Possible future enhancements include:

- **Parallel Processing**: Implementing multi-threading to further speed up the computation by taking advantage of multi-core processors.
- **Heuristic Optimization**: Incorporating more heuristic-based approaches to reduce the search space even more effectively.
- **GUI Integration**: Adding a graphical user interface to make the solver more user-friendly and accessible to a broader audience.

## Contributing

Contributions are welcome! If you have ideas for improvements, feel free to fork the repository and submit a pull request. :)


## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Gif Of Program Running
- ![gif](https://github.com/FelixCenusa/Aristotles-Puzzle-Solver/blob/main/asssets/gif/480p2xAristotlesGif.gif)
