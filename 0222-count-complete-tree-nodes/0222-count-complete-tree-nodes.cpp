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
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;

        int lh=findleftheight(root);
        int rh=findrightheight(root);

        if(lh==rh)
        return (1<<lh)-1;//2 power lh
        
        return 1+countNodes(root->left)+countNodes(root->right); 
    }

    int findleftheight(TreeNode* node){
        int h=0;
        while(node!=NULL){
            h++;
            node=node->left;
        }
        return h;
    }

    int findrightheight(TreeNode* node){
        int h=0;
        while(node!=NULL){
            h++;
            node=node->right;
        }
        return h;
    }
};