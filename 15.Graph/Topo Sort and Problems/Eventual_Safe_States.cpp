#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        //1. Reverse all the edges
        vector<vector<int>> revAdj(V);
        for(int i =0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                revAdj[it].push_back(i);
            }
        }
        
        // calculate inDegree
        vector<int> inDegree(V,0);
        for(int i =0;i<V;i++)
        {
            for(auto it : revAdj[i])
            {
                inDegree[it]++;
            }
        }
        
        queue<int> Q;
        
        for(int i =0;i<V;i++)
        {
            if(inDegree[i]==0) Q.push(i);
        }
        
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for(auto it : revAdj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0) Q.push(it);
            }
        }
        vector<int> safeNode;
        for(int i =0;i<V;i++)
        {
            if(inDegree[i]==0) safeNode.push_back(i);
        }
        return safeNode;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}
