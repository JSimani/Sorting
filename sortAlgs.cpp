#include <iostream>
#include <cmath>
#include <vector>
#include "sortAlgs.h"
using namespace std;

template <typename T>
static void quickPartition(vector<T> &);

template <typename T>
static vector<T> mergePartition(vector<T> &);

template <typename T>
static vector<T> mergeGlue(vector<T>, vector<T>);

template <typename T>
static void buildHeap(vector<T> &);

template <typename T>
static void heapify(vector<T> &, size_t, size_t);

static inline size_t getLeftChild(size_t);
static inline size_t getRightChild(size_t);

template <typename T>
static inline vector<T> radixGlue(vector<T> [], size_t);

template <typename T>
static inline T findMin(const vector<T> &);

template <typename T>
static T findPivot(const vector<T> &);

template <typename T>
static inline T findMax(const vector<T> &);

template <typename T>
static inline size_t findDigits(const vector<T> &);

template <typename T>
static vector<T> operator+(vector<T> a, const vector<T> &b)
{
    for (size_t i = 0; i < b.size(); i++) 
        a.push_back(b[i]);

    return a;
}
template vector<int> operator+(vector<int>, const vector<int> &);
template vector<size_t> operator+(vector<size_t>, const vector<size_t> &);
template vector<unsigned> operator+(vector<unsigned>, 
                                    const vector<unsigned> &);
template vector<double> operator+(vector<double>, const vector<double> &);
template vector<string> operator+(vector<string>, const vector<string> &);

template <typename T>
static void operator+=(vector<T> &a, const vector<T> &b)
{
    for (size_t i = 0; i < a.size(); i++) 
        a.push_back(b[i]);
}
template void operator+=(vector<int> &, const vector<int> &);
template void operator+=(vector<size_t> &, const vector<size_t> &);
template void operator+=(vector<unsigned> &, const vector<unsigned> &);
template void operator+=(vector<double> &, const vector<double> &);
template void operator+=(vector<string> &, const vector<string> &);

/* insertionSort()
 * Purpose: Sorts a vector of unsigned integers into ascending order by using 
 *          the Insertion Sort algorithm. 
 * Parameters: Reference to an unsigned integer Vector (list of unsorted 
 *             numbers). The list will be updated to contain the same integers
 *             in sorted order. 
 * Return Type: void
 * Errors Thrown: None */
template <typename T>
void insertionSort(vector<T> &list)
{
    size_t i, j;
    for (i = 1; i < list.size(); i++) {
        T initialNum = list[i];

        /* This for loop will continue swapping elements until either j gets
         * to 0, or until the next element is less than the orginal one. */
        for (j = i; (j > 0) && (list[j - 1] > initialNum); j--) 
            list[j] = list[j - 1];
    
        list[j] = initialNum;
    }
}
template void insertionSort(vector<int> &);
template void insertionSort(vector<size_t> &);
template void insertionSort(vector<double> &);
template void insertionSort(vector<unsigned> &);
template void insertionSort(vector<string> &);

/* selectionSort()
 * Purpose: Sorts a vector of unsigned integers into ascending order by using 
 *          the Selection Sort algorithm. 
 * Parameters: Reference to an unsigned integer Vector (list of unsorted 
 *             numbers). The list will be updated to contain the same integers
 *             in sorted order. 
 * Return Type: void
 * Errors Thrown: None */
