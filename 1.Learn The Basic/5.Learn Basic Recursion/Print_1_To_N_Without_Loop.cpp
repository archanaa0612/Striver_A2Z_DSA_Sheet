/*
Time Complexity: O(n).
Auxiliary Space: O(n) (Recursive).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void printNos(int N)
    {
        if(N==1)
        {
            cout<<N<<" ";
            return;
        }
        printNos(N-1);
        cout<<N<<" ";
    }
};

int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}
