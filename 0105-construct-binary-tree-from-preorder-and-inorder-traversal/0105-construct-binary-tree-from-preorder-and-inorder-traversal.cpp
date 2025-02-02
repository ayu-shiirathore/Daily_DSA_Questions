class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd, 
                    map<int, int>& mp) {  // Pass `mp` and `inorder` by reference
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;

        // Recursively build the left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mp);
        root->right = build(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

        return root;
    }
};
