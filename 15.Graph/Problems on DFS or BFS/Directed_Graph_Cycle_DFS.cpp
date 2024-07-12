#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool dfs(int node , vector<int> adj[],vector<int>& visited,vector<int>& pathVis)
    {
        if(visited[node]==1 && pathVis[node]==1) return true;
        visited[node]=1;
        pathVis[node]=1;
        for(auto it : adj[node])
        {
            bool ans = dfs(it,adj,visited,pathVis);
            if(ans) return ans;
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVis(V,0);
        
        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans = dfs(i,adj,visited,pathVis);
                if(ans) return ans;
            }
        }
        return false;
    }
};



int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
