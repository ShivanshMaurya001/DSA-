class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int maxi = INT_MIN;
        int secondMax = INT_MIN;
        int index = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > maxi) {

                secondMax = maxi;
                maxi = nums[i];
                index = i;
            }
            else if (nums[i] > secondMax) {

                secondMax = nums[i];
            }
        }

        if (maxi >= 2 * secondMax) {
            return index;
        }

        return -1;
    }
};