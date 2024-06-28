//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // Helper function to heapify a subtree rooted at index i
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;      // Initialize largest as root
        int left = 2 * i + 1; // left child
        int right = 2 * i + 2; // right child
    
        // Check if left child exists and is greater than root
        if (left < n && arr[left] > arr[largest])
            largest = left;
    
        // Check if right child exists and is greater than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;
    
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]); // Swap root and largest
            heapify(arr, n, largest);   // Recursively heapify the affected subtree
        }
    }
    
    // Function to convert a min-heap to a max-heap
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        // Start from the last non-leaf node and heapify each node
        for (int i = N / 2 - 1; i >= 0; i--) {
            heapify(arr, N, i);
        }
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
