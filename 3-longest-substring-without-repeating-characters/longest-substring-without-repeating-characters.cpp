class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0; int r = 0;  int maxi = 0;

        unordered_map<char, int> mp;

        while(r<s.size()){

            mp[s[r]]++;

            while(mp[s[r]]>1){

                mp[s[l]]--;
                l++;
            }

            if(maxi < r-l+1){

                maxi = r-l+1;

            }
            r++;
        }
        return maxi;
        
    }
};