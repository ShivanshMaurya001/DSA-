class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int sec = 0;  int index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                index = i;
            }
        }

        for (int i = 0; i < n; i++) {

            if (  nums[i]> sec && index != i){
                sec = nums[i];  
            }
        }

        return (maxi-1) * (sec-1);
    }
};