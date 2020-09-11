#include <iostream>
#include <vector>


int findSmallestMissing(std::vector<int> numbers, int min) {
    int iterate = 0;
    int candidate = min + 1;
    while(iterate < numbers.size()) {
        if(numbers.at(iterate) == candidate) {
            candidate++;
            iterate = 0;
        }
        else {
            iterate++;
        }
    }
    return candidate;
}

int main() {
    int smallestMissing;
    int amountNums;
    int nextNum;
    int minimum;
    int maximum;

    std::cout << "How many numbers? ";
    std::cin >> amountNums;
    std::vector<int> numbers;
    std::cout << std::endl;
    std::cout << "Please enter the numbers ";
    std::cin >> nextNum;

    numbers.push_back(nextNum);
    minimum = nextNum;
    maximum = nextNum;
    for(int i = 0; i < amountNums - 1; i++) {
        std::cin >> nextNum;
        if(nextNum < minimum) {
            minimum = nextNum;
        }
        if(nextNum > maximum) {
            maximum = nextNum;
        }
        numbers.push_back(nextNum);
    }

    std::cout << std::endl << "The smallest missing number is ";
    std::cout << findSmallestMissing(numbers, minimum) << std::endl;

    return 0;
}

