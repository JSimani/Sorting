#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    srand(time(NULL));
    ofstream outfile;
    size_t range; 
    size_t size; 
    char has_negatives;
    string filename;

    cout << "Size: ";
    cin >> size;

    cout << "Range: ";
    cin >> range;

    cout << "Negatives? (Y/N)";
    cin >> has_negatives;
    while (toupper(has_negatives) != 'Y' && toupper(has_negatives) != 'N') {
        cerr << "Invalid input. Negatives? (Y/N) ";
        cin >> has_negatives;
    }

    cout << "Filename: ";
    cin >> filename;

    outfile.open(filename.c_str());

    if (toupper(has_negatives) == 'Y') {
        range /= 2;
        for (size_t i = 0; i < size; i++) {
            if (rand() % 2) 
                outfile << "-";
            outfile << (int)rand() % range << " ";
        }
    } else {
        for (size_t i = 0; i < size; i++) 
            outfile << (int)rand() % range << " ";
    }
    

    outfile << endl;
    outfile.close();

    return 0;
}
