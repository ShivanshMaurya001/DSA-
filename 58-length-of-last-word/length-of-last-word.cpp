class Solution {
public:
    int lengthOfLastWord(string s) {

       stringstream ss(s);

       string word;   vector<string>ans;

       while(ss>>word ){

        ans.push_back(word);
       }

       reverse(ans.begin(), ans.end());

       return ans[0].size();
    }
};