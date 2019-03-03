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
#### person.h
[Example Class](sort/include/person.h).
Create Objects with Name and Age.
#### sort.h
T can be any type. Functions with T* use the provided compare function.

`void prarr(int *arr, int s, int e);`

Print array arr from index s to index e.
___

`int pow(int, int);`

_@return_ first parameter to the power of second parameter
___

`int getChar(int, std::string);`

_@param_ int position, string value

_@return_ numeric value of string at position - 'a' map 'a' - 'z' to 0-25
___

`Sort();`

Default constructor
___

`Sort(int (*compare)(T, T));`

_@param_ function pointer to provided compare function
Set the function by which objects are compared here. View [code examples](#code-examples) for more details.
___

`void bubbleSort(T*, int);`

_@param_ T* array of elements of type T, int i number of elements in array
___

`void selectionSort(T*, int);`

_@param_ T* array of elements of type T, int i number of elements in array
___

`void insertionSort(T*, int);`

_@param_ T* array of elements of type T, int i number of elements in array
___

`void shellSort(T*, int);`

_@param_ T* array of elements of type T, int i number of elements in array
___

`void mergeSort(T*, int, int);`

_@param_ T* array of elements of type T, sort elements from int start to int end
___

`void merge(T*, int, int, int);`

_@param_ T* array of elements of type T, int start, int mid, int end
Merge elements in logically left array with right array
___

`void countingSort(int*, int);`

_@param_ int* array of non-negative discrete values, int number of elements
Only sorts integer arrays does not use the compare function.
___

`void quickSort(T*, int, int);`

_@param_ T* array of elements of type T, int start, int end
Sort T* from index start to end
___

`int partition(T*, int, int);`

_@param_ T* array of elements of type T, int start, int end

_@return_ Index of new pivot
Move all elements smaller than the pivot element to the left of it and all elements greater to the right of it.
___

`void radixSort(T*, std::string[], int, int);`

_@param_ T* array of elements of type T, array of strings to be sorted, int radix, int number of elements

One string in the string array belongs to one object in T* they must have the same index.
Only sorts strings by alphabet. Does not use the comare function.
___

`void radixSingleSort(T*, std::string[], int, int, int, int);`

_@param_ T* array of elements of type T, array of strings to be sorted, int position, int width, int radix, int number of elements

One string in the string array belongs to one object in T* they must have the same index.
Only sorts strings by alphabet. Does not use the comare function. Sorts strings by character at position.
___

`void swap(T&, T&);`

_@param_ address of object, address of object
___

`T getMax(T*, int);`

_@param_ T* array of elements of type T, int number of Elements in T*

_@return_ greatest object of type T
___

`T getMin(T*, int);`

_@param_ T* array of elements of type T, int number of Elements in T*

_@return_ smallest object of type T
___

`int (*compare)(T,T);`  

_@param_ object of type T, object of type T

_@return_ View [code examples](#code-examples) for more details.

T can be any type of object. Define here by which values objects are compared and when they are greater, equal or smaller than another object.
___
# Code Examples
```cpp

```
