
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ath = list1;
        while(a>1){
            ath = ath->next;
            a--;
            b--;
        }
        ListNode* bth = ath;
        while(b>=0){
            bth = bth->next;
            b--;
        }
        ath->next = list2;
        ListNode* trav = list2;
        while(trav->next != NULL){
            trav = trav->next;
        }
        trav->next = bth;
        return list1;
    }
};