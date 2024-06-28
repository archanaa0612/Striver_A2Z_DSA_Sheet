/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class MatrixOfLinkedLists {
private:
    vector<vector<ListNode*>> matrix;
    int rows, cols;

public:
    MatrixOfLinkedLists(int r, int c) : rows(r), cols(c) {
        matrix.resize(rows,vector<ListNode*>(cols, nullptr));
    }

    void addNode(int row, int col, int value) {
        if (row >= rows || col >= cols) {
            throw out_of_range("Index out of bounds");
        }
        ListNode* newNode = new ListNode(value);
        if (matrix[row][col] == nullptr) {
            matrix[row][col] = newNode;
        } else {
            ListNode* current = matrix[row][col];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
  }

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int row = lists.size();
        priority_queue<int,vector<int>,greater<int>> minPQ;

        for(int i =0;i<row;i++)
        {
            ListNode* temp = lists[i];
            while(temp!=NULL)
            {
                minPQ.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* head = NULL;
        ListNode* temp = NULL;

        while(!minPQ.empty())
        {
            if(head==NULL)
            {
                ListNode* newNode = new ListNode(minPQ.top());
                minPQ.pop();
                head = newNode;
                temp = newNode;
            }
            else
            {
                ListNode* newNode = new ListNode(minPQ.top());
                minPQ.pop();
                temp->next = newNode;
                temp=temp->next;
            }
        } 
        return head;
    }
};

int main() {
    MatrixOfLinkedLists matrix(3, 3);
    matrix.addNode(0, 0, 1);
    matrix.addNode(0, 0, 2);
    matrix.addNode(0, 1, 3);
    matrix.addNode(1, 1, 4);
    matrix.addNode(2, 2, 5);
    Solution sol;
    sol.mergeKLists(matrix,5);
    

    return 0;
}
