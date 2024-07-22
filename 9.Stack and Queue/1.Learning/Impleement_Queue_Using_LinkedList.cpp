#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }


//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        if(front==NULL && rear==NULL)
        {
             QueueNode *newNode = new QueueNode(x);
             rear=newNode;
             front=newNode;
        }
        else{
             QueueNode *newNode = new QueueNode(x);
             rear->next=newNode;
             rear=rear->next;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code     
        if(front==NULL && rear==NULL) return -1;
        else if(rear==front)
        {
            int ans = front->data;
            rear=NULL;
            front=rear;
            return ans;
        }
        else{
            int ans = front->data;
            front=front->next;
            return ans;
        }
}
