class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int odd = 0;
        int count = 0;

        vector<int> freq(nums.size() + 1, 0);

        freq[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] % 2 != 0) {
                odd++;
            }

            if (odd >= k) {
                count = count + freq[odd - k];
            }

            freq[odd]++;
        }

        return count;
    }
};