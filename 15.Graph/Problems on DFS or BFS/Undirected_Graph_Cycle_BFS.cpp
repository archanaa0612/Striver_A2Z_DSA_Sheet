//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                queue<pair<int, int>> Q;
                Q.push({i, -1});
                visited[i] = 1;
                
                while (!Q.empty()) {
                    int node = Q.front().first;
                    int parent = Q.front().second;
                    Q.pop();
                    
                    for (auto it : adj[node]) {
                        if (!visited[it]) {
                            Q.push({it, node});
                            visited[it] = 1;
                        } else if (it != parent) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
