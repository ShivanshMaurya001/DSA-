class Solution {
public:
    int hammingWeight(int n) {

        vector<int>ans;

        while(n>0){

            int val = n%2;
            ans.push_back(val);
            n = n/2;
        }
        int count = 0;

        for(int i = 0; i<ans.size(); i++){

            if(ans[i]== 1){
                count++;
            }
        }
        return count;
        
    }
};