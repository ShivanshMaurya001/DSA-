class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        unordered_map<int,int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto x : nums) {
            if (mp[x] == 1) {
                ans.push_back(x);
            }
        }

        int val = 0;

        for (int i = 0; i < ans.size(); i++) {
            val = val + ans[i];
        }

        return val;
    }
};