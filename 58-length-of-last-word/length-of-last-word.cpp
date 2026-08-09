class Solution {
public:
    int lengthOfLastWord(string s) {

        reverse(s.begin(), s.end());

        int i = 0;
        int count = 0;

        while (i < s.length() && s[i] == ' ') {

            i++;
        }
        while (i < s.length() && s[i] != ' ') {
            count++;
            i++;
        }
        return count;
    }
};