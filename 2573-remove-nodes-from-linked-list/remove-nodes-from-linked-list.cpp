class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        while(cur != NULL){
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        ListNode* temp = NULL;
        while(!stack.empty()){
            cur = stack.top();
            stack.pop();
            cur->next = temp;
            temp = cur;
        }
        return cur;
    }
};