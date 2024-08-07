/*
Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;


int noOfDigits(int n)
{
	int cnt =0;
	while(n>0)
	{
		cnt++;
		n=n/10;
	}
	return cnt;
}

bool checkArmstrong(int n){
	if(n==0 || n==1)
	{
		return true;
	}
	int nos = noOfDigits(n);
	int b =n;
	int a =0;
	while(n>0)
	{
		a = a+pow(n%10,nos);
		n=n/10;
	}
	return a==b;
}

int main()
{
  int n;
  cin>>n;

  bool ans =checkArmstrong(n);
  cout<<ans;
  return 0;
}
