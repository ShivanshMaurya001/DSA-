class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int ans = nums[0];

        for (int i = 0; i < n-1; i++) {

            if (nums[i] < nums[i + 1]) {
                continue;
            } else {
                ans = nums[i + 1];
            }
        }
        return ans;
    }
};