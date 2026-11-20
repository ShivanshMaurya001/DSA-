

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans,
               vector<int> &temp, int index) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (index >= candidates.size()) {
            return;
        }

        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);
            solve(candidates, target - candidates[index], ans, temp, index);
            temp.pop_back();
        }

        solve(candidates, target, ans, temp, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;
        vector<vector<int>> ans;
        int index = 0;
        solve(candidates, target, ans, temp, index);
        return ans;
    }
};

// void solve(vector<int>& candidates, int target,  vector<vector<int>>ans,
// vector<int>temp,int &index){

//         if(target == 0){
//             ans.push_back(temp);
//              temp.pop_back();
//         }

//         if(index > candidates.size()){
//             return;
//         }

//         if(candidates[index] <= target){
//             temp.push_back(candidates[index]);
//             solve(candidates, target - candidates[index], ans, temp , index);
//         }

//         solve(candidates, target, ans, temp , index+1);

//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

//         vector<int>temp;
//         vector<vector<int>>ans;
//         int index = 0;
//         solve(candidates,target,ans,temp,index);
//         return ans;
//     }