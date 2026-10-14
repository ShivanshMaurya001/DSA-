class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1000000007;

        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || arr[st.top()] >= arr[i])) {

                int mid = st.top();
                st.pop();

                int left;

                if (st.empty()) {
                    left = -1;
                } else {
                    left = st.top();
                }

                int right = i;

                long long leftCount = mid - left;
                long long rightCount = right - mid;

                long long contribution =
                    (arr[mid] * leftCount % MOD) * rightCount % MOD;

                ans = (ans + contribution) % MOD;
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};