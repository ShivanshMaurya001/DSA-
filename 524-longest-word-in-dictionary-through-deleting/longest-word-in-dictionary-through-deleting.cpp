class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        string ans = "";

        for (int k = 0; k < dictionary.size(); k++) {

            string word = dictionary[k];

            int i = 0;
            int j = 0;

            while (i < s.size() && j < word.size()) {

                if (s[i] == word[j]) {
                    i++;
                    j++;
                }
                else {
                    i++;
                }
            }
            if (j == word.size()) {

                if (word.size() > ans.size()) {
                    ans = word;
                }
                else if (word.size() == ans.size() && word < ans) {
                    ans = word;// ye line ble topo me jo pahle aya ha vahi hoga if len same  practise 
                }
            }
        }

        return ans;
    }
};
