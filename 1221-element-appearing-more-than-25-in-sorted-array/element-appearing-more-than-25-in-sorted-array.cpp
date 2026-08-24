class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {

        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {

            mp[arr[i]]++;
        }
        int maxi = 0;
        int ans = 0;

        for (auto x : mp) {

            if (x.second > maxi) {
                maxi = x.second;
                ans = x.first;
            }
        }
        int val = arr.size()/4;

        if(maxi > val){
            return ans;
        }
        return -1;
    }
};