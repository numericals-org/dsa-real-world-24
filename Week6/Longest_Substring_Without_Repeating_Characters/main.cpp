#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> charSet;
    int left = 0;
    int right = 0;
    int maxLength = 0;

    while (right < s.length()) {
        // YOUR CODE HERE:
        // 1. While the character s[right] is already in charSet:
        //    - Remove s[left] from charSet
        //    - Increment left
        while(charSet.count(s[right])){
            charSet.erase(s[left]);
            left++;
        }
        
        // 2. Add s[right] to charSet
        charSet.insert(s[right]);
        
        // 3. Update maxLength = std::max(maxLength, right - left + 1)
        maxLength = std::max(maxLength, right-left + 1 );
        
        // 4. Increment right
        right++;
    }

    return maxLength;
}

int main() {
    std::cout << "abcabcbb: " << lengthOfLongestSubstring("abcabcbb") << std::endl; // Expected: 3
    std::cout << "bbbbb: " << lengthOfLongestSubstring("bbbbb") << std::endl;        // Expected: 1
    std::cout << "pwwkew: " << lengthOfLongestSubstring("pwwkew") << std::endl;      // Expected: 3
    
    return 0;
}