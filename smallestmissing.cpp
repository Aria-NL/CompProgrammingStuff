#include <iostream>
#include <vector>

void countingSort(std::vector<int>& nums, int min, int max) {
    int range = max - min + 1;
    
    std::vector<int> counts(range);
    std::vector<int> output(nums.size());
    
    for(int i = 0; i < nums.size(); i++) {
        counts.at(nums.at(i) - min)++;
    }
    for(int i = 1; i < counts.size(); i++) {
        counts.at(i) += counts.at(i - 1);
    }
    for(int i = nums.size() - 1; i >= 0; i--) {
        output.at(counts.at(nums.at(i) - min) - 1) = nums[i];
        counts.at(nums.at(i) - min)--;
    }
    nums = output;
}

int findSmallestMissing(std::vector<int> sortedNums) {
    for(int i = 0; i < sortedNums.size(); i++) {
        if((sortedNums.at(i + 1) - sortedNums.at(i)) > 1) {
            return (sortedNums.at(i) + 1);
        }
    }
    return 0; //make compiler happy
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

    std::cout << "The smallest missing number is ";
    countingSort(numbers, minimum, maximum);
    std::cout << findSmallestMissing(numbers) << std::endl;

    return 0;
}

