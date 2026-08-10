class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int sum = 0;
        int count = 0;   // n2 vaal nahi lagega tle ayega 

        unordered_map<int, int> mp;

        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {

            sum = sum + nums[i];

            int rem = sum % k;

            if(rem < 0) {    // ye line dekh lena baad me 
                rem = rem + k;
            }

            if(mp.find(rem) != mp.end()) {
                count = count + mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }
};