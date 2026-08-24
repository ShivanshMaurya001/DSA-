class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();
        int left = 0;
        int right = 0;

        for(int i = 0; i < n; i++) {

            left = max(left, weights[i]);

            right = right + weights[i];
        }
        while(left < right) {

            int mid = left + (right - left) / 2;

            int day = 1;
            int currentWeight = 0;

            for(int i = 0; i < n; i++) {

                currentWeight = currentWeight + weights[i];

                if(currentWeight > mid) {

                    day++;
                    currentWeight = weights[i];
                }
            }
            if(day <= days) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};