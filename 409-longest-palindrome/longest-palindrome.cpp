class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        int ans = 0;
        bool found = false;

        for(auto x : mp){
            int freq = x.second;

            if(freq % 2 == 0){
                ans += freq;
            }
            else{
                ans += freq - 1; 
                found = true;   
            }
        }

        if(found)
        {
            ans= ans + 1;
        }

        return ans;
    }
};     