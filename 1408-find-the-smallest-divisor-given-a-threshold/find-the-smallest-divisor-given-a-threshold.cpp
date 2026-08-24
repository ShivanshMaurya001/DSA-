class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        int left = 1;
        int right = maxi;

        while(left < right) {

            int mid = left + (right - left) / 2;

            int sum = 0;

            for(int i = 0; i < n; i++) {
                sum = sum + (nums[i] + mid - 1) / mid;
            }

            if(sum <= threshold) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};