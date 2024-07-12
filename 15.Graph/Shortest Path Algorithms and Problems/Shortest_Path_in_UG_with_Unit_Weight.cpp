#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        
        for(int i =0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(N,-1);
        ans[src]=0;
        
        queue<pair<int,int>> Q;
        Q.push({src,0});
        
        
        while(!Q.empty())
        {
            int node = Q.front().first;
            int len  = Q.front().second;
            Q.pop();
            
            for(auto it : adj[node])
            {
                if(ans[it]==-1 && it!=src)
                {
                    ans[it]=len+1;
                    Q.push({it,len+1});
                }
            }
        }
        return ans;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
