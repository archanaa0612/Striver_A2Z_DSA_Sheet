/*
Time Complexity : O(n)
Space Complexity: O(1)
*/

#include<bits/stdc++.h> 
using namespace std;


class Solution{
public:
    int evenlyDivides(int N){
        int temp = N;
        int ans =0;
        while(temp>0)
        {
            int a = temp%10;
            if(a!=0 && N%a==0) ans++;
            temp/=10;
        }
        return ans;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
