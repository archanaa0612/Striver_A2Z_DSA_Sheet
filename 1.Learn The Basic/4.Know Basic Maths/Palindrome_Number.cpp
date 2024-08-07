#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long reverseDigits(int num) 
{ 
    long rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
} 
    bool isPalindrome(int x) {
         int rev = int(reverseDigits(x));
         return rev==x;
    }
};

int main()
{
  int x;
  cin>>x;
  Solution obj;
  bool ans =  obj.isPalindrome(x);
  if(ans==1) cout<<"true";
  else cout<<"false";
  return 0;
}
