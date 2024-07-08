//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    vector<vector<int>> helper(vector<vector<int>> adj,int V)
    {
        vector<vector<int>> adjList(V);
        for(int i =0;i<V;i++)
        {
            for(int j =0;j<V;j++)
            {
                if(i!=j && adj[i][j])
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        return adjList;
    }
    
    void dfs(int node , vector<int> &visited,vector<vector<int>> adjList)
    {
        visited[node]=1;
        for(auto it : adjList[node])
        {
            if(!visited[it]) dfs(it,visited,adjList);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adjList =helper(adj,V);
        int ans =0;
        vector<int> visited(V,0);
        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(i,visited,adjList);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
