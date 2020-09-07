#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> getPartialSum(int n) {
    int currentValue = 1;
    std::vector<int> partialVec(n + 1);
    partialVec.at(0) = 1;
    for(int i = 1; i <= n; i++) {
        currentValue += (i + 1);
        partialVec.at(i) = currentValue;
    }
    return partialVec;
}

int main() {
    int userN;
    int userX;
    
    std::cout << "Summing up 1 to n, please enter n: ";
    std::cin >> userN;
    std::cout << "Which partial sum (1+...+x) would you like to know? Please enter x<=n : ";
    std::cin >> userX;
    if(userX > userN) {
        std::cout << "Invalid value. X must be less than or equal to n.";
        return 1;
    }
    std::vector<int> sumResult(userN);
    sumResult = getPartialSum(userN);
    int i;
    for(i = 1; i < userX; i++) {
        std::cout << i << "+";
    }
    std::cout << i << " = " << sumResult.at(userX - 1) << std::endl << "The entire sequence of partial sums up to " << userN << " is: ";
    for(i = 0; i < userN; i++) {
        std::cout << sumResult.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}