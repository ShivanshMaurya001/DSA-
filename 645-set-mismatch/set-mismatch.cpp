class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int n = nums.size();


        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1]) {
                ans.push_back(nums[i]);
                break;
            }
        }

        int expected = 1;

        for (int i = 0; i < n; i++) {

            if (nums[i] == expected) {
                expected++;
            }
            else if (nums[i] > expected) {
                ans.push_back(expected);
                break;
            }
        }

        if (ans.size() == 1) {
            ans.push_back(n);
        }

        return ans;
    }
};