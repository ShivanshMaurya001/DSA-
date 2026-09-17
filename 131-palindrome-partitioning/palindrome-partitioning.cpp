class Solution {
public:

    bool isPalindrome(string s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(string s, int start, vector<string>& path,
               vector<vector<string>>& ans) {

        if(start == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i = start; i < s.size(); i++) {

            if(isPalindrome(s, start, i)) {

                path.push_back(s.substr(start, i - start + 1));

                solve(s, i + 1, path, ans);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        solve(s, 0, path, ans);

        return ans;
    }
};