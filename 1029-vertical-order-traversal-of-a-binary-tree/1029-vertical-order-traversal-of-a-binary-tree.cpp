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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> out;                // Final output vector
        map<int, vector<int>> final_mp;         // Map to store vertical column indices and their respective node values
        queue<pair<int, TreeNode*>> q;          
        q.push({0, root});                      

        while (!q.empty()) {
            int n = q.size();
            map<int, vector<int>> mp;           // Temporary map for nodes in the current level

            // Process all nodes in the current level
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                int index = it.first;          
                TreeNode* node = it.second;     

                mp[index].push_back(node->val); // Add node value to the corresponding column in `mp`
                q.pop();

                if (node->left != NULL)
                    q.push({index - 1, node->left});

                if (node->right != NULL)
                    q.push({index + 1, node->right});
            }

            // Process nodes level by level
            for (auto it : mp) {
                sort(it.second.begin(), it.second.end()); // Sort nodes at the same column and level
                vector<int> temp = final_mp[it.first];    // Get existing values for this column
                for (int i = 0; i < it.second.size(); i++) {
                    temp.push_back(it.second[i]);         // Append sorted nodes for this column
                }
                final_mp[it.first] = temp;                // Update the column in the final map
            }
        }

        // Convert the map to a vector of vectors
        for (auto it : final_mp) {
            out.push_back(it.second);
        }

        return out;
    }
};