#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int startNumber;
    int numberToPrint;
    int oneCount = 0;

    cout << "Enter the first number of the sequence: ";
    cin >> startNumber;
    numberToPrint = startNumber;

    if(numberToPrint == 1) {
        oneCount++;
    }

    cout << startNumber << " ";
    while(oneCount < 3) {
        if(numberToPrint % 2 == 0) {
            numberToPrint /= 2;
            cout << numberToPrint << " ";

            if(numberToPrint == 1) {
                oneCount++;
            }
        }
        else {
            numberToPrint = 3 * numberToPrint + 1;
            cout << numberToPrint << " ";
        }
    }
    cout << "..." << endl;
}