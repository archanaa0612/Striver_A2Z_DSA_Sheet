#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> distance(N,-1);
        distance[0]=0;
        
        // to store child node and weight
        vector<vector<pair<int,int>>> adj(N);
        
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        // min heap {weight , node};
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> PQ;
        PQ.push({0,0});
        
        while(!PQ.empty())
        {
            int node = PQ.top().second;
            int dis  = PQ.top().first;
            PQ.pop();
            
            for(auto it : adj[node])
            {
                int V = it.first;
                int nDist = it.second+dis;
                
                if(distance[V]==-1)
                {
                    distance[V]=nDist;
                    PQ.push({nDist,V});
                }
                else if(distance[V]!=-1 && distance[V]>nDist)
                {
                    distance[V]=nDist;
                    PQ.push({nDist,V});
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
