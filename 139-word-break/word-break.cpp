class Solution {
public:
    bool solve(string& s, int i, unordered_set<string>& st, vector<int>& dp) {
        if (i == s.size()) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        string temp = "";

        for (int j = i; j < s.size(); j++) {
            temp += s[j];

            if (st.find(temp) != st.end()) {
                if (solve(s, j + 1, st, dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st;

        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }

        vector<int> dp(s.size(), -1);

        return solve(s, 0, st, dp);
    }
};
