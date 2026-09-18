class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int>ans1;  vector<int>ans2; vector<int>ans;

        for(int i = 0; i<n; i++){

            ans1.push_back(nums[i]);
        }
        for(int i = n; i<nums.size(); i++){

            ans2.push_back(nums[i]);
        }

        int i = 0;
        int j = 0;

        while(i<ans1.size() && j<ans2.size()){

            ans.push_back(ans1[i]);
            ans.push_back(ans2[i]);
            i++; j++;
        }

        return ans;
    }
};