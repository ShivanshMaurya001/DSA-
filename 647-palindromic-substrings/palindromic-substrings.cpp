class Solution {
public:
    int countSubstrings(string s, int i , int j) {
        int count = 0;

        while(i>= 0 && j<s.length() && s[i]== s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s){
        int count = 0;
        int center;

        for(int center= 0; center<s.length(); center++){
            int oddans = countSubstrings(s,center,center);

            int evenans = countSubstrings(s,center,center+1);

            count = count + oddans + evenans;
        }
        return count;
    }
};