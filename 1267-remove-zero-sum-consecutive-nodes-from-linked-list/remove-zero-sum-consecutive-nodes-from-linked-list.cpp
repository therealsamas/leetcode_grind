
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int i = 0;
        unordered_map<int, ListNode*> prefs;
        prefs[0] = dummy;
        ListNode* current = head;
        while(current){
            i += current->val;
            if(prefs.find(i) != prefs.end()){
                ListNode* to_delete = prefs[i]->next;
                int temp_sum = i + to_delete->val;
                while (to_delete != current) {
                    prefs.erase(temp_sum);
                    to_delete = to_delete->next;
                    temp_sum += to_delete->val;
                }
                prefs[i]->next = current->next;
            }
            else{
                prefs[i] = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};