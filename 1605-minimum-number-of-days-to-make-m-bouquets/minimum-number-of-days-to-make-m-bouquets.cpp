class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int count = 0;     
        int bouquets = 0;  

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                count++;
            }
            else {

                bouquets += count / k;

                count = 0;
            }
        }
        bouquets += count / k;

        if(bouquets >= m) {
            return true;
        }

        return false;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        if(1LL *m * k > bloomDay.size()) {
            return -1;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < bloomDay.size(); i++) {

            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)) {

                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};