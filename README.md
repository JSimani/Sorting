#Sorter
## Sorting Options
### Algorithm
Specify when algorithm to use by using the flag, ``--algorithm=method``. Options include insertionSort, selectionSort, quickSort, mergeSort, heapSort, radixSort, and bucketSort. The default algorithm is quickSort. 

### Help
Show sorting options by using the flag ``-h`` or ``--help``. 

### Order
Specify sorting order by using the flag ``-r`` or ``--reverse`` to sort the input in descending order. 

### Time
Display the time taken to sort the elements by using the flag ``-t`` or ``--time``. Does not include time taken to output results. 

### Input Source
Take input from a filename by specifying the file as the last argument in the command line. Default input is from standard input.

## Sorting Algorithms
### insertionSort
Sorts the data by putting every element in the list to the left of all elements that are greater than it, starting at index 1. Expected Runtime: O(n²)

### selectionSort
Sorts the data by dividing the list into a sorted and unsorted list. It puts the smallest element in the unsorted list to the back of the sorted list until the unsorted list is empty. Expected Runtime: O(n²)

### quickSort
Sorts the data by choosing an arbitrary pivot element (I chose the first element). Using three sub-vectors (left, middle, right), it places the elements in the list less than the pivot in the left vector, the elements equal to the pivot in the middle vector, and the elements greater than the pivot in the right vector. It then recursively continues to partition each left and right sub partition until reaching a 1- or 0-element list. It then glues all of the partitions together to form a sorted list. Expected Runtime: O(n logn). 

### mergeSort
Sorts the data by recursively partitioning the list into two equal-size sublists until each sublist has only one element, then sorting those sublists by removing the smallest number from the two sublists and placing it in a sorted list. Expected Runtime: O(n logn).

### heapSort
Sorts the data by building a Max Heap from the list and extracting the maximum element, placing it into the sorted list. Expected Runtime: O(n logn).

### radixSort
Sorts the data by placing every element in a vector corresponding to its first digit. At the end each iteration, these vectors are concatenated and overwrite the original list. This process repeats for a set number of times based on the number of digits for the largest element in the list. Expected Runtime: O(dn), where d = number of digits and n = number of elements. 

### bucketSort
Sorts the data by placing each element into an array. The array holds a space for every integer between the minimum number in the list and the maximum number in the list. Once every element has been assigned to a bucket, it combines every bucket into a sorted array. Expected Runtime: O(n+k), n = number of elements and k = number of buckets needed. 
 