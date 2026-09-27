#include <iostream>
#include <vector>
#include <algorithm> // for std::max

int maxSumSubarray(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1; // Edge case

    // 1. Calculate the sum of the very first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;

    // 2. Slide the window across the rest of the array
    for (int i = k; i < n; i++) {
        // YOUR CODE HERE:
        // 1. Subtract the element leaving the window (arr[i - k])
            windowSum = windowSum - arr[i-k];
        // 2. Add the element entering the window (arr[i])
            windowSum = windowSum + arr[i];
        // 3. Update maxSum using std::max(maxSum, windowSum)
        maxSum = std::max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    std::vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    std::cout << "Max Sum: " << maxSumSubarray(arr, k) << std::endl; // Expected: 9
    return 0;
}