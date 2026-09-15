class Solution {
public:
    int findComplement(int num) {

        vector<int> ans;

        while(num > 0) {

            int digit = num % 2;
            ans.push_back(digit);

            num = num / 2;
        }

        vector<int> ans2;

        for(int i = 0; i < ans.size(); i++) {

            if(ans[i] == 1) {
                ans2.push_back(0);
            }
            else {
                ans2.push_back(1);
            }
        }

        int val = 0;
        int long long power = 1;

        for(int i = 0; i < ans2.size(); i++) {

            val = val + ans2[i] * power;
            power = power * 2;
        }

        return val;
    }
};