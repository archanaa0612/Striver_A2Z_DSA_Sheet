#include<bits/stdc++.h>
using namespace std;

/*======================================================================================*/
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> grp(V,-1);
        queue<int> Q;

        for(int i =0;i<V;i++)
        {
            if(grp[i]==-1)
            {
                Q.push(i);
                grp[i]=1;
                while(!Q.empty())
                {
                    int node = Q.front();
                    Q.pop();

                    for(auto it : adj[node])
                    {
                        if(grp[it]==-1)
                        {
                            if(grp[node]==1) grp[it]=0;
                            else grp[it]=1;
                            Q.push(it);
                        }
                        else if(grp[it]!=-1 && grp[it]==grp[node]) return false;
                    }
                }
            }
        }
        return true;
	}

};
/*=================================================================================================*/

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
