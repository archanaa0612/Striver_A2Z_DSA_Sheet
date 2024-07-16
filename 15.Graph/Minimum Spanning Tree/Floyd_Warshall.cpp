#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
        void shortest_distance(vector<vector<int>>& matrix) {
            int V = matrix.size();
            
            // Initialization: Replace -1 with a large value, except for the diagonal
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (matrix[i][j] == -1 && i != j) {
                        matrix[i][j] = INT_MAX;
                    }
                }
            }
            
            // Floyd-Warshall algorithm
            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                    }
                }
            }
        
            // Replace large values back to -1 to indicate no path
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (matrix[i][j] == INT_MAX) {
                        matrix[i][j] = -1;
                    }
                }
            }
        }

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
