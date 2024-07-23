#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    bool helper(vector<int> arr, int index,int sum)
    {
        if(sum==0) return 1;
        if(index==0) return arr[0]==sum;
       
        
        bool notTake = helper(arr,index-1,sum);
        bool take = false;
        if(arr[index]<=sum) take = helper(arr,index-1,sum-arr[index]);
        
        return notTake || take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        if(sum==0) return 1;
        int n = arr.size();
        
        return helper(arr,n-1,sum);
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
}
