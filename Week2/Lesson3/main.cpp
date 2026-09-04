#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &nums, int target)
{
    int left = 0, right = static_cast<int>(nums.size() - 1);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int findFirstOccurrence(const std::vector<int> &nums, int target)
{
    int left = 0, right = static_cast<int>(nums.size() - 1), ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return ans;
}

int findLastOccurrence(const std::vector<int> &nums, int target)
{
    int left = 0, right = static_cast<int>(nums.size() - 1), ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return ans;
}

int lowerBound(const std::vector<int> &nums, int target)
{
    int left = 0, right = static_cast<int>(nums.size() - 1), ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return ans;
}

int upperBound(const std::vector<int> &nums, int target)
{
    int left = 0, right = static_cast<int>(nums.size() - 1), ans = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return ans;
}

int main()
{
    return 0;
}