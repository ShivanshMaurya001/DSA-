class Solution {
public:
    bool ispal(vector<char>& ans) {

        int st = 0;
        int e = ans.size() - 1;

        while (st <= e) {

            if (ans[st] != ans[e]) {
                return false;
            }

            st++;
            e--;
        }

        return true;
    }

    bool isPalindrome(string s) {

        vector<char> ans;

        for (int i = 0; i < s.size(); i++) {

            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9')) {

                ans.push_back(s[i]);
            }
        }
        for (int i = 0; i < ans.size(); i++) {

            if (ans[i] >= 'A' && ans[i] <= 'Z') {
                ans[i] = ans[i] + 32;
            }
        }

        bool x = ispal(ans);
        return x;
    }
};