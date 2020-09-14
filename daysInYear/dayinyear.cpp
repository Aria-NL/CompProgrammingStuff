#include <iostream>
#include <cassert>

int dayInYear(int day, int month, int year);

int main(){
    std::cout << "Starting tests." << std::endl;
 
    assert(dayInYear(1,1,2000) == 1);
    assert(dayInYear(2,1,2000) == 2);
    assert(dayInYear(1,2,2000) == 31+1);
    assert(dayInYear(1,3,1900) == 31+28+1);
    assert(dayInYear(1,3,1904) == 31+29+1);
    assert(dayInYear(1,3,1910) == 31+28+1);
    assert(dayInYear(1,3,2000) == 31+29+1);
    assert(dayInYear(10,4,2010) == 31+28+31+10);
    assert(dayInYear(4,5,2010) == 31+28+31+30+4);
    assert(dayInYear(20,6,2010) == 31+28+31+30+31+20);
    assert(dayInYear(18,7,2010) == 31+28+31+30+31+30+18);
    assert(dayInYear(9,8,2010) == 31+28+31+30+31+30+31+9);
    assert(dayInYear(30,9,2010) == 31+28+31+30+31+30+31+31+30);
    assert(dayInYear(30,9,2020) == 31+29+31+30+31+30+31+31+30);
    assert(dayInYear(3,10,2010) == 31+28+31+30+31+30+31+31+30+3);
    assert(dayInYear(5,11,2010) == 31+28+31+30+31+30+31+31+30+31+5);
    assert(dayInYear(31,12,2000) == 366);
    assert(dayInYear(31,12,2001) == 365);
     
    std::cout << "All tests succeeded!" << std::endl;

    return 0;
}