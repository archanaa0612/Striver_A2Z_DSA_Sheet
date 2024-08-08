/*
Time Complexity: O(n).
Auxiliary Space: O(n).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int,int> mp;
        int sum =0;
        int ans =0;
        mp[0] = 0;
        for(int i =0;i<N;i++)
        {
            sum+=A[i];
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i+1;
            }
            int rem = sum-k;
            if(mp.find(rem)!=mp.end())
            {
                ans = max(ans,i-mp[rem]+1);
            }
        }
        return ans;
    } 

};

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
