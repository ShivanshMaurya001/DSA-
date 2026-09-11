class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i = 0; i < s1.size(); i++){
            mp1[s1[i]]++;
        }

        int left = 0;   int right = 0;

        while(right < s2.size()){

            mp2[s2[right]]++;

            if(right - left + 1 > s1.size()){
                mp2[s2[left]]--;

                if(mp2[s2[left]] == 0){
                    mp2.erase(s2[left]);
                }
                left++;
            }

            if(right - left + 1 == s1.size()){
                if(mp1 == mp2){
                    return true;
                }
            }

            right++;
        }

        return false;
    }
};