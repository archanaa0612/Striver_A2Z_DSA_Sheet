#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Initialize minEffort matrix with maximum integer values
        vector<vector<int>> minEffort(n, vector<int>(m, INT_MAX));
        minEffort[0][0] = 0;

        // Min-heap priority queue to store (effort, row, col)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        // Direction vectors for moving up, down, left, and right
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int eff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // If we reached the bottom-right corner, return the effort
            if (row == n - 1 && col == m - 1) return eff;

            // Explore all 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // Check if the new position is within bounds
                if (nRow < n && nRow >= 0 && nCol < m && nCol >= 0) {
                    int nEff = max(eff, abs(heights[row][col] - heights[nRow][nCol]));
                    if (nEff < minEffort[nRow][nCol]) {
                        minEffort[nRow][nCol] = nEff;
                        pq.push({nEff, {nRow, nCol}});
                    }
                }
            }
        }
        return -1; // This line should never be reached
    }
};

// Main function to test the Solution class
int main() {
    Solution sol;

    // Taking input for the matrix dimensions
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    // Initializing the matrix
    vector<vector<int>> heights(n, vector<int>(m));
    cout << "Enter the heights matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> heights[i][j];
        }
    }

    // Calling the function and printing the result
    int result = sol.minimumEffortPath(heights);
    cout << "Minimum Effort Path: " << result << endl;

    return 0;
}
