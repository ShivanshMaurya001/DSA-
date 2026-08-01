class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1;
        vector<string> v1;   vector<string> ans;

        stringstream ss1(s1);    string word;

        while (ss1 >> word) {
            v1.push_back(word);
        }
        stringstream ss2(s2);

        while (ss2 >> word) {
            v1.push_back(word);
        }
        for (int i = 0; i < v1.size(); i++) {
            mp1[v1[i]]++;
        }
        for (int i = 0; i < v1.size(); i++) {
            if(mp1[v1[i]] == 1){
                ans.push_back(v1[i]);
            }
        }
        return ans;
    }
};