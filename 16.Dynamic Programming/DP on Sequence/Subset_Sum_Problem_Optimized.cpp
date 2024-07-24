/*
Time Complexity  : O(n*sum)
Space Complexity : O(sum)
*/

#include<bits/stdc++.h> 
using namespace std; 



class Solution{   
public:
    
    bool isSubsetSum(vector<int> arr, int sum) {
    int n = arr.size();
    
    vector<int> prev(sum+1,0);
    vector<int> cur(sum+1,0);
    
    prev[0]=1;
    cur[0]=1;
    
    
   
    
    
    if (arr[0] <= sum) {
        prev[arr[0]] = 1;
    }
    
    for (int index = 1; index < n; index++) {
        for (int target = 1; target <= sum; target++) {
            int notTake = prev[target];
            int take = 0;
            if (arr[index] <= target) {
                take = prev[target - arr[index]];
            }
            
           cur[target] = notTake | take;
        }
        prev = cur;
    }
    return prev[sum];
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
