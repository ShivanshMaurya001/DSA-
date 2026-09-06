class Solution {
public:
    int findStudents(vector<int>& nums, int maxPages) {

        int students = 1;
        int pagestudent = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (pagestudent + nums[i] <= maxPages) {
                pagestudent += nums[i];
            } else {
                students++;
                pagestudent = nums[i];
            }
        }

        return students;
    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        if (k > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());

        int high = 0;

        for (int i = 0; i < n; i++) {
            high += nums[i];
        }

        int ans = -1;

        while (low <= high) {

            int maxPages = low + (high - low) / 2;

            int students = findStudents(nums, maxPages);

            if (students <= k) {
                ans = maxPages;
                high = maxPages - 1;
            } else {
                low = maxPages + 1;
            }
        }

        return ans;
    }
};



int countStudents(vector<int> &arr, int pages) {

    int students = 1;
    long long pagesStudent = 0;

    for(int i = 0; i < arr.size(); i++) {

        if(pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            students++;
            pagesStudent = arr[i];
        }
    }

    return students;
}


int findPages(vector<int> &arr, int n, int m) {

    if(m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());

    int high = 0;

    for(int i = 0; i < arr.size(); i++) {
        high += arr[i];
    }

    while(low <= high) {

        int mid = (low + high) / 2;

        int students = countStudents(arr, mid);

        if(students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}