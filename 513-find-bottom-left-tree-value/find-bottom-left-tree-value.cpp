class Solution {
public:

    int glob_max = -1;
    int ans;
    void treehelper(TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        if(depth>glob_max){
            glob_max = depth;
            ans = root->val;
        }
        treehelper(root->left,depth+1);
        treehelper(root->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        ans = root->val;
        treehelper(root,0);
        return ans;
    }
};