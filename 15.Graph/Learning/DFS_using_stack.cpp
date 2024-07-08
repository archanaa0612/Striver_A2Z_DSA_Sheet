//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        
        vector<int> visited(V,0);
        //visited[0]=1;
        
        stack<int> stack;
        stack.push(0);
        
        while(!stack.empty())
        {
            int node=stack.top();
            stack.pop();
            if(!visited[node])
            {
                visited[node]=1;
                ans.push_back(node);
            }
            
            int n = adj[node].size();
            for(int i = n-1;i>=0;i--)
            {
                if(!visited[adj[node][i]])
                {
                    stack.push(adj[node][i]);
                }
                
                
            }
        }
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
