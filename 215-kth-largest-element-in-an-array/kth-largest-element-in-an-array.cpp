class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){

            if(i+1  == k){
                ans = nums[i];
            }
        }
        return ans;
        
    }
};