/*
Time Complexity  : O(n)
Space Complexity : O(n)
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int rob(int nums[], int n)
    {
        // Your code here
       
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i = n-3;i>=0;i--)
        {
            dp[i] = max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};


int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.rob(a,n)<<endl;
	}
	return 0;
}
