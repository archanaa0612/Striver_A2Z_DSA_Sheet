#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> minTime(n+1,-1);
        minTime[k]=0;
        
        // to store time, node
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> PQ;
        PQ.push({0,k});

        while(!PQ.empty())
        {
            int time = PQ.top().first;
            int node = PQ.top().second;
            PQ.pop();
            for(auto it : adj[node])
            {
                int nNode = it.first;
                int nTime = it.second+time;
                if(minTime[nNode]==-1 || minTime[nNode]>nTime)
                {
                    PQ.push({nTime,nNode});
                    minTime[nNode]=nTime;
                }
            }
        }
        int ans = INT_MIN;
        for(int i =1;i<=n;i++)
        {
            if(minTime[i]==-1) return -1;
            ans = max(ans,minTime[i]);
        }
        return ans;
    }
};





int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> times;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            times.push_back(temp);
        }
        
        k;
        cin>>k;
        Solution obj;
        cout<<obj.networkDelayTime(times,n,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
