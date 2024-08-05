/*
Time Complexity  : O(1)
Space Complexity : O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        return  (n>0 && (n & (n-1))==0) ? true:false;
    }
};

int main()
{
  int n;
  cin>>n;

  Solution obj;
  bool ans = obj.isPowerOfTwo(n);
  cout<<ans;
}
