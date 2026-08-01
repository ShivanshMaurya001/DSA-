class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;

        vector<string> v1;
        vector<string> v2;
        vector<string> ans;

        stringstream ss1(s1);
        string word;

        while (ss1 >> word) {
            v1.push_back(word);
        }

        stringstream ss2(s2);

        while (ss2 >> word) {
            v2.push_back(word);
        }

        for (int i = 0; i < v1.size(); i++) {
            mp1[v1[i]]++;
        }

        for (int i = 0; i < v2.size(); i++) {
            mp2[v2[i]]++;
        }

        for (int i = 0; i < v1.size(); i++) {
            if (mp1[v1[i]] == 1 && mp2[v1[i]] == 0) {
                ans.push_back(v1[i]);
            }
        }
        for (int i = 0; i < v2.size(); i++) {
            if (mp2[v2[i]] == 1 && mp1[v2[i]] == 0) {
                ans.push_back(v2[i]);
            }
        }

        return ans;
    }
};