# Data Structures & Algorithms with C++

An educational repository focused on learning and understanding **Data Structures and Algorithms** using C++.

The main goal of this repository is to provide simple implementations and explanations of fundamental computer science concepts, making it easier for students and beginners to understand how different data structures and algorithms work.

## 📚 Repository Contents

The repository covers different topics, including:

- **Sorting Algorithms**
- Searching Algorithms
- Linear Data Structures
- Non-Linear Data Structures
- Other fundamental Algorithms

---

## 🔢 Sorting Algorithms

Sorting algorithms are used to arrange elements in a specific order, usually ascending or descending.

Different sorting algorithms use different approaches to organize data. Understanding how they work and comparing their time complexities helps us choose the most suitable algorithm for a particular problem.

### 1. Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

With each pass, the largest unsorted element moves to its correct position.

- **Best Case:** O(n) (optimized version)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)
- **Space Complexity:** O(1)

### 2. Selection Sort

Selection Sort divides the array into sorted and unsorted parts.

It repeatedly finds the smallest element in the unsorted part and places it at the beginning.

- **Best Case:** O(n²)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)
- **Space Complexity:** O(1)

### 3. Insertion Sort

Insertion Sort builds the sorted array one element at a time.

It takes each element and inserts it into its correct position among the previously sorted elements.

It works particularly well with small or nearly sorted arrays.

- **Best Case:** O(n)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)
- **Space Complexity:** O(1)

### 4. Merge Sort

Merge Sort uses the **Divide and Conquer** approach.

It divides the array into smaller halves, sorts each half recursively, and then merges the sorted halves into one sorted array.

- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)
- **Space Complexity:** O(n)

### 5. Quick Sort

Quick Sort also uses the **Divide and Conquer** approach.

It selects a pivot element, partitions the array around that pivot, and recursively sorts the resulting partitions.

- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n²)
- **Average Auxiliary Space:** O(log n)

### 6. Heap Sort

Heap Sort uses a Binary Heap data structure to organize and sort elements.

It builds a Max Heap, then repeatedly extracts the largest element and places it at the end of the array.

- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)
- **Space Complexity:** O(1)

### Sorting Algorithms Comparison

| Algorithm | Best Case | Average Case | Worst Case | Stable |
|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | No |

---

## 🎯 Learning Objectives

- Understand fundamental data structures and algorithms.
- Learn how different algorithms work through practical C++ implementations.
- Analyze and compare algorithm efficiency using Big O notation.
- Improve problem-solving and programming skills.

## 🔍 Binary Search

Binary Search is an efficient searching algorithm used to find a specific element in a **sorted array**.

It works by repeatedly dividing the search range into two halves:

1. Find the middle element.
2. If the middle element matches the target, return its position.
3. If the target is smaller, search the left half.
4. If the target is larger, search the right half.
5. Repeat until the element is found or the search range becomes empty.

### Time Complexity

| Case | Time Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

**Space Complexity:** O(1) (Iterative Implementation)

**Note:** Binary Search requires the array to be sorted before searching.