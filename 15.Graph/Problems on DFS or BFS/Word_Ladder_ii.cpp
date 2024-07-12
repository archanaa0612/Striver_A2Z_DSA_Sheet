#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (set.find(endWord) == set.end()) return ans;

        queue<vector<string>> Q;
        Q.push({beginWord});

        bool found = false;
        unordered_set<string> visitedThisLevel;

        while (!Q.empty() && !found) {
            int levelSize = Q.size();
            for (int i = 0; i < levelSize; ++i) {
                vector<string> path = Q.front();
                Q.pop();
                string word = path.back();

                for (int j = 0; j < word.size(); ++j) {
                    string temp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[j] = c;
                        if (set.find(temp) != set.end()) {
                            vector<string> newPath = path;
                            newPath.push_back(temp);
                            if (temp == endWord) {
                                ans.push_back(newPath);
                                found = true;
                            } else {
                                Q.push(newPath);
                                visitedThisLevel.insert(temp);
                            }
                        }
                    }
                }
            }

            for (const string& word : visitedThisLevel) {
                set.erase(word);
            }
            visitedThisLevel.clear();
        }

        return ans;
    }
};


//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
