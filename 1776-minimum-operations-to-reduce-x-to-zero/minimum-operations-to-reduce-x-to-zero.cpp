class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        int total = 0;

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        int target = total - x;

        if(target < 0) {
            return -1;
        }

        int i = 0;
        int j = 0;

        int sum = 0;
        int maxi = -1;

        while(j < n) {

            sum += nums[j];

            while(i <= j && sum > target) {
                sum -= nums[i];
                i++;
            }

            if(sum == target) {
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }

        if(maxi == -1) {
            return -1;
        }

        return n - maxi;
    }
};