template <typename T>
void selectionSort(vector<T> &list)
{
    size_t minIndex;
    for (size_t i = 0; i < list.size(); i++) {
        minIndex = i;
        for (size_t j = i; j < list.size(); j++) {
            if (list[j] < list[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            T temp = list[i];
            list[i] = list[minIndex];
            list[minIndex] = temp;
        }
    }
}
template void selectionSort(vector<int> &);
template void selectionSort(vector<size_t> &);
template void selectionSort(vector<double> &);
template void selectionSort(vector<unsigned> &);
template void selectionSort(vector<string> &);

/* quickSort()
 * Purpose: Sorts a vector of unsigned integers into ascending order by using 
 *          the Quick Sort algorithm. 
 * Parameters: Reference to an unsigned integer Vector (list of unsorted 
 *             numbers). The list will be updated to contain the same integers
 *             in sorted order. 
 * Return Type: void
 * Errors Thrown: None */
template <typename T>
void quickSort(vector<T> &list)
{
    quickPartition(list);
}
template void quickSort(vector<int> &);
template void quickSort(vector<size_t> &);
template void quickSort(vector<double> &);
template void quickSort(vector<unsigned> &);
template void quickSort(vector<string> &);

/* mergeSort()
 * Purpose: Sorts a vector of unsigned integers into ascending order by using 
 *          the Merge Sort algorithm. 
 * Parameters: Reference to an unsigned integer Vector (list of unsorted 
 *             numbers). The list will be updated to contain the same integers
 *             in sorted order. 
 * Return Type: void
 * Errors Thrown: None */
template <typename T>
void mergeSort(vector<T> &list)
{
    list = mergePartition(list);
}
template void mergeSort(vector<int> &);
template void mergeSort(vector<size_t> &);
template void mergeSort(vector<double> &);
template void mergeSort(vector<unsigned> &);
template void mergeSort(vector<string> &);

/* heapSort()
 * Purpose: Sorts a vector of unsigned integers into ascending order by using 
 *          the Heap Sort algorithm. 
 * Parameters: Reference to an unsigned integer Vector (list of unsorted 
 *             numbers). The list will be updated to contain the same integers
 *             in sorted order. 
 * Return Type: void
 * Errors Thrown: None */
template <typename T>
void heapSort(vector<T> &list)
{
    buildHeap(list);

    for (size_t heapSize = list.size(); heapSize > 0; heapSize--) {
        T temp = list[0];
        list[0] = list[heapSize - 1];
        list[heapSize - 1] = temp;

        heapify(list, 0, heapSize);
    }
}
template void heapSort(vector<int> &);
template void heapSort(vector<size_t> &);
template void heapSort(vector<double> &);
template void heapSort(vector<unsigned> &);
template void heapSort(vector<string> &);

/* radixSort()
 * Purpose: Sorts a vector of unsigned integers into ascending order by using 
 *          the Radix Sort algorithm. 
 * Parameters: Reference to an unsigned integer Vector (list of unsorted 
 *             numbers). The list will be updated to contain the same integers
 *             in sorted order. 
 * Return Type: void
 * Errors Thrown: None */
template <typename T>
void radixSort(vector<T> &list)
{
    T minNumber = findMin(list);
    if (minNumber < 0) {
        minNumber *= -1;
    }

    for (size_t i = 0; i < list.size(); i++) {
        list[i] += minNumber;
    }

    size_t maxDigits = findDigits(list);
    vector<T> digit[10];
    size_t n = 10, m = 1;

    for (size_t i = 0; i < maxDigits; i++) {
        // // Used to evaluate the value of the current digit for each element
        // n = pow(10, i + 1);
        // m = pow(10, i);

        for (size_t j = 0; j < list.size(); j++) {
            // Calculates which bucket (index) the current number should be
            // stored in among the 10 possible digit buckets
            size_t bucket = ((list[j] % n) / m);
            digit[bucket].push_back(list[j]);
        }

        list = radixGlue(digit, 10);

        for (size_t i = 0; i < 10; i++) {
            digit[i].clear();
        }

        // Used to evaluate the value of the current digit for each element
        n *= 10;
        m *= 10;
    }

    for (size_t i = 0; i < list.size(); i++) {
        list[i] -= minNumber;
    }
}
template void radixSort(vector<int> &);
template void radixSort(vector<size_t> &);
template void radixSort(vector<unsigned> &);

/* bucketSort()
 * Purpose: Sorts a vector of unsigned integers into ascending order by using 
 *          the Bucket Sort algorithm. 
 * Parameters: Reference to an unsigned integer Vector (list of unsorted 
 *             numbers). The list will be updated to contain the same integers
 *             in sorted order. 
 * Return Type: void
 * Errors Thrown: None */
template <typename T>
void bucketSort(vector<T> &list)
{
    T minElement = findMin(list);
    T maxElement = findMax(list);
    T currentElement;

    size_t *buckets = new size_t[maxElement - minElement]();

    for (size_t i = 0; i < list.size(); i++) {
        currentElement = list[i];
        buckets[currentElement - minElement]++;
    }

    list.clear();
    for (T i = 0; i < (maxElement - minElement); i++) {
        for (size_t j = 0; j < buckets[i]; j++) {
            list.push_back(minElement + i);
        }
    }

    delete[] buckets;
}
template void bucketSort(vector<int> &);
template void bucketSort(vector<size_t> &);
template void bucketSort(vector<unsigned> &);

/* quickPartition()
 * Purpose: Partition the current vector into three separate vectors: left 
 *          (numbers less than the pivot number), middle (numbers equal to the
 *          pivot number), and right (numbers greater than the pivot number). 
 *          After partitioning, it keeps partitioning the left and right 
 *          sub-vectors until they cannot be partitioned anymore, then it 
 *          glues all partitions together and returns that vector of unsigned
 *          integers to the caller of the function. 
 * Parameters: Vector of unsigned integers (to be partitioned)
 * Return Type: Vector of unsigned integers (partitioned and glued back 
 *              together)
 * Errors Thrown: None */
template <typename T>
static void quickPartition(vector<T> &list)
{
    if (list.size() <= 1)
        return;
    
    T pivot = findPivot(list);
    vector<T> left, middle, right;
    int currentIndex = 0;

    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] < pivot)
            left.push_back(list[i]);
        else if (list[i] > pivot)
            right.push_back(list[i]);
        else
            middle.push_back(list[i]);
    }

    // Partitions the left and right vectors recursively until they each 
    // contain only one or zero elements.
    quickPartition(left);
    quickPartition(right);

    for (size_t i = 0; i < left.size(); i++) 
        list[currentIndex++] = left[i];
    
    for (size_t i = 0; i < middle.size(); i++)
        list[currentIndex++] = middle[i];

    for (size_t i = 0; i < right.size(); i++)
        list[currentIndex++] = right[i];
    
}
template void quickPartition(vector<int> &);
template void quickPartition(vector<size_t> &);
template void quickPartition(vector<double> &);
template void quickPartition(vector<unsigned> &);
template void quickPartition(vector<string> &);

