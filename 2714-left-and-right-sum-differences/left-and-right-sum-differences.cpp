class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int leftsum = 0;
        vector<int> ans1;
        vector<int> ans2;
        int rightsum = 0;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            leftsum = leftsum + nums[i];
            ans1.push_back(leftsum);
        }

        for (int i = n - 1; i >= 0; i--) {
            rightsum = rightsum + nums[i];

            ans2.push_back(rightsum);
        }
        reverse(ans2.begin(), ans2.end());

        for (int i = 0; i < n; i++) {

            int sum = abs(ans1[i] - ans2[i]);

            ans.push_back(sum);
        }
        return ans;
    }
};