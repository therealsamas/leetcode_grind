class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        n = len-n;
        if(n==0){
            return head->next;
        }
        temp = head;
        while(n>1){
            temp = temp->next;
            n--;
        }
        temp->next = temp->next->next;
        return head;
    }
};