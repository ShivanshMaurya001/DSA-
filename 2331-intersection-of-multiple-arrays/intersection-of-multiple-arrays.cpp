class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {

        int row = nums.size();
        int col = nums[0].size(); vector<int>ans;   unordered_map<int,int>mp;

        for(int i = 0; i<row; i++){
            for(int j = 0;j < nums[i].size(); j++){  // yaha pe jagged or uneven ya agalg alag size ha to 
                ans.push_back(nums[i][j]);   // nums[i].size kiya ha dekh lena budhu
            }
        }
        for(int i = 0;i<ans.size(); i++){
            mp[ans[i]]++;
        }
        vector<int>final;

        for(int i = 0; i<ans.size(); i++){

            if(mp[ans[i]] == row){  //3 nahi hoga multiple array me 3 hi arr ho 
                                        //jaruri nahi ha so row le lo 
                final.push_back(ans[i]);
                mp[ans[i]] = 0;    // jitane row hoge utane time ana chahiye
            }
        }
        sort(final.begin(),final.end());
        return final;

        
    }
};