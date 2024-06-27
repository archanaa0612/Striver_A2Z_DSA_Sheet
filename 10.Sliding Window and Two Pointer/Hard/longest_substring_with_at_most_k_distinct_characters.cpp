//Time Complexity : O(n)
//Space Complexity : O(k) where k is the number of distinct characters we want in the substring.  


#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> map;
        int n = s.size();
        int i = 0, j = 0;
        int ans = -1;

        while (j < n) {
            map[s[j]]++;
            
            // Check if the current window has exactly k distinct characters
            if (map.size() == k) {
                ans = max(ans, j - i + 1);
            }
            
            // If the current window has more than k distinct characters, shrink the window from the left
            while (map.size() > k) {
                if (map[s[i]] > 1) {
                    map[s[i]]--;
                } else if (map[s[i]] == 1) {
                    map.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};


// Example usage
int main() {
    Solution sol;
    string s = "aabacbebebe";
    int k = 3;

    int result = sol.longestKSubstr(s, k);
    cout << "The length of the longest substring with exactly " << k << " distinct characters is " << result <<endl;

    return 0;
}
