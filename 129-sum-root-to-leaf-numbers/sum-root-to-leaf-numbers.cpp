
class Solution {
public:
    int ans=0;
    void sumhelper(TreeNode* root, int num){
        if(root==NULL){
            return;
        }
        num = num*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            ans+=num;
            return;
        }
        sumhelper(root->left, num);
        sumhelper(root->right, num);
    }
    int sumNumbers(TreeNode* root){
        sumhelper(root,0);
        return ans;
    }
};