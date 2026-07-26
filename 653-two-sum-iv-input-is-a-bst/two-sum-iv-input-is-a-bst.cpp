class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL) {
            return;
        }

        storeInorder(root->left, arr);
        arr.push_back(root->val);
        storeInorder(root->right, arr);
    }

    bool checkSum(vector<int>& arr, int k) {
        int i = 0;
        int j = arr.size() - 1;

        while(i < j) {
            int sum = arr[i] + arr[j];

            if(sum == k) {
                return true;
            }

            if(sum > k) {
                j--;
            }
            else {
                i++;
            }
        }

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        storeInorder(root, arr);

        bool ans = checkSum(arr, k);
        return ans;
    }
};