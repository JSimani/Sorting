#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <sys/ioctl.h>
#include <unistd.h>
#include "sortAlgs.h"
using namespace std;

void buildHeap(vector<int> &);
void heapify(vector<int> &, int, int);
static inline size_t getLeftChild(size_t index);
static inline size_t getRightChild(size_t index);

int main(int argc, char *argv[])
{


    return 0;
}

void buildHeap(vector<int> &list)
{
    size_t size = list.size();

    if (size == 0) 
        return;
    
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(list, i, size);  
}

void heapify(vector<int> &list, int index, int size)
{
    int leftChildIndex = getLeftChild(index);
    int rightChildIndex = getRightChild(index);
    int maxIndex = index;

    if (index < 0) 
        return;

    if (leftChildIndex < size && list[leftChildIndex] > list[maxIndex])
        maxIndex = leftChildIndex;
    
    if (rightChildIndex < size && list[rightChildIndex] > list[maxIndex]) 
        maxIndex = leftChildIndex;

    if (maxIndex != index) {
        int temp = list[maxIndex];
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
