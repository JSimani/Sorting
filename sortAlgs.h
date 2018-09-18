#ifndef SORTALGS_H
#define SORTALGS_H 
#include <vector>

// Sorts a vector of elements into ascending order by using the Insertion Sort
// algorithm. 
template <typename T>
void insertionSort(std::vector<T> &list);

// Sorts a vector of elements into ascending order by using the Selection Sort
// algorithm. 
template <typename T>
void selectionSort(std::vector<T> &list);

// Sorts a vector of elements into ascending order by using the Quick Sort 
// algorithm. 
template <typename T>
void quickSort(std::vector<T> &list);

// Sorts a vector of elements into ascending order by using the Merge Sort 
// algorithm. 
template <typename T>
void mergeSort(std::vector<T> &list);

// Sorts a vector of elements into ascending order by using the Heap Sort 
// algorithm. 
template <typename T>
void heapSort(std::vector<T> &list);

// Sorts a vector of elements into ascending order by using the Radix Sort 
// algorithm. 
template <typename T>
void radixSort(std::vector<T> &list);

// Sorts a vector of elements into ascending order by using the Bucket Sort 
// algorithm. 
template <typename T>
void bucketSort(std::vector<T> &list);

#endif