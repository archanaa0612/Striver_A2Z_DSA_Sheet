/*
Time Complexity: O(n+m).
Auxiliary Space: O(n+m).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int index = -1;
        int i =0,j=0;
        while(i<n && j<m)
        {
            if(arr1[i]<= arr2[j])
            {
                if(index==-1 || arr1[i]!=ans[index])
                {
                    ans.push_back(arr1[i]);
                    index++;
                }
                i++;
            }
            else
            {
                if(index==-1 || arr2[j]!=ans[index])
                {
                    ans.push_back(arr2[j]);
                    index++;
                }
                j++;
            }
        }
        
        while(i<n)
        {
           if(index==-1 || arr1[i]!=ans[index])
                {
                    ans.push_back(arr1[i]);
                    index++;
                }
                i++;
        }
        
        while(j<m)
        {
             if(index==-1 || arr2[j]!=ans[index])
                {
                    ans.push_back(arr2[j]);
                    index++;
                }
                j++;
        }
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
