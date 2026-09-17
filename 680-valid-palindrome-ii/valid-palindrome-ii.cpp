class Solution {
public:

    bool check(string s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            if(s[left] != s[right]) {

                bool ans1 = check(s, left + 1, right);
                bool ans2 = check(s, left, right - 1);

                if(ans1 == true || ans2 == true) {
                    return true;
                }
                else {
                    return false;
                }
            }

            left++;
            right--;
        }

        return true;
    }
};