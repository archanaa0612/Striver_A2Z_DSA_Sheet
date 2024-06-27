//There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
//In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
//Your score is the sum of the points of the cards you have taken.
//Given the integer array cardPoints and the integer k, return the maximum score you can obtain.




/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans =0;
        int leftSum  = 0;
        int rightSum = 0;
        for(int i =0;i<k;i++)
        {
           leftSum+=cardPoints[i];
        }
        ans = max(ans,leftSum+rightSum);
        int rightIndex=n-1;
        for(int i =k-1;i>=0;i--)
        {
           leftSum=leftSum-cardPoints[i];
           rightSum=rightSum+cardPoints[rightIndex];
           rightIndex--;
           ans=max(ans,leftSum+rightSum);
        }
        return ans;
    }
};


int main()
{
  Solution sol;
  vector<int> cardPoints = {1,2,3,4,5,6,1};
  int k = 3;
  int ans = sol.maxScore(cardPoints,k);
  cout<<"the maximum score that can be  obtain  "<<ans<<endl;
  return 0;
}
