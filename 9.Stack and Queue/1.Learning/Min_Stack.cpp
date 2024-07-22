
#include <bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack<pair<int,int>> s;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(val<mini) mini = val;
        s.push({val,mini});
    }
    
    void pop() {
        if(s.top().second==mini)
        s.pop();
        if(!s.empty()) mini = s.top().second;
        else mini = INT_MAX;
        
    }


    int getMin() {
        int ans = s.top().second;
        return ans;
    }

    int top() {
        int ans = s.top().first;
        return ans;
    }
    

};




int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        MinStack ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              ob.pop();
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
           else if(qt==4)
           {
              cout<<ob.top()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
