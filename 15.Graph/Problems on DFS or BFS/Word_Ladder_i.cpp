#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> set;
        for(string s : wordList) set.insert(s);
        
        auto it = set.find(targetWord);
        if(it==set.end()) return 0;
        
        queue<pair<string,int>> Q;
        Q.push({startWord,1});
        
        while(!Q.empty())
        {
            string word = Q.front().first;
            int len = Q.front().second;
            Q.pop();
            if(word==targetWord) return len;
            int n = word.size();
            for(int i =0;i<n;i++)
            {
                string temp = word;
                for(int j =0;j<26;j++)
                {
                    temp[i] = 'a'+j;
                    //cout<<temp<<endl;
                    auto it = set.find(temp);
                    if(it!=set.end())
                    {
                        Q.push({temp,len+1});
                    }
                }
            }
            set.erase(word);
        }
        return 0;
    }
};


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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
