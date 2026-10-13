
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            int curr = asteroids[i];

            bool alive = true;

            while (alive && curr < 0 &&
                   !st.empty() && st.top() > 0) {

                if (st.top() < -curr) {
                    st.pop();
                }

                else if (st.top() == -curr) {
                    st.pop();
                    alive = false;
                }

                else {
                    alive = false;
                }
            }

            if (alive) {
                st.push(curr);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
