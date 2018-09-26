#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    srand(time(NULL));
    size_t range; 
    size_t size; 
    char has_negatives;
    string filename;

    cerr << "Size: ";
    cin >> size;

    cerr << "Range: ";
    cin >> range;

    cerr << "Negatives? (Y/N)";
    cin >> has_negatives;
    while (toupper(has_negatives) != 'Y' && toupper(has_negatives) != 'N') {
        cerr << "Invalid input. Negatives? (Y/N) ";
        cin >> has_negatives;
    }

    if (toupper(has_negatives) == 'Y') {
        range /= 2;
        for (size_t i = 0; i < size; i++) {
            if (rand() % 2) 
                cout << "-";
            cout << (int)rand() % range << " ";
        }
    } else {
        for (size_t i = 0; i < size; i++) 
            cout << (int)rand() % range << " ";
    }
    

    cout << endl;

    return 0;
}
