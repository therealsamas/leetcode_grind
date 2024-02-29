
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        bool flag = 0;
        queue<TreeNode*> pending;
        pending.push(root);
        while(!pending.empty()){
            int len = pending.size();
            int prev;
            flag = !flag;
            if(flag==0){
                prev = INT_MAX;
            }else{
                prev = -1;
            }
            if(flag){
                for(int i=0; i<len; i++){
                    TreeNode* cur = pending.front();
                    pending.pop();
                    if((cur->val)%2==0 || cur->val <= prev){
                        return 0;
                    }
                    prev = cur->val;
                    if(cur->left != NULL){
                        pending.push(cur->left);
                    }
                    if(cur->right != NULL){
                        pending.push(cur->right);
                    }
                }
            }else{
                for(int i=0; i<len; i++){
                    TreeNode* cur = pending.front();
                    pending.pop();
                    if((cur->val)%2 != 0 || cur->val >= prev){
                        return 0;
                    }
                    prev = cur->val;
                    if(cur->left != NULL){
                        pending.push(cur->left);
                    }
                    if(cur->right != NULL){
                        pending.push(cur->right);
                    }
                }
            }
        }
        return 1;
    }
};