class Solution {
public:

    bool treehelper(TreeNode* p, TreeNode* q){
        if((q==NULL || p==NULL) && (p != NULL || q != NULL)){
            return 0;
        }
        if((p==NULL && q==NULL)){
            return 1;
        }
        bool left=0, right = 0;
        left = treehelper(p->left,q->left);
        right = treehelper(p->right, q->right);
        return ((p->val == q->val) & left & right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return treehelper(p,q);
    }
};