#include <iostream>
#include <cassert>
#include <vector>

int dayInYear(int day, int month, int year) {
    std::vector<int> daysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapYear;
    int totalDays = 0;

    for(int i = 0; i < month - 1; i++) {
        totalDays += daysPerMonth.at(i);
    }
    if(month > 2 && year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                totalDays++;
            }
        }
        else {
            totalDays++;
        }
    }
    totalDays += day;
    return totalDays;
}
