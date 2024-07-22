#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    bool isOperator(char c)
   {
       if(c=='+' || c== '-' || c=='*' || c=='/' || c=='^') return true;
       return false;
   }
   
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> stack;
        int n = post_exp.size();
        
        for(int i =0;i<n;i++)
        {
            if(isOperator(post_exp[i]))
            {
                string op1 = stack.top(); stack.pop();
                string op2 = stack.top(); stack.pop();
                string res = post_exp[i]+op2+op1;
                stack.push(res);
            }
            else stack.push(string(1,post_exp[i]));
        }
        return stack.top();
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
