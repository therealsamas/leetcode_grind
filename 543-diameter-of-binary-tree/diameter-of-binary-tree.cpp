class Solution {
public:
    int glob_max=0;
    int diameter(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = diameter(root->left);
        int right = diameter(root->right);
        glob_max = max(glob_max,left+right);
        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return glob_max;
    }
};