template <typename T>
static vector<T> mergePartition(vector<T> &list)
{
    vector<T> subListOne, subListTwo;

    if (list.size() <= 1) 
        return list;

    for (size_t i = 0; i < (list.size() / 2); i++) {
        subListOne.push_back(list[i]);
    }

    for (size_t i = (list.size() / 2); i < list.size(); i++) {
        subListOne.push_back(list[i]);
    }

    return mergeGlue(mergePartition(subListOne), mergePartition(subListTwo));
}

template <typename T>
static vector<T> mergeGlue(vector<T> listOne, vector<T> listTwo)
{
    vector<T> merge;
    size_t i = 0, j = 0;
    size_t listOneSize = listOne.size();
    size_t listTwoSize = listTwo.size();

    while ((i < listOneSize) || (j < listTwoSize)) {
        if ((i < listOneSize) && !(j < listTwoSize)) {
            merge.push_back(listOne[i++]);
        } else if (!(i < listOneSize) && (j < listTwoSize)) {
            merge.push_back(listTwo[j++]);
        } else {
            if (listOne[i] < listTwo[j]) {
                merge.push_back(listOne[i++]);
            } else {
                merge.push_back(listTwo[j++]);
            }
        }
    }

    return merge;
}

template <typename T>
static void buildHeap(vector<T> &list)
{
    size_t size = list.size();

    if (size == 0) 
        return;
    
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(list, i, size);  
}

template <typename T>
static void heapify(vector<T> &list, size_t index, size_t size)
{
    size_t leftChildIndex = getLeftChild(index);
    size_t rightChildIndex = getRightChild(index);
    size_t maxIndex = index;

    if (index >= size) 
        return;

    if (leftChildIndex < size && list[leftChildIndex] > list[maxIndex])
        maxIndex = leftChildIndex;
    
    if (rightChildIndex < size && list[rightChildIndex] > list[maxIndex]) 
        maxIndex = leftChildIndex;

    if (maxIndex != index) {
        T temp = list[maxIndex];
        list[maxIndex] = list[index];
        list[index] = temp;

        heapify(list, maxIndex, size);
    }
}

static inline size_t getLeftChild(size_t index)
{
    return (index * 2) + 1;
}

static inline size_t getRightChild(size_t index)
{
    return (index * 2) + 2;
}

/* radixGlue()
 * Purpose: Concatenates an array of vectors of integers into one single 
 *          vector of integers. 
 * Parameters: Array of unsigned integer Vectors, size_t (number of unsigned 
 *             integer vectors to be concatenated)
 * Return Type: unsigned integer Vector (concatenated version of array of 
 *              unsigned integer Vectors)
 * Errors Thrown: None */
template <typename T>
static inline vector<T> radixGlue(vector<T> arr[], size_t size)
{
    vector<T> combined;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < arr[i].size(); j++) {
            combined.push_back(arr[i][j]);
        }
    }

    return combined;
}
template vector<int> radixGlue(vector<int> [], size_t);
template vector<size_t> radixGlue(vector<size_t> [], size_t);
template vector<unsigned> radixGlue(vector<unsigned> [], size_t);

template <typename T>
static T findPivot(const vector<T> &list)
{
    T first = list[0];
    T middle = list[list.size() / 2];
    T last = list[list.size() - 1];

    if (first <= middle && middle <= last) {
        return middle;
    } else if (middle <= last && last <= first) {
        return last;
    } else {
        return first;
    }
}

/* findDigits()
 * Purpose: Calculates the maximum number of digits for the largest number
 *          within an unsigned integer Vector
 * Parameters: unsigned integer Vector (contains numbers with varying values 
 *             and numbers of digits)
 * Return Type: size_t (number of digits for the largest number within the 
 *              unsigned integer Vector)
 * Errors Thrown: None */
template <typename T>
static inline size_t findDigits(const vector<T> &list) 
{
    T maxNumber = findMax(list);
    size_t maxDigits = 1;

    while (maxNumber / 10) {
        maxNumber /= 10;
        maxDigits++;
    }

    return maxDigits;
}
template size_t findDigits(const vector<int> &);
template size_t findDigits(const vector<size_t> &);
template size_t findDigits(const vector<unsigned> &);

template <typename T>
static inline T findMin(const vector<T> &list)
{
    if (list.empty()) {
        return 0;
    }

    T minNumber = list[0];
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] < minNumber) {
            minNumber = list[i];
        }
    }

    return minNumber;
}
template int findMin(const vector<int> &);
template size_t findMin(const vector<size_t> &);
template unsigned findMin(const vector<unsigned> &);

template <typename T>
static inline T findMax(const vector<T> &list)
{
    if (list.empty()) {
        return 0;
    }

    T maxNumber = list[0];
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] > maxNumber) {
            maxNumber = list[i];
        }
    }

    return maxNumber;
}
template int findMax(const vector<int> &);
template size_t findMax(const vector<size_t> &);
template unsigned findMax(const vector<unsigned> &);
