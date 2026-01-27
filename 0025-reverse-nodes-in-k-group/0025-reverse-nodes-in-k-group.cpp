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
    ListNode* reverse(ListNode* temp){
        ListNode* prev=NULL;
        ListNode* front;
        while(temp != NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* findnthnode(ListNode* temp, int k){
        while(temp != NULL && k > 1){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev= NULL;
        ListNode* nextnode;
        while(temp != NULL){
            ListNode* kthnode=findnthnode(temp, k);
            if(kthnode == NULL){
               if(prev) prev->next=temp;
                break;
            }
            nextnode=kthnode->next;
            kthnode->next=NULL;
            ListNode* newhead=reverse(temp);
            if(temp == head){
                head=kthnode;
            }
            else{
                prev->next=newhead;
            }
            prev=temp;
            temp=nextnode;
        }
        return head;
    }
};