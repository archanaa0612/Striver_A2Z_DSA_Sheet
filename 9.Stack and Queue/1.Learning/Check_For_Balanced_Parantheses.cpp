#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool isValid(string s)
    {
        // Your code here
        stack<char> st;
        int n=s.size();

        for(int i =0;i<n;i++)
        {
            if(st.empty()){
                st.push(s[i]);
            }
            else if((st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') 
            || (st.top()=='[' && s[i]==']')) st.pop();

            else st.push(s[i]);
        }
        return st.empty();
    }

};



int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.isValid(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
