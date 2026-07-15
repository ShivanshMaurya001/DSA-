
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
         //  Store hua ha vo {frequency, number} ble sort 1st ko hi karta ha
        vector<pair<int, int>> freq;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            freq.push_back({it->second, it->first});
        }
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};