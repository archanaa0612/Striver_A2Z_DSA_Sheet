//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>> &image, int initial, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();

        // Ensure sr and sc are within bounds
        if (sr < 0 || sr >= row || sc < 0 || sc >= col) return;
        
        // Return if the current cell is not the initial color
        if (image[sr][sc] != initial) return;

        // Change the color
        image[sr][sc] = newColor;

        // Recursively call dfs on the surrounding cells
        dfs(image, initial, sr, sc - 1, newColor);
        dfs(image, initial, sr, sc + 1, newColor);
        dfs(image, initial, sr + 1, sc, newColor);
        dfs(image, initial, sr - 1, sc, newColor);

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int initial = image[sr][sc];
        
        // Prevent infinite recursion if the initial color is the same as the target color
        if (initial != newColor) {
            dfs(image, initial, sr, sc, newColor);
        }

        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
