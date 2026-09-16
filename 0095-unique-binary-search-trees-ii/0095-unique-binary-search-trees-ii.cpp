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
    private:
    // Helper function to deep copy a tree while applying an offset to node values
    TreeNode* cloneAndOffset(TreeNode* root, int offset) {
        if (!root) return nullptr;
        
        TreeNode* newNode = new TreeNode(root->val + offset);
        newNode->left = cloneAndOffset(root->left, offset);
        newNode->right = cloneAndOffset(root->right, offset);
        return newNode;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};

        // dp[len] stores root pointers of all unique BSTs for a sequence of length 'len'
        std::vector<std::vector<TreeNode*>> dp(n + 1);
        
        // Base case: empty tree for length 0
        dp[0] = {nullptr};

        // Build DP table for lengths from 1 to n
        for (int len = 1; len <= n; ++len) {
            for (int rootVal = 1; rootVal <= len; ++rootVal) {
                int leftLen = rootVal - 1;
                int rightLen = len - rootVal;

                // Combine each left subtree with each right subtree
                for (TreeNode* leftTree : dp[leftLen]) {
                    for (TreeNode* rightTree : dp[rightLen]) {
                        TreeNode* root = new TreeNode(rootVal);
                        root->left = leftTree;
                        // Right subtree nodes need to be shifted by rootVal
                        root->right = cloneAndOffset(rightTree, rootVal);
                        
                        dp[len].push_back(root);
                    }
                }
            }
        }

        return dp[n];
    }
};