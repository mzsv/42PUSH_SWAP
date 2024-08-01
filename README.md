# Push_swap: Sorting Algorithm Project

## Table of Contents

1. [Overview](#overview)
2. [Objectives](#objectives)
3. [Features](#features)
4. [How to use](#how-to-use)
5. [References](#references)
6. [Author](#author)
5. [Acknowledgments](#acknowledgments)

## 1. Overview

Push_swap is a project focused on creating an efficient sorting algorithm to sort integers using a limited set of operations on two stacks. This project is designed to deepen understanding of algorithm complexity and efficient coding practices in C.

## 2. Features

- **Two Stack Management:** Utilizes two stacks, `a` and `b`, to perform sorting.
- **Operations:**
  - **Swap Operations:** `sa`, `sb`, `ss`
  - **Push Operations:** `pa`, `pb`
  - **Rotate Operations:** `ra`, `rb`, `rr`
  - **Reverse Rotate Operations:** `rra`, `rrb`, `rrr`
- **Error Handling:** Comprehensive error handling to prevent crashes (e.g., segmentation fault, bus error).
- **Memory Management:** Ensures no memory leaks.
- **Norm Compliance:** Adheres to the project norm and coding standards.
- **Checker Program:** Validates the correctness of the sorting algorithm.
- **Operation Optimization:** Achieves minimal operations for sorting 100 and 500 random numbers.

## 3. Objectives

- **Develop a Sorting Algorithm:** Write a sorting algorithm to sort integers in stack `a` with the least number of operations.
- **Algorithm Efficiency:** Focus on the complexity and efficiency of the algorithm.
- **Error Handling and Memory Management:** Ensure robust error handling and proper memory management.
- **Sort stack `a`:** Sort integers in ascending order using the available operations.
- **Minimal Operations:** Strive to achieve the minimal number of operations for given benchmarks.

## How to use

1. Clone the repository:
   ```sh
   git clone <repository-url>

2. Compile the code:
   ```sh
   make bonus

3. Run the Program:
   ```sh
   ./push_swap <list of integers>

### Example of Usage
- Initializing Stacks:
  ```sh
   ./push_swap 2 1 3 5 8 4
- Check Sorting (using bash terminal):
  ```sh
  bash
  ARG="2 1 3 5 8 4"; ./push_swap $ARG | ./checker $ARG
- Benchmarking Number of Operations (using bash terminal:
  ```sh
  ARG="2 1 3 5 8 4"; ./push_swap $ARG | wc -l

## Author

- [Andre Silva](https://github.com/mzsv/)

## Acknowledgements

- The 42 School for providing the project specifications and work environment.
