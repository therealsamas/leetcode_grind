
class Solution {
public:
    int ans;
    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return 0;
    }
    void sumhelper(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left != NULL && isleaf(root->left)){
            ans+= root->left->val;
        }
        sumhelper(root->left);
        sumhelper(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        ans=0;
        sumhelper(root);
        return ans;
    }
};