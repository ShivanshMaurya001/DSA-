/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preorder(TreeNode* root, string &ans)
    {
        if (root == NULL)
        {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";

        preorder(root->left, ans);

        preorder(root->right, ans);
    }

    string serialize(TreeNode* root)
    {
        string ans = "";

        preorder(root, ans);

        return ans;
    }

    TreeNode* build(vector<string> &arr, int &i)
    {
        if (arr[i] == "N")
        {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(arr[i]));

        i++;

        root->left = build(arr, i);

        root->right = build(arr, i);

        return root;
    }

    TreeNode* deserialize(string data)
    {
        vector<string> arr;

        string temp = "";

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',')
            {
                arr.push_back(temp);
                temp = "";
            }
            else
            {
                temp += data[i];
            }
        }

        int i = 0;

        return build(arr, i);
    }
};