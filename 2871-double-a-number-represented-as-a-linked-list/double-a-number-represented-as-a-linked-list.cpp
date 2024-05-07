/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:


	int remhead(ListNode* head){
		if(head->next==NULL){
			int temp = (head->val) * 2;
			head->val = temp%10;
			temp/=10;
			return temp;
		}
		int carry = remhead(head->next);
		int num = (head->val) * 2;
		num+=carry;
		head->val = num%10;
		num/=10;
		return num;
	}

    ListNode* doubleIt(ListNode* head) {
        int fcarr = remhead(head);
        if(fcarr!=0){
	    	ListNode* newhead = new ListNode(fcarr);
	    	newhead->next = head;
	    	return newhead;
        }
        return head;
    }
};