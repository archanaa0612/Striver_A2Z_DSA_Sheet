/*
Time Complexity  : O(sum*n)
Space Complexity : O(sum);
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i =0;i<n;i++) sum+=arr[i];
    
  	int temp = sum;
  	sum = sum/2;
    
	
  	vector<int> prev(sum+1);
  	vector<int> cur(sum+1);
  	prev[0]=1;
  	cur[0]=1;
  	if(arr[0]<=sum) prev[arr[0]]=1;	
  
  	for(int index =1;index<n;index++)
  	{
  		for(int target =1;target<=sum;target++)
  		{
  			int ntake = prev[target];
  			int take = 0;
  			if(arr[index]<=target) take = prev[target-arr[index]];
  			cur[target]= take | ntake;
  		}
  		prev = cur;
  	}
     
  	
  	for(int i =sum;i>=0;i--)
  	{
  		if(prev[i])
  		{
  			return temp-2*i;
  		}
  	}
  	} 
};


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
