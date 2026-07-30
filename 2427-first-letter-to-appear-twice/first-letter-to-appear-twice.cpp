class Solution {
public:
    char repeatedCharacter(string s) {
        int freq[256] = {0};  char ans = 0;

        for (int i = 0; i < s.size(); i++) {

            freq[s[i]]++;

            if (freq[s[i]] > 1) {
                ans =  s[i];
                break;
            }
        }
        return ans;
    }
};