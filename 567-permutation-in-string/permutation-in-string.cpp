class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m)
            return false;

        vector<int> freq1(26, 0);

        for(int i = 0; i < n; i++)
        {
            freq1[s1[i] - 'a']++;
        }

        for(int i = 0; i <= m - n; i++)  // ye looop me galti huyi thi
        {
            vector<int> freq2(26, 0);

            for(int j = i; j < i + n; j++)
            {
                freq2[s2[j] - 'a']++;
            }

            if(freq1 == freq2)
                return true;
        }

        return false;
    }
};