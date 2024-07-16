#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    // Create adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    // Queue to store stops, cost, node
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, src});

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    while (!Q.empty()) {
        int stops = Q.front().first.first;
        int cost = Q.front().first.second;
        int node = Q.front().second;
        Q.pop();

        for (auto it : adj[node]) {
            int nNode = it.first;
            int nCost = cost + it.second;

            if (stops<= K && nCost < distance[nNode]) {
                distance[nNode] = nCost;
                Q.push({{stops + 1, nCost}, nNode});
            }
        }
    }

    if (distance[dst] == INT_MAX) return -1;
    return distance[dst];
}

};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
