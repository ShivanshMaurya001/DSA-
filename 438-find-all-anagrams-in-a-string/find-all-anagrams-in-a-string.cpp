class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (s.size() < p.size()) {
            return ans;
        }

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        for (int i = 0; i < p.size(); i++) {
            freqP[p[i] - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++) {

            freqS[s[right] - 'a']++;

            if (right - left + 1 > p.size()) {

                freqS[s[left] - 'a']--;

                left++;
            }
            if (freqS == freqP) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};