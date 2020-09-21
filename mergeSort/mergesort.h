#include <vector>
using namespace std;

template <typename T> void sorting(vector<T> &data, int i, int j, int k) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition

   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   vector<T> mergedNumbers;
   
   // Add smallest element from left or right partition to merged data
   while (leftPos <= j && rightPos <= k) {
      if (data.at(leftPos) < data.at(rightPos)) {
         mergedNumbers.push_back(data.at(leftPos));
         ++leftPos;
      }
      else {
         mergedNumbers.push_back(data.at(rightPos));
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged data
   while (leftPos <= j) {
      mergedNumbers.push_back(data.at(leftPos));
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged data
   while (rightPos <= k) {
      mergedNumbers.push_back(data.at(rightPos));
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to data
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      data.at(i + mergePos) = mergedNumbers.at(mergePos);
   }
}

template <typename T> void mergeSort(vector<T> &data, int i, int k) {
   int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      mergeSort(data, i, j);
      mergeSort(data, j + 1, k);
      
      // Merge left and right partition in sorted order
      sorting(data, i, j, k);
   }
}

