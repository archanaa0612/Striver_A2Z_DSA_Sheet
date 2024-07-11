#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[V];

        for(auto it : prerequisites)
        {
            adj[it.first].push_back(it.second);
        }
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
	    return cnt==V;
	}
};



int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
