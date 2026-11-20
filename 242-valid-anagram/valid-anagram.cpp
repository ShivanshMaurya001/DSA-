class Solution {
public:
    bool isAnagram(string s, string t) {

        if(t.size() != s.size()){
            return false;
        }

        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;


        for(int i = 0; i<s.size(); i++){

            mp1[s[i]]++;
        }
        for(int i = 0; i<t.size(); i++){

            mp2[t[i]]++;
        }

        for(int i = 0; i<s.size(); i++){

            if(mp1[s[i]] != mp2[s[i]]){
                return false;
            }
            mp1[s[i]]--;
            mp2[s[i]]--;
        }
        return true;  
    }
};
// unordered_map<char,int>mp1;
//         unordered_map<char,int>mp2;


//         for(int i = 0; i<s.size(); i++){

//             mp1[s[i]- 'a']++;
//         }
//         for(int i = 0; i<t.size(); i++){

//             mp2[s[i]- 'a']++;
//         }

//         for(int i = 0; i<s.size(); i++){

//             if(mp1[s[i]] != mp2[s[i]]){
//                 return false;
//             }
//             mp1[s[i]]--;
//             mp2[s[i]]--;
//         }
//         return true;






// int freq1[26] = {0};
//         int freq2[26] = {0};

//         for(int i = 0; i<s.size(); i++){

//             freq1[s[i] - 'a']++;
//         }
//         for(int i = 0; i<t.size(); i++){

//             freq2[s[i] - 'a']++;
//         }
//         for(int i = 0; i<26; i++){

//             if(freq1[i] != freq2[i]){

//                 return false;
//             }
//         }
//         return true;






// int freq1[26] = {0};
//         int freq2[26] = {0};

//         for(int i = 0; i<s.size(); i++){

//             freq1[s[i] - 'a']++
//         }
//         for(int i = 0; i<t.size(); i++){

//             freq2[s[i] - 'a']++
//         }
//         for(int i = 0; i<26; i++){

//             if(freq1[i] != freq2[i]){

//                 return false;
//             }
//         }
//         return true;