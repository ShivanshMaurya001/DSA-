class Solution {
public:
    vector<string> commonChars(vector<string>& words) {//practise it ....

        // First string ki frequency store karega
        vector<int> commonFreq(26, 0);

        // First string ki frequency
        for(int i = 0; i < words[0].size(); i++)
        {
            commonFreq[words[0][i] - 'a']++;
        }

        // Baaki sab strings ke liye
        for(int i = 1; i < words.size(); i++)
        {
            vector<int> freq(26, 0);

            // Current string ki frequency
            for(int j = 0; j < words[i].size(); j++)
            {
                freq[words[i][j] - 'a']++;
            }

            // Minimum frequency rakho
            for(int j = 0; j < 26; j++)
            {
                commonFreq[j] = min(commonFreq[j], freq[j]);
            }
        }

        vector<string> ans;

        // Answer banao
        for(int i = 0; i < 26; i++)
        {
            while(commonFreq[i] > 0)
            {
                string s = "";
                s += (char)(i + 'a');  // ans store karne ko bhi dekh lena

                ans.push_back(s);

                commonFreq[i]--;
            }
        }

        return ans;
    }
};