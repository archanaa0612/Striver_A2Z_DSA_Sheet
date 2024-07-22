#include<bits/stdc++.h>
using namespace std;



class Queue {
    stack<int> stack1, stack2;
public:

    void enqueue(int x) {
        if(stack1.empty()) stack1.push(x);
        else{
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack1.push(x);
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }

    int dequeue() {
         if(stack1.empty()) return -1;
        int ans = stack1.top();
        stack1.pop();
        return ans;
    }

   int peek() {
        return stack1.top();
    }
    
    bool empty() {
        return stack1.empty();
    }

};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        else if(QueryType==3)
        {
            cout<<ob.peek()<<" ";

        }

       else if(QueryType==4)
        {
            cout<<ob.empty()<<" ";

        }
             
        
        }
    cout<<endl;
    }
}
