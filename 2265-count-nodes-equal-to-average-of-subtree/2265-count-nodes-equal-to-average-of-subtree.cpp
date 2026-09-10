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
int count(TreeNode* &root){
    if(root==NULL){
        return 0;
    }
    int leftCount=count(root->left);
    int rightCount=count(root->right);
    return 1+leftCount+rightCount;
}
int preorder(TreeNode* &root,int &ans){
    if (root == nullptr) {
            return 0;
        }
 int leftSub=preorder(root->left,ans);
  
  int rightSub=preorder(root->right,ans);
  int totalSum=leftSub+rightSub+root->val;
  int total=count(root);
  if(totalSum/total==root->val){
    ans++;
  }
  return totalSum;
 
}
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
       preorder(root,ans); 
       return ans;
       
    }
};