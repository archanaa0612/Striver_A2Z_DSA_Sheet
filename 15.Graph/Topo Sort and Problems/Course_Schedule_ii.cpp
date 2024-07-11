#include <bits/stdc++.h>
using namespace std;



class Solution
{
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> adj[n];

        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        //int V = numCourses;
        vector<int> inDegree(n,0);
	    
	    for(int i =0;i<n;i++)
	    {
	        for(auto it : adj[i])
	        {
	            inDegree[it]++;
	        }
	    }
	    
	    queue<int> Q;
	    vector<int> ans;
	    for(int i =0;i<n;i++)
	    {
	        if(!inDegree[i]) Q.push(i);
	    }
	    
	    while(!Q.empty())
	    {
	        int node = Q.front();
	        Q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node])
	        {
	            inDegree[it]--;
	            if(!inDegree[it]) Q.push(it);
	        }
	    }
	    if(ans.size()==n) return ans;
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
