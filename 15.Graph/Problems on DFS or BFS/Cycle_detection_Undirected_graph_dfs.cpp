#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node , vector<int> adj[],int parent,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                bool ans = dfs(it,adj,node,visited);
                if(ans) return ans;
            }
            else if(visited[it] && it!=parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        
        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans = dfs(i,adj,-1,visited);
                if(ans) return ans;
            }
        }
        return false;
    }
};


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
