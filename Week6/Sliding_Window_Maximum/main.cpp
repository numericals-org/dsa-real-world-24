#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> result;
    std::deque<int> dq; // Stores INDICES

    for (int i = 0; i < nums.size(); i++)
    {

        // 1. Remove indices from the BACK if their values are <= current value
        // YOUR CODE HERE (while loop)
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back(); // Remove index from the BACK
        }

        // 2. Add current index to the BACK
        // YOUR CODE HERE
        dq.push_back(i);

        // 3. Remove index from the FRONT if it's outside the window
        // YOUR CODE HERE (if statement)
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // 4. Record the maximum (the front of the deque) once the first window is complete
        // YOUR CODE HERE (if statement checking if i >= k - 1)
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main()
{
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> res = maxSlidingWindow(nums, k);

    std::cout << "Output: [";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << (i == res.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    return 0;
}