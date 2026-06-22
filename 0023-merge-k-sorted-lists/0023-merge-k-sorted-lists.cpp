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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,
                       vector<ListNode*>,
                       Compare> minHeap;

        for (auto head : lists) {
            if (head != NULL) {
                minHeap.push(head);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while (!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();
            tail->next = temp;
            tail = temp;
            if (temp->next != NULL) {
                minHeap.push(temp->next);
            }
        }
        return dummy->next;
    }
};