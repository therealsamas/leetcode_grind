
class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth==1){
            TreeNode temp = new TreeNode(val);
            temp.left = root;
            return temp;
        }
        Queue<TreeNode> pending = new LinkedList<>();
        pending.add(root);
        int level = 0;
        while(pending.size()>0){
            int len = pending.size();
            if(level==depth-2){
                break;
            }
            for(int i=0; i<len; i++){
                TreeNode cur = pending.peek();
                pending.remove();
                if(cur.left != null){
                    pending.add(cur.left);
                }
                if(cur.right != null){
                    pending.add(cur.right);
                }
            }
            level++;
        }
        while(pending.size()>0){
            TreeNode temp = new TreeNode(val);
            TreeNode cur = pending.peek();
            System.out.println(cur.val);
            pending.remove();
            if(cur.left != null){
                temp.left = cur.left;
            }
            cur.left = temp;
            TreeNode tempr = new TreeNode(val);
            if(cur.right != null){
            tempr.right = cur.right;
            }
            cur.right = tempr;
        }
        return root;
    }
}
