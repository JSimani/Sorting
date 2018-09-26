#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "sortAlgs.h"
#include "wordWrap.h"
using namespace std;

const string USAGE = " [-1234567hr] [--algorithm=method] [--help] \
                     [--reverse] [file]";

typedef int Element;

struct sortInfo {
    void (*sort)(vector<Element> &);
    bool reverse;
    bool argFail;

    sortInfo()
    {
        sort=quickSort;
        reverse=false;
        argFail=false;
    }
};

void printError(char *[], int);
void printHelp(char *[]);

void processArguments(int, char*[], sortInfo &);

template <typename T>
void readInVector(vector<T> &, istream &);

template <typename T>
void printVector(vector<T>);

void wordWrap(stringstream &, ostream &, int);

int main(int argc, char *argv[])
{
    vector<Element> listOne;
    string argOne = (argc > 1 ? argv[1] : " ");
    sortInfo info;

    processArguments(argc, argv, info);
    if (info.argFail) {
        return 1;
    }

    if (argc == 1 || argv[argc - 1][0] == '-') {
        readInVector(listOne, cin);
    } else {
        string filename = argv[argc - 1];
        ifstream infile(filename.c_str());
        if (!infile.is_open()) {
            cerr << "Error opening file " << filename << endl;
            return 1;
        }

        readInVector(listOne, infile);
        infile.close();
    } 
    
    info.sort(listOne);

    if (info.reverse) {
        size_t size = listOne.size();
        for (size_t i = 0; i < size / 2; i++) {
            Element swap = listOne[i];
            listOne[i] = listOne[size - i - 1];
            listOne[size - i - 1] = swap;
        }
    }

    printVector(listOne);
    return 0;
}

void printError(char *argv[], int invalidArg)
{
    stringstream ss;

    if (invalidArg > 0) {
        string arg = argv[invalidArg];
        arg = arg.substr(1, arg.length());
        ss << argv[0] << ": invalid option -- " << arg;
        wordWrap(ss, cerr, 0);
    }

    ss << "usage: " << argv[0] << USAGE;
    wordWrap(ss, cerr, 0);
}

void printHelp(char *argv[])
{
    stringstream ss;
    ss << "NAME";
    wordWrap(ss, cerr, 0);

    ss << "sorting";
    wordWrap(ss, cerr, 4);
    cerr << endl;

    ss << "SYNOPSIS";
    wordWrap(ss, cerr, 0);

    ss << argv[0] << USAGE;
    wordWrap(ss, cerr, 4);
    cerr << endl;

    ss << "DESCRIPTION";
    wordWrap(ss, cerr, 0);

    ss << "The sorter utility organizes a given file in logical (alphabetical "
       << "or numeric) order and outputs the results to standard output.";
    wordWrap(ss, cerr, 4);
    cerr << endl;

    ss << "sorter accepts input from files and standard input, and can use a "
       << "user-defined algorithm to sort it.";
    wordWrap(ss, cerr, 4);
    cerr << endl;

    ss << "The following options are available: \n\n";
    wordWrap(ss, cerr, 4);
    cerr << endl;

    ss << "-1, --algorithm=insertion";
    wordWrap(ss, cerr, 4);

    ss << "Sort the data using Insertion Sort, which puts every element in an "
       << "unsorted list into its correct position in a sorted list until the "
       << "unsorted list is empty. Expected Runtime: O(n²)";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-2, --algorithm=selection";
    wordWrap(ss, cerr, 4);

    ss << "Sort the data using Selection Sort, which puts each element in its "
       << "correct position one at a time. Expected Runtime: O(n²)";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-3, --algorithm=quick";
    wordWrap(ss, cerr, 4);

    ss << "(Default) Sort the data using Quick Sort, which recursively "
       << "partitions the list into items less than, equal to, and greater "
       << "than the selected pivot, then glues those partitions back "
       << "together. Expected Runtime: O(nlogn)";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-4, --algorithm=merge";
    wordWrap(ss, cerr, 4);

    ss << "Sort the data using Merge Sort, which recursively partitions the "
       << "list into two equal-size sublists until each sublist has only one "
       << "element, then sorts those sublists by removing the smallest number "
       << "from two sublists and placing it in a sorted list. Expected "
       << "Runtime: O(nlogn)";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-5, --algorithm=heap";
    wordWrap(ss, cerr, 4);

    ss << "Sort the data using Heap Sort, which builds a Max Heap from the "
       << "list and extracts the maximum element, placing it into the sorted "
       << "list. Expected Runtime: O(nlogn). ";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-6, --algorithm=radix";
    wordWrap(ss, cerr, 4);

    ss << "Sort the data using Radix Sort, which iteratively assigns integers "
       << "(without using comparisons) to groups based on the current digit "
       << "being processed. When all digits have been processed, the groups " 
       << "are in sorted order. Expected Runtime: O(n+w), where w = "
       << "maximum number of digits per integer.";
    wordWrap(ss, cerr, 8);
    ss << "Note: This only works with integers, and cannot be used to sort "
       << "floating point numbers.";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-7, --algorithm=bucket";
    wordWrap(ss, cerr, 4);

    ss << "Sort the data using Bucket Sort, which places each element into an "
       << "array. The array holds a space for every integer between the "
       << "minimum number in the list and the maximum number in the list. "
       << "Once every element has been assigned to a bucket, it combines "
       << "every bucket into a sorted array. Expected Runtime: O(n+k), "
       << "where k = number of buckets needed.";
    wordWrap(ss, cerr, 8);

    ss << "Note: This only works with integers, and cannot be used to sort "
       << "floating point numbers.";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-h, --help";
    wordWrap(ss, cerr, 4);

    ss << "Display sorter's manual page.";
    wordWrap(ss, cerr, 8);
    cerr << endl;

    ss << "-r, --reverse";
    wordWrap(ss, cerr, 4);

    ss << "Reverse sort the input.";
    wordWrap(ss, cerr, 8);
}

void processArguments(int argc, char *argv[], sortInfo &info)
{
    for (int i = 0; i < argc; i++) {
        string currArg = argv[i];

        if (currArg == "-1" || currArg == "--algorithm=insertion") {
            info.sort = insertionSort;
        } else if (currArg == "-2" || currArg == "--algorithm=selection") {
            info.sort = selectionSort;
        } else if (currArg == "-3" || currArg == "--algorithm=quick") {
            info.sort = quickSort;
        } else if (currArg == "-4" || currArg == "--algorithm=merge") {
            info.sort = mergeSort;
        } else if (currArg == "-5" || currArg == "--algorithm=heap") {
            info.sort = heapSort;
        } else if (currArg == "-6" || currArg == "--algorithm=radix") {
            info.sort = radixSort;
        } else if (currArg == "-7" || currArg == "--algorithm=bucket") {
            info.sort = bucketSort;
        } else if (currArg == "-r" || currArg == "--reverse") {
            info.reverse = true;
        } else if (currArg == "-h" || currArg == "--help") {
            if (info.argFail)
                continue;

            printHelp(argv);
            info.argFail = true;
        } else if (argv[i][0] == '-') {
            if (info.argFail)
                continue;

            printError(argv, i);
            info.argFail = true;
        }
    }
}

template <typename T>
void readInVector(vector<T> &list, istream &stream)
{
    T num;
    while (stream >> num) 
        list.push_back(num);
}

template <typename T>
void printVector(vector<T> list)
{
    for (size_t i = 0; i < list.size(); i++)
        cout << list[i] << endl;
}
