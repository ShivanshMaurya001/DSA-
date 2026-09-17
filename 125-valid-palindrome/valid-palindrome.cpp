class Solution {
public:

    bool ispal(vector<char>& ans) {

        int st = 0;
        int e = ans.size() - 1;

        while (st <= e) {

            if (ans[st] == ans[e]) {
                st++;
                e--;
            }
            else {
                return false;
            }
        }

        return true;
    }

    bool isPalindrome(string s) {

        vector<char> ans;

        for (int i = 0; i < s.size(); i++) {

            if (isalnum(s[i])) {
                ans.push_back(tolower(s[i]));
            }
        }

        bool val = ispal(ans);
        return val;
    }
};