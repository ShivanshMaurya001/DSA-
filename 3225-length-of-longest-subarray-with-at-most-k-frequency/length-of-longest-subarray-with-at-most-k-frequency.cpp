class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int i = 0;    int j = 0;
        int maxi = 0;    int n = nums.size();
        unordered_map<int, int> mp;
        
        while (j < n) {

            mp[nums[j]]++;

            while(mp[nums[j]] > k) {  //while lagega na yaar aur vo bhi j hoga

                mp[nums[i]]--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};