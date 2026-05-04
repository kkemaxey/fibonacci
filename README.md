# ⏱️ Fibonacci Efficiency Analysis: Iteration vs. Recursion

> A performance benchmarking suite in C++ that compares iterative and recursive approaches to calculating Fibonacci numbers. This project focuses on analyzing time complexity and the exponential overhead of naive recursion.

## 🧬 The Sequence
The implementation follows the specific sequence:
- **F(1)** = 1
- **F(2)** = 2
- **F(n)** = F(n-1) + F(n-2) for **n > 2**

## ✨ Features
- **Dual Implementations**: Includes both a linear-time iterative function and a classic recursive function.
- **Precision Benchmarking**: Uses the `<chrono>` high-resolution clock to measure execution time in microseconds.
- **Comparative Analysis**: Tests performance across a range of values: `F(10)` through `F(55)`.

## 📊 Benchmarking Requirements
The driver program measures and records the execution time for:
- **Iterative Method**: $O(n)$ time complexity, demonstrating near-instant results even for higher values.
- **Recursive Method**: $O(2^n)$ time complexity, illustrating the dramatic performance "cliff" as $n$ increases.

## 🛠️ Tech Stack
- **Language**: C++
- **Time Measurement**: `<chrono>` (High Resolution Clock)
- **Standard I/O**: `<iostream>`

## 🚀 How to Run

### Compilation
```bash
g++ fi.cpp -o [your_file_name].exe
```
