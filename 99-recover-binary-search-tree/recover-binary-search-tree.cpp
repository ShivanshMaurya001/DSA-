/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderStore(TreeNode* root, vector<int>& arr){
        if(root == NULL) return;

        inorderStore(root->left, arr);
        arr.push_back(root->val);
        inorderStore(root->right, arr);
    }

    void replace(TreeNode* root, vector<int>& arr, int& i){
        if(root == NULL) return;

        replace(root->left, arr, i);
        
        root->val = arr[i]; 
        i++;
        
        replace(root->right, arr, i);
    }

    void recoverTree(TreeNode* root) {
        
        vector<int> arr;

        inorderStore(root, arr);


        sort(arr.begin(), arr.end());

        int i = 0;
        replace(root, arr, i);
    }
};