//Time Complexity : O(n)
//Space Complexity of the provided solution is O(k), where k is the number of unique characters in the string


#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charFrequency; // Map to store character frequencies
        int start = 0; // Left pointer of the sliding window
        int end = 0; // Right pointer of the sliding window
        int maxLength = 0; // Variable to store the maximum length of substring

        // Iterate over the string with the right pointer
        while (end < s.size()) {
            charFrequency[s[end]]++; // Increment the frequency of the current character

            // If the size of the map is equal to the window size, all characters are unique
            if (charFrequency.size() == end - start + 1) {
                maxLength = std::max(maxLength, end - start + 1); // Update the maximum length
                end++; // Expand the window by moving the right pointer
            }
            // If the size of the map is less than the window size, there are duplicates
            else if (charFrequency.size() < end - start + 1) {
                // Shrink the window from the left until all characters are unique
                while (charFrequency.size() < end - start + 1) {
                    charFrequency[s[start]]--; // Decrement the frequency of the character at the left pointer
                    if (charFrequency[s[start]] == 0) {
                        charFrequency.erase(s[start]); // Remove the character from the map if its frequency is zero
                    }
                    start++; // Move the left pointer to the right
                }
                end++; // Expand the window by moving the right pointer
            }
        }
        return maxLength; // Return the maximum length of the substring without repeating characters
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters in \"" << s << "\" is " << sol.lengthOfLongestSubstring(s) <<endl;

    s = "bbbbb";
    cout<< "Length of longest substring without repeating characters in \"" << s << "\" is " << sol.lengthOfLongestSubstring(s) <<endl;
    return 0;
}
