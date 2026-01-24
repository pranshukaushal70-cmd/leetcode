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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        int middle = n / 2;
        temp = head;
        for (int i = 0; i < middle - 1; i++) {
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;

    }
};