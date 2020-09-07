#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int length;
    int width;
    int perimeter;
    int area;
    double diagonal;

    cout << "Please enter the length and width of the rectangle: ";
    cin >> length >> width;
    cout << endl;

    perimeter = (length + width) * 2;
    area = length * width;
    diagonal = sqrt(pow(length,2) + pow(width,2));

    cout << "perimeter: " << perimeter << endl << "area: " << area << endl << "diagonal: " << diagonal << endl;

    return 0;
}
