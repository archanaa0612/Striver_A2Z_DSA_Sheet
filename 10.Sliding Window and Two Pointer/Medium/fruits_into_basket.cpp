/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits 
of size N, where fruits[i]  is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has somestrict rules that you must follow :

1.You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.

2.Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of the baskets.

3.Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.
*/

/*
Time Complexity  : O(n)
Space Complexity : O(2)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int totalFruits(int N, vector<int> &fruits) {
          unordered_map<int,int> map;
          
          int i =0,j=0;
          int ans =0;
          
          while(j<N)
          {
              map[fruits[j]]++;
              if(map.size()==2)
              {
                  ans=max(ans,j-i+1);
              }
              while(map.size()>2)
              {
                  if(map[fruits[i]]>1) map[fruits[i]]--;
                  else if(map[fruits[i]]==1) map.erase(fruits[i]);
                  i++;
              }
              j++;
          }
          return ans;
   }
};

int main()
{

  Solution sol;
  vector<int> fruits = { 0, 1, 2, 2, 2, 2 };
  int n = fruits.size();

  int ans = sol.totalFruits(n,fruits);
  cout<<"the maximum number of fruits that can be picked  : "<<ans<<endl;
  return 0;
}
