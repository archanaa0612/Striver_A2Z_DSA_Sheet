#include <bits/stdc++.h>
using namespace std;
  
class Solution{
    public:
/*===========================================================================================================*/    
    vector<int> topoSort(vector<vector<int>>& adj,int K)
    {
        vector<int> inDegree(K,0);
        queue<int> Q;
        vector<int> ans;
        for(int i =0;i<K;i++)
        {
            for(auto it : adj[i]) inDegree[it]++;
        }
        for(int i =0;i<K;i++)
        {
            if(inDegree[i]==0)
            {
                Q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for(auto it : adj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0)
                {
                    Q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
/*===========================================================================================================*/  

    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char,int> map;
        for(int i =0;i<K;i++)
        {
            map['a'+i] = i;
        }
        
        vector<vector<int>> adj(K);
        for(int i =0;i<N-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int a =0;
            int b =0;
            while(a<s1.size() && b<s2.size())
            {
                if(s1[a]!=s2[b])
                {
                    adj[map[s1[a]]].push_back(map[s2[b]]);
                    break;
                }
                a++;
                b++;
            }
        }
        
        vector<int> topo = topoSort(adj,K);
        string ans = "";
        for(auto it : topo)
        {
            ans+='a'+it;
        }
        return ans;
    }
};
/*===========================================================================================================*/   

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
