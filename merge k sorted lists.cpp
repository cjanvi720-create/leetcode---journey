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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // minheap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // push first nodes
        for(auto l : lists) {
            if(l != NULL) pq.push(l);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if(node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
