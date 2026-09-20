class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int>arr = nums;

        sort(arr.begin(), arr.end());

        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){

            for(int j = 0; j < arr.size(); j++){

                if(arr[j] == nums[i]){

                    ans.push_back(j);
                    break;
                }
            }
        }

        return ans;
    }
};