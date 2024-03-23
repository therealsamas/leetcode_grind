class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        stack<ListNode*> bucket;
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
        }
        ListNode* temp;
        if(fast!=NULL){
            temp= slow->next;
        }
        else{
            temp= slow;
        }
        while(temp!=NULL){
            bucket.push(temp);
            temp= temp->next;
        }
        fast= head;
        
        while(bucket.size()){
        temp = fast->next; 
        fast->next= bucket.top();
        bucket.top()->next =temp;
        fast=temp;
        bucket.pop();
        }
        slow->next= NULL;
    }
};