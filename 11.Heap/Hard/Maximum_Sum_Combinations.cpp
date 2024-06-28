#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &A, vector<int> &B, int C) {
        // Sorting arrays A and B in descending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        // Max-heap to store (sum, index_A, index_B) tuples
        priority_queue<tuple<int, int, int>> pq;
        
        // Initialize the heap with sums of the first elements from A and all elements from B
        for (int i = 0; i < A.size(); ++i) {
            pq.push({ A[i] + B[0], i, 0 });
        }
        
        // Result vector to store the maximum C valid sum combinations
        vector<int> result;
        
        // Extract C maximum sum combinations
        while (C-- > 0 && !pq.empty()) {
            auto [sum, idx_A, idx_B] = pq.top();
            pq.pop();
            result.push_back(sum);
            
            // Push the next element from A with the same element from B
            if (idx_B + 1 < B.size()) {
                pq.push({ A[idx_A] + B[idx_B + 1], idx_A, idx_B + 1 });
            }
        }
        
        return result;
    }
};

int main() {
    // Example input
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int C = 4;

    // Create a Solution object
    Solution sol;
    
    // Get the maximum sum combinations
    vector<int> result = sol.solve(A, B, C);
    
    // Print the result
    cout << "The maximum " << C << " sum combinations are:" << endl;
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}
