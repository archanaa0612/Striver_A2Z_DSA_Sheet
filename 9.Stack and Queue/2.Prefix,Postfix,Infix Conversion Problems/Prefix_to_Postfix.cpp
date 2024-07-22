#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
   bool isOperator(char c)
   {
       if(c=='+' || c== '-' || c=='*' || c=='/' || c=='^') return true;
       return false;
   }
   

    string preToPost(string pre_exp) {
        stack<string> stack;
        int n = pre_exp.size();
        
        for(int i = n-1;i>=0;i--)
        {
            if(isOperator(pre_exp[i]))
            {
                string op1 = stack.top(); stack.pop();
                string op2 = stack.top(); stack.pop();
                string res = op1+op2+pre_exp[i];
                stack.push(res);
            }
            else stack.push(string(1,pre_exp[i]));
        }
        return stack.top();
    }
};


int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
