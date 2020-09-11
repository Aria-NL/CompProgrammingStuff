#include <iostream>
#include <vector>
#include <algorithm>

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

    std::cout << "How many numbers? ";
    std::cin >> amountNums;
    std::vector<int> numbers;
    std::cout << std::endl << "Please enter the numbers ";
    std::cin >> nextNum;

    numbers.push_back(nextNum);
    for(int i = 0; i < amountNums - 1; i++) {
        std::cin >> nextNum;
        numbers.push_back(nextNum);
    }
    minimum = *min_element(numbers.begin(), numbers.end());
    std::cout << std::endl << "The smallest missing number is " << findSmallestMissing(numbers, minimum) << std::endl; 
    return 0;
}

