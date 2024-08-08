/*
Time Complexity  : O(n*log(n) + m*log(m))) 
Space Complexity : O(n+m)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set<int> st;
        for(int i =0;i<n;i++) st.insert(arr1[i]);
        for(int j =0;j<m;j++) st.insert(arr2[j]);
        
        vector<int> ans;
        for(auto it : st) ans.push_back(it);
        return ans;
    }
};



int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
