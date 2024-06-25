#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
/*====================================Brute Force Approach==============================================================*/    

vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
  /*==================================Optimal Approach using hashMap====================================================*/ 
   
   vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
   }

/*=================================================================================================================*/
};


int main() {
    // Example array and target
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Create an object of the Solution class
    Solution sol;

/*========================================Brute Force Approach=======================================================*/
   
 // Call the twoSumBruteForce function
    vector<int> result1 = sol.twoSumBruteForce(nums, target);

  // Check if a solution was found
    if (!result.empty()) {
        cout << "Indices: " << result1[0] << ", " << result1[1] <<endl;
        cout << "Elements: " << nums[result1[0]] << ", " << nums[result1[1]] <<endl;
    } else {
        cout << "No two sum solution found." <<endl;
    }

        
/*==============================Optimal Approach using hashMap======================================================*/

// Call the twoSum function 
    vector<int> result2 = sol.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result2[0] << ", " << result2[1] <<endl;
        cout << "Elements: " << nums[result2[0]] << ", " << nums[result2[1]] <<endl;
    } else {
        cout << "No two sum solution found." <<endl;
    }

    return 0;
}
