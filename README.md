# Algorithms: 
    1.  Insertion Sort: The algorithm for insertion sort is fairly straight 
    forward. Given a particular element, keep moving the elements to the left 
    of it over one position to the right until the next element is less than 
    the original element. Then place the original element in the spot of the 
    last moved element. You need to do this for every element in the list from 
    the first to the last. The best case runtime for Insertion Sort occurs 
    when the list of integers is already sorted, resulting in a runtime of 
    O(n). The worst case runtime occurs when the list of integers is in 
    reverse order, resulting in a runtime of O(n^2). The average runtime for 
    Insertion Sort is O(n^2) because you are multiplying the number of 
    integers to sort by an average number of shifts that need to occur. 

    2.  Quick Sort: The algorithm for quick sort is more complicated than 
    insertion sort. When given a list of integers, you need to choose a pivot 
    number (I chose the first element). Using three sub-vectors (left, middle, 
    right), you place the elements in the list less than the pivot in the left 
    vector, the elements equal to the pivot in the middle vector, and the 
    elements greater than the pivot in the right vector. The partition function
    has a base case (because it's recursive!) where if the size of the vector 
    is less than 2, it doesn't do anything and returns the original vector. 
    With this, we can call glue (which concatenates vectors) on partition(
    left) + middle + partition(right). We don't need to partition middle again 
    because it only contains the pivot number and is therefore already sorted. 
    Partitioning a sub-vector will cause more partitions until it reaches a 
    state where all partitions are less than 2 (except for middle vectors). 
    This will then continuously concatenate these vectors until we are left 
    with one whole, sorted vector. The worst case is when the selected pivot 
    is the smallest or greatest element in the list, resulting in a runtime of 
    O(n^2). The best case is when the selected pivot is the median element in 
    the list, resulting in a runtime of O (n log(n)). The average runtime ends 
    up being (n long(n)).

    3.  Radix Sort: The algorithm for radix sort deals with the values of 
    specific digits within a number, rather than dealing with the number as a 
    whole. For every digit starting from the one's place, up to the largest 
    place for the largest number in the list, that number is placed in a vector
    (0-9) corresponding to the value of the number at that digit. At the end of
    that iteration, these vectors are concatenated and overwrite the original 
    list. This process repeats for a set number of times based on the number of
    digits for the largest number in the list. The worst case is when there is 
    a large number of digits to iterate through and there are a lot of numbers 
    to go through. The best case is when there is a low number of digits and a 
    small list of numbers to sort. All cases end in a runtime of O(dn), where 
    d = number of digits and n = number of numbers to sort through. 