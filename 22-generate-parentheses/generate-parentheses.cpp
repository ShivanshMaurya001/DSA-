class Solution {
public:
    void solve(int n, int open, int close, string ans, vector<string>& result) {

        if (open == n && close == n) {
            result.push_back(ans);
            return;
        }

        if (open < n) {
            solve(n, open + 1, close, ans + '(', result);
        }

        if (close < open) {
            solve(n, open, close + 1, ans + ')', result);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        int open = 0;
        int close = 0;
        string ans = "";

        solve(n, open, close, ans, result);

        return result;
    }
};