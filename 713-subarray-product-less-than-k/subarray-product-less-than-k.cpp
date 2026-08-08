class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int i = 0;   int j = 0;
        int ans = 1; int count = 0;   int n = nums.size();

          if(k <= 1)
            return 0;

        while(j < n) {

            ans = ans * nums[j];

            while(ans >= k) {
                ans = ans / nums[i];
                i++;
            }

            count = count + (j - i + 1);  // yaha galti huyi thi

            j++;
        }

        return count;
    }
};