#include <iostream>
#include <fstream>
#include <vector>
#include "sortAlgs.h"
using namespace std;

void output(string filename, ofstream &outfile);

int main()
{
    ofstream outfile("insertionSortOutput.txt");
    outfile << "Insertion Sort Output\n\n";

    output("empty.txt", outfile);
    output("forwardOrderContinuous.txt", outfile);
    output("forwardOrderSkip.txt", outfile);
    output("reverseOrderContinuous.txt", outfile);
    output("reverseOrderSkip.txt", outfile);
    output("random.txt", outfile);
}

void output(string filename, ofstream &outfile)
{
    ifstream infile(filename.c_str());
    if (!infile.is_open())
        return;

    outfile << "[" << filename << "]" << endl;
    vector<int> list;

    int readIn;
    while (infile >> readIn)
        list.push_back(readIn);

    insertionSort(list);

    for (size_t i = 0; i < list.size(); i++) 
        outfile << list[i] << endl;

    outfile << endl;
    infile.close();
}
