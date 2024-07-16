#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(end%100000==start) return 0; 
        queue<pair<int,int>> Q;
        vector<int> dis(100000,1e9);
        dis[start]=0;
        Q.push({0,start});
        
        while(!Q.empty())
        {
            int node = Q.front().second;
            int step = Q.front().first;
            Q.pop();
            
            for(auto it : arr)
            {
                int value = (node*it)%100000;
                if(step+1<dis[value])
                {
                    dis[value]=step+1;
                    if(value==end) return step+1;
                    Q.push({step+1,value});
                }
            }
        }
        return -1;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}
