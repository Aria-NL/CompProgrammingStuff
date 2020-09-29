#include <iostream>
#include <fstream>
#include <vector>

int knapsack(int knapsackCap, std::vector<int> weights, std::vector<int> values, int itemNo, std::vector<bool> &visited) {
    if(itemNo == 0 || knapsackCap == 0) {
        return 0;
    }
    if(weights.at(itemNo - 1) > knapsackCap) {
        return knapsack(knapsackCap, weights, values, itemNo - 1, visited);
    }
    else {
        std::vector<bool> storeOne(visited.size());
        storeOne = visited;
        std::vector<bool> storeTwo(visited.size());
        storeTwo = visited;
        storeOne.at(itemNo - 1) = true;

        int answerOne = values.at(itemNo - 1) + knapsack(knapsackCap - weights.at(itemNo - 1), weights, values, itemNo - 1, storeOne);
        int answerTwo = knapsack(knapsackCap, weights, values, itemNo - 1, storeTwo);
        if(answerOne > answerTwo) {
            visited = storeOne;
            return answerOne;
        }
        else {
            visited = storeTwo;
            return answerTwo;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    std::ifstream input;
    std::vector<int> weights, values;
    int knapsackCap, currentValue, itemNo;
    int totalWeight = 0;

    try {
        if(argc != 2) {
            throw std::runtime_error("No input filename given");
        }
    }
    catch(std::runtime_error &excpt) {
        std::cout << excpt.what() << std::endl;
        return 0;
    }
    try {
        input.open(argv[1]);
        if(!input.is_open()) {
            throw std::runtime_error("Could not open file ");
        }
        input >> knapsackCap;
        while (input >> currentValue) {
            weights.push_back(currentValue);
            input >> currentValue;
            values.push_back(currentValue);
        }
        std::vector<bool> visited(weights.size());
        itemNo = values.size();
        std::cout << "With a capacity of " << knapsackCap << " kg, the total value is " << knapsack(knapsackCap, weights, values, itemNo, visited) << " Eur, leading to a total weight of ";
        for(int i = 0; i < itemNo; i++) {
            if(visited.at(i) == true) {
                totalWeight += weights.at(i);
            }
        }
        std::cout << totalWeight << " kg" << std::endl << "The following items are included: ";
        for(int i = 0; i < itemNo; i++) {
            if(visited.at(i) == true) {
                std::cout << "[" << weights.at(i) << "," << values.at(i) << "] ";
            }
        }
        std::cout << std::endl;
        return 0;
    }
    catch(std::runtime_error &excpt) {
        std::cout << excpt.what() << argv[1] << std::endl;
        return 0;
    }
}