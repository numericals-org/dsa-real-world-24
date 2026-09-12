#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1); // Default all to -1
    std::stack<int> st; // This stack will store INDICES, not values!

    for (int i = 0; i < n; i++) {
        // While stack is not empty AND current number is greater than 
        // the number at the index stored at the top of the stack:
        while (!st.empty() && nums[i] > nums[st.top()]) {
            // We found the next greater element for the index at st.top()!
            int index = st.top();
            st.pop();
            result[index] = nums[i]; // Record the answer
        }
        
        // Push the current index onto the stack
        st.push(i);
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 1, 2, 4, 3};
    std::vector<int> res = nextGreaterElement(nums);
    
    std::cout << "Input:  [2, 1, 2, 4, 3]" << std::endl;
    std::cout << "Output: [";
    for(int i=0; i<res.size(); i++) {
        std::cout << res[i] << (i == res.size()-1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    
    return 0;
}