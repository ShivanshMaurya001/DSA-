class Solution {
public:
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();

        // Step 1: Sort positions in increasing order
        // Taaki hum balls ko left to right place kar sakein.
        sort(position.begin(), position.end());


        // Step 2: Define binary search range

        // Minimum possible distance = 1
        int left = 1;

        // Maximum possible distance:
        // Last position - First position
        // Ye dono extreme positions ke beech ka maximum gap hai.
        int right = position[n-1] - position[0];


        // Step 3: Binary Search
        // Humein maximum possible minimum distance find karna hai.
        while(left < right) {

            // Upper mid use kar rahe hain.
            // Kyunki valid hone par left = mid karenge.
            int mid = left + (right - left + 1) / 2;


            // Step 4: Check whether we can place
            // all m balls with at least 'mid' distance.

            // First ball ko first position par place kar diya.
            int balls = 1;

            // Last placed ball ki position store karenge.
            int lastPosition = position[0];


            // Baaki positions check karenge.
            for(int i = 1; i < n; i++) {

                // Check karo ki current position aur
                // last placed ball ke beech distance
                // mid ya usse zyada hai ya nahi.
                if(position[i] - lastPosition >= mid) {

                    // Distance valid hai, ek aur ball place kar do.
                    balls++;

                    // Ab current position last placed position ban jayegi.
                    lastPosition = position[i];
                }
            }


            // Step 5: Update binary search range

            // Agar m ya usse zyada balls place ho gayi,
            // toh mid distance possible hai.
            if(balls >= m) {

                // Humein aur bada minimum distance try karna hai.
                left = mid;
            }

            else {

                // Itni distance par required balls place nahi ho paayi.
                // Isliye distance kam karna padega.
                right = mid - 1;
            }
        }


        // Step 6: left == right
        // Ye maximum possible minimum distance hai.
        return left;
    }
};