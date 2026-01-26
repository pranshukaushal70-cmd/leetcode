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
    ListNode* findnthnode(ListNode* temp, int k){
        int cnt=1;
        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail=head;
        int len=1;
        if(head == NULL || head->next == NULL || k == 0) return head;
        while(tail->next != NULL){
            len++;
            tail=tail->next;
        }
        if(k % len == 0) return head;
        k = k % len;
        tail->next=head;

        ListNode* newlastnode = findnthnode(head, len-k);
        ListNode* newhead=newlastnode->next;
        newlastnode->next=NULL;

        return newhead;
    }
};