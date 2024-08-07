#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> visited(V,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
        PQ.push({0,0});
        
        int ans =0;
        while(!PQ.empty())
        {
            int node = PQ.top().second;
            int wt = PQ.top().first;
            PQ.pop();
            if(!visited[node])
            {
                visited[node]=1;
                ans+=wt;
            }
            else continue;
            for(auto it : adj[node])
            {
                int nNode = it[0];
                int nWt = it[1];
                if(!visited[nNode])
                {
                    PQ.push({nWt,nNode});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
