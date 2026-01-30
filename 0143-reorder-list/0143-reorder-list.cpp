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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        if(head == NULL || head->next == NULL) return ;
        ListNode* temp=head;
        while(temp != NULL){
            st.push(temp);
            temp=temp->next;
        }
        int k=st.size()/2;
        ListNode* curr=head;
        for(int i=0; i<k; i++){
            ListNode* last=st.top();
            st.pop();
            ListNode* nextnode=curr->next;
            curr->next=last;
            last->next=nextnode;
            curr=nextnode;
        }
        curr->next=NULL;
    }
};