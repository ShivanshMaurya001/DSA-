class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        int i = 0;
        int j = 0;

        int maxi = 0;
        int freq = 0;

        unordered_map<char, int> mp;

        while (j < n) {

            mp[s[j]]++;

            freq = max(freq, mp[s[j]]);

            while (j - i + 1 - freq > k) {

                mp[s[i]]--;
                i++;
            }

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};