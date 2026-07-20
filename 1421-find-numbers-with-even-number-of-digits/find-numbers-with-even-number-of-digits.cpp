class Solution {
public:
    int findNumbers(vector<int>& nums) {
        vector<int> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i]);
        }
        vector<int> digitCount;

        for (int i = 0; i < arr.size(); i++) {

            int num = arr[i];
            int count = 0;

            while (num > 0) {
                count++;
                num = num / 10;
            }
            digitCount.push_back(count);
        }
        int even = 0;

        for (int i = 0; i < digitCount.size(); i++) {

            if (digitCount[i] % 2 == 0) {
                even++;
            }
        }

        return even;
    }
};