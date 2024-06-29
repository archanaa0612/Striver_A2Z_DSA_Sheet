class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || minHeap.empty())
        {
            maxHeap.push(num);
        }
        else if(maxHeap.top()<num) minHeap.push(num);
        else maxHeap.push(num);
        while(minHeap.size()>maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        while(maxHeap.size()>minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

    }
    
    double findMedian() {
        double ans;
        if(maxHeap.size()==minHeap.size())
        {
            ans = (1.0*maxHeap.top()+1.0*minHeap.top())/2.0;
            return ans;
        }
        return 1.0*maxHeap.top();

    }
};


int main()
{
   MedianFinder* obj = new MedianFinder();
   obj->addNum(1);
   obj->addNum(2);
   double param_2 = obj->findMedian();
   cout<<"Median of data till now  "<<param_2<<endl;
   obj->addNum(3);
   param_2 = obj->findMedian();
  cout<<"Median of data till now  "<<param_2<<endl;
  return 0;
}
