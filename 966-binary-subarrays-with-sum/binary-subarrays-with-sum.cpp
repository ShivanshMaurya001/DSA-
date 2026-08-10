class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int sum = 0;

        int count = 0;

        unordered_map<int, int> mp;

        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {

            sum = sum + nums[i];

            int needed = sum - goal;

            if(mp.find(needed) != mp.end()) {
                count = count + mp[needed];
            }

            mp[sum]++;
        }

        return count;
    }
};