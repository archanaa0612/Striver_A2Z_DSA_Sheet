#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<vector<int>> minDist(n, vector<int>(n, 1e9));
        minDist[0][0] = 1;

        queue<pair<pair<int, int>, int>> Q;
        Q.push({{0, 0}, 1});

        int delRow[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int delCol[] = {0, 1, -1, 1, -1, 0, 1, -1};

        while (!Q.empty()) {
            int row = Q.front().first.first;
            int col = Q.front().first.second;
            int dist = Q.front().second;
            Q.pop();

            if (row == n-1 && col == n-1) return dist;

            for (int i = 0; i < 8; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow < n && nRow >= 0 && nCol < n && nCol >= 0 && grid[nRow][nCol] == 0) {
                    int nDist = dist + 1;
                    if (minDist[nRow][nCol] > nDist) {
                        minDist[nRow][nCol] = nDist;
                        Q.push({{nRow, nCol}, nDist});
                    }
                }
            }
        }
        return -1;
    }
};



;

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >>n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < n; j++) cin >> grid[i][j];
        Solution ob;
        cout << ob.shortestPathBinaryMatrix(grid) << "\n";
    }
}
