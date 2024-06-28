class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int it : nums) map[it]++;
        
        priority_queue<pair<int,int>> PQ;

        for(auto it : map)
        {
            PQ.push({it.second,it.first});
        }
        
        for(int i =0;i<k;i++)
        {
           pair<int,int> top = PQ.top();
           PQ.pop();
           ans.push_back(top.second);
        }
        return ans;
    }
};

int main()
{
  vector<int> nums={1,1,1,2,2,3};
  int k =2;
  vector<int> ans = topKFrequent(nums,k);
  cout<<"Top K Frequent Elements are  :";
  for(int i : ans)
    {
      cout<<i<<"  ";
    }
  cout<<endl;
}
