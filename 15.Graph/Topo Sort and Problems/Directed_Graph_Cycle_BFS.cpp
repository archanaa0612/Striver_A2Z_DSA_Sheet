#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here// code here
	    vector<int> inDegree(V,0);
	    
	    for(int i =0;i<V;i++)
	    {
	        for(auto it : adj[i])
	        {
	            inDegree[it]++;
	        }
	    }
	    
	    queue<int> Q;
	    int cnt=0;
	    for(int i =0;i<V;i++)
	    {
	        if(!inDegree[i]) Q.push(i);
	    }
	    
	    while(!Q.empty())
	    {
	        int node = Q.front();
	        Q.pop();
	        cnt++;
	        for(auto it : adj[node])
	        {
	            inDegree[it]--;
	            if(!inDegree[it]) Q.push(it);
	        }
	    }
	    return !(cnt==V);
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
