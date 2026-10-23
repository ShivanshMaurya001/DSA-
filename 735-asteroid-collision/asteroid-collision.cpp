
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // Stack mein surviving asteroids store karenge
        stack<int> st;

        // Har asteroid ko left se right process karo
        for (int i = 0; i < asteroids.size(); i++) {

            int curr = asteroids[i];

            // Initially current asteroid alive hai
            bool alive = true;

            // Collision tabhi possible hai jab:
            // stack top positive ho aur current negative ho
            while (alive && curr < 0 &&
                   !st.empty() && st.top() > 0) {

                // Agar stack top ka size chhota hai,
                // toh stack top destroy hoga
                if (st.top() < -curr) {
                    st.pop();
                }

                // Dono ka size equal hai
                else if (st.top() == -curr) {
                    st.pop();
                    alive = false;
                }

                // Stack top bada hai,
                // current asteroid destroy hoga
                else {
                    alive = false;
                }
            }

            // Agar current asteroid survive karta hai,
            // tabhi stack mein push karenge
            if (alive) {
                st.push(curr);
            }
        }

        // Stack ko array mein convert karo
        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
