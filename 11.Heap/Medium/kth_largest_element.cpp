#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i : nums)
        {
            pq.push(i);
        }
        for(int i =1;i<k;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};

int main()
{
  vector<int> nums = {3,2,1,5,6,4};
  int k = 2;
  int ans = (nums,k);
  cout<<"Kth Largest element in the given array is : "<<ans<<endl;
  return 0;
}
