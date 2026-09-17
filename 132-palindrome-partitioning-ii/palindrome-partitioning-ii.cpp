class Solution {
public:

    bool isPalindrome(string &s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    int solve(int i, string &s, vector<int> &dp) {

        int n = s.size();

        // end tak pahuch gaye
        if(i == n) {
            return -1;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int ans = n;

        for(int j = i; j < n; j++) {

            if(isPalindrome(s, i, j)) {

                int cuts = 1 + solve(j + 1, s, dp);

                ans = min(ans, cuts);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};