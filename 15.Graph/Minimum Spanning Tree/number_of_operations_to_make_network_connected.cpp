#include<bits/stdc++.h>
using namespace std;


class Solution{
    private:
        void dfs(vector<vector<int>>& adj , int node,vector<int>& visited)
         {
          visited[node]=1;
          for(auto it : adj[node])
          {
            if(!visited[it]) dfs(adj,it,visited); 
          }
   }


    public:      
      int minimumConnections(int n , vector<vector<int>> &connections)
    {
            // code here
            if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto it : connections)
        {
            int node1 = it[0];
            int node2 = it[1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        int components=0;
        vector<int> visited(n,0);
        for(int i =0;i<n;i++)
        {
            if(!visited[i])
            {
                components++;
                dfs(adj,i,visited);
            }
        }
    return components-1;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> connections(m,vector<int> (2));
        for(auto &j:connections)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(n,connections)<<endl;
    }
    return 0;
}
