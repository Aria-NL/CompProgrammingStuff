# CompProgrammingStuff
My programs for 2020-2021 Computer Programming at the Vrije Universiteit Amsterdam.

# Compilation
Simply use g++ to compile the .cpp.

# Programs
## Rectangle
This program takes a length and width of a rectangle, then outputs its perimeter, area, and diagonal length.

## Collatz
This program takes a starting value then prints the Collatz Sequence from that value until 1 has appeared three times.

## Polish
This program takes an operator and two numbers in Polish notation (operator then number then number) and outputs the answer in standard notation.

## Partial Sum
This program takes a user n value, then a user x value. It then prints the partial sum up to x, and the entire sequence of partial sums up to n.

## Quadratic
This program takes a value from the user for a, b, and c, then uses those values to calculate solutions via the quadratic formula.

### Quadratic-Errors
Different version of Quadratic, with error-checking code.

## Matrix-Vector
This program takes 3 vector coefficients and multiplies them as a matrix with a predefined ascending 3x3 matrix.

## Smallest Missing
This program accepts a size of a vector, vector values, then sorts that vector and finds the smallest missing value.

## Day In Year
This program is slightly different; it consists of a function file and a main file. Both must be used and compiled together to function properly. It does calculations to determine the date in days from a day/month/year format. No user input is allowed unless more test cases are added to the main file.

## Run-Length Encoding (RLE)
This program takes a string of all-lowercase letters and no numbers from the user and compresses it using Run-Length Encoding.

## Merge Sort
This isn't a program - rather, a template function for merge sort. This should work with all the basic datatypes in C++, and takes a vector of values, the beginning point, and the ending point.

## Knapsack
This program is a recursive implementation of the 0-1 Knapsack problem. Numbers should be input into the knapsack1 file, or any text file, then run with the filename as an argument. First line should be knapsack capacity, then the following lines should all follow the format `<weight> <value>`.

## Happy Numbers
This program takes a number from the user and determines whether it is happy or not (see this wikipedia article https://en.wikipedia.org/wiki/Happy_number)

## Maze
This program takes files (see maze1-9) and solves the maze inside them.