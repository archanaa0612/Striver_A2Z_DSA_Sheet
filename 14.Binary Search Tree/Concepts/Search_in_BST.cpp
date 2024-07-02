#include <bits/stdc++.h>
using namespace std;

struct Node {
    int   val;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node* searchBST(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->val) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->val) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}



Node* searchBST(Node* root, int val) {
    // Your code here
        if(root==NULL) return NULL;
        if(root->val==val) return root
        if(val<root->val) 
        {
            return searchBST(root->left,val);
        }
        else return searchBST(root->right,val);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << searchBST(root, s);
        cout << endl;
    }
}
