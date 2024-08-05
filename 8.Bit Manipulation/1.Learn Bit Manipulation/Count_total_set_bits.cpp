#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSetBits(int n) {
    if (n == 0) return 0; 

    int x = floor(log2(n));
    int power = pow(2, x);
    int ans = (power / 2) * x + (n - power + 1);

    return ans + countSetBits(n - power);
}
};



int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
