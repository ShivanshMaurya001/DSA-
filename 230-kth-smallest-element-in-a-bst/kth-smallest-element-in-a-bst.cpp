class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        storeInorder(root->left, ans);
        ans.push_back(root->val);
        storeInorder(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        storeInorder(root, ans);
        return ans[k - 1];
    }
};