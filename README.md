# Algorithms and Datastructures
My implementation of different algorithms and datastructures in C++ for better understanding.


## Table of contents
* [Sorting algorithms](#sorting-algorithms)
* [How to test/use](#how-to-testuse)
* [Documentation](#documentation)
* [Code Examples](#code-examples)


## Sorting algorithms
Overview of all sorting algorithms implemented in this project with time and space complexity.
1. **Bubblesort**
 * Worst case time complexity: **O(n^2)**
 * Spacecomplexity: **O(1)**
 * "In-place algorithm"
 * stable
2. **Selectionsort**
 * Worst case time complexity: **O(n^2)**
 * Spacecomplexity: **O(1)**
 * "In-place algorithm"
 * unstable
3. **Insertionsort**
 * Worst case time complexity: **O(n^2)**
 * Spacecomplexity: **O(1)**
 * "In-place algorithm"
 * stable
4. **Shellsort**
 * Variation of Insertion Sort (1 < gap)
 * Worst case time complexity: **O(n^2)** (dependent on gap)
 * Spacecomplexity: **O(1)**
 * "In-place algorithm"
 * unstable
5. **Mergesort**
 * Worst case time complexity: **O(nln(n))**
 * Spacecomplexity: **O(n)**
 * "In-place algorithm"
 * Divide and conquer
 * stable
6. **Quicksort**
 * Worst case time complexity: **O(n^2)**
 * Average case time complexity: **O(nln(n))**
 * Mostly performs better than mergesort
 * Spacecomplexity: **O(1)**
 * "In-place algorithm"
 * unstable
7. **Counting Sort**
 * Only works with non-negative discrete values
 * Does not use comparison
 * Complexity depending on range of algorithms
 * Worst case time complexity: **O(n+k)**
 * Spacecomplexity: **O(k)**
 * unstable (stable variation used in radixsort)
8. **Radixsort**
 * Worst case time complexity: **O(nk)**
 * Spacecomplexity: **O(n+k)**
 * stable
Implemented in [_sort.h_](sort/include/sort.h). View [documentation](#sorth) for more Information.
## How to test/use
Clone/Download Repository. `cd AD/sort/source` -> `make start`. Compiles and runs program.
## Documentation
#### sort.h
`void prarr(int *arr, int s, int e);`


Print array arr from index s to index e.


`int pow(int, int);`


_@return_ first parameter to the power of second parameter


`int getChar(int, std::string);`


_@param_ int position, string value
_@return_ numeric value of string at position - 'a' map 'a' - 'z' to 0-25


`Sort();`


Default constructor


`Sort(int (*compare)(T, T));`


_@param_ function pointer to provided compare function



`void bubbleSort(T*, int);`


_@param_ T* array of elements of type T, int i number of elements in array



`void selectionSort(T*, int);`


_@param_ T* array of elements of type T, int i number of elements in array



`void insertionSort(T*, int);`


_@param_ T* array of elements of type T, int i number of elements in array


`void shellSort(T*, int);`


_@param_ T* array of elements of type T, int i number of elements in array


`void mergeSort(T*, int, int);`


_@param_ T* array of elements of type T, sort elements from int start to int end



`void merge(T*, int, int, int);`



`void countingSort(int*, int);`


`void quickSort(T*, int, int);`


`int partition(T*, int, int);`


`void radixSort(T*, std::string[], int, int);`


`void swap(T&, T&);`


`T getMax(T*, int);`


`T getMin(T*, int);`


`int (*compare)(T,T);`  


`void radixSingleSort(T*, std::string[], int, int, int, int);`
