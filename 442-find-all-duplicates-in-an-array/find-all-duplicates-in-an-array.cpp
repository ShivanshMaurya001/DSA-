class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        

        unordered_map<int,int>mp;

        for(int i = 0; i<nums.size(); i++){

            mp[nums[i]]++;
        }
        vector<int>ans;

        for(auto x: mp){

            if(x.second >1){
                ans.push_back(x.first);
            }
        }
        return ans;

        // for(int i = 0; i<nums.size(); i++){

        //     if(mp[nums[i]>1]){

        //         ans.push_back(nums[i]);

        //         mp[nums[i]]--;
        //     }
        // }
        return ans;
    }
};
