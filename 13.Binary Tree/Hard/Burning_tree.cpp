#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


=======================================================================================================================================
class Solution {
  public:
    Node* parentMapping(Node* root , unordered_map<Node*,Node*>& map,int target)
    {
        Node* targetNode = NULL;
        queue<Node*> Q;
        Q.push(root);
        map[root]=NULL;
        while(!Q.empty())
        {
            Node* front = Q.front();
            Q.pop();
            if(front->data==target) targetNode = front;
            
            if(front->left!=NULL)
            {
                map[front->left]=front;
                Q.push(front->left);
            }
            if(front->right!=NULL)
            {
                map[front->right] = front;
                Q.push(front->right);
            }
        }
        return targetNode;
    }
    
    int timeToBurn(Node* root,unordered_map<Node*,Node*>& map)
    {
        int ans =0;
        queue<Node*> Q;
        Q.push(root);
        unordered_map<Node* , bool> visited;
        visited[root]=true;
        
        while(!Q.empty())
        {
            bool flag = false;
            int n = Q.size();
            for(int i =0;i<n;i++)
            {
              Node* front = Q.front();
              Q.pop();
            if(front->left && !visited[front->left])
            {
                Q.push(front->left);
                flag = true;
                visited[front->left]=true;
                
            }
            if(front->right && !visited[front->right])
            {
                Q.push(front->right);
                flag = true;
                visited[front->right]=true;
            }
            if(map[front] && !visited[map[front]])
            {
                Q.push(map[front]);
                flag = true;
                visited[map[front]] = true;
            }
            }
            if(flag) ans++;
        }
        return ans;
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL) return 0;
        unordered_map<Node* , Node*> map;
        Node* targetNode = parentMapping(root,map,target);
        return timeToBurn(targetNode,map);
        
    }
};
===============================================================================================================================================

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
