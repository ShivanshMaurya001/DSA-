class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        if(n== 1){
            return nums[0];
        }
        
        int maxi = 0;

        for(int i = 0; i<n; i++){
            int pro = 1;
            for(int j = i; j<n; j++){

                pro = pro* nums[j];
                
                maxi = max(maxi,pro);


            }
        }
        return maxi;
    }
};