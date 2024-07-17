#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int climbStairs(int n)
    {
        // your code here
         int a = 1;
        int b=0;
        for(int i =n-1;i>=0;i--)
         {
            int c = (a+b)%mod;
            b=a;
            a=c;
         }
        return a;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.climbStairs(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
