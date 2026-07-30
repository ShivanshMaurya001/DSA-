class Solution {

public:
    char repeatedCharacter(string s) {

        unordered_map<char, int> mp;
        char ch = 0;

        for (int i = 0; i < s.size(); i++) {

            mp[s[i]]++;

            if (mp[s[i]] > 1) {

                ch = s[i];
                break;
            }
        }
        return ch;
    }
};