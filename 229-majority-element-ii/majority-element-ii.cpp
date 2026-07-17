class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        int con = n / 3;

        for (int i = 0; i < n; i++) {

            int temp = nums[i];
            int count = 1;

            for (int j = i + 1; j < n; j++) {
                if (nums[j] == temp) {
                    count++;
                }
            }
            bool found = false;

            for (int k = 0; k < ans.size(); k++) {
                if (ans[k] == temp) {
                    found = true;
                    break;
                }
            }

            if (count > con && !found) {
                ans.push_back(temp);
            }
        }

        return ans;
    }
};