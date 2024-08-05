/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
       
        long long int XOR =0;        
        for(long long int i =0;i<N;i++) XOR^=Arr[i];
       
        long long int bits = floor(log2(XOR));
        
        long long int setBit;        
        for(long long int i =0;i<=bits;i++)
        {
            if(XOR & (1<<i))
            {
                setBit = i;
                break;
            }
        }
        
        long long int XOR1=0;
        long long int XOR2=0;
        
        for(long long int i =0;i<N;i++)
        {
            if(Arr[i] & (1<<setBit)) XOR1^=Arr[i];
            else XOR2^=Arr[i];
        }
        
        if(XOR1>XOR2) return {XOR1,XOR2};
        return {XOR2,XOR1};
        
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
