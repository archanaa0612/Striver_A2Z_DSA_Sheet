#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q.empty()) q.push(x);
        else
        {
            q.push(x);
            int n = q.size();
            for(int i =1;i<n;i++)
            {
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int ans = q.front();
        q.pop();
        return ans;
    }
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyStack obj;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            obj.push(a);
        }else if(QueryType==2){
            cout<<obj.pop()<<" ";

        }
        }
        cout<<endl;
    }
}

