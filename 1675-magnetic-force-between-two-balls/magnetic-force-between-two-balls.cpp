class Solution {
public:

    bool check(vector<int>& position, int m, int mid) {

        int balls = 1;
        int last = position[0];

        for(int i = 1; i < position.size(); i++) {

            if(position[i] - last >= mid) {
                balls++;
                last = position[i];
            }
        }

        return balls >= m;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int s = 1;
        int e = position[position.size() - 1] - position[0];

        int ans = 0;

        while(s <= e) {

            int mid = s + (e - s) / 2;

            if(check(position, m, mid)) {
                ans = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }
};