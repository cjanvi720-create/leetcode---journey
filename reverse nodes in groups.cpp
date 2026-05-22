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
    //helper function
    bool hasKNodes(ListNode* head, int k) {
        int count = 0;
        while(head && count < k) {
            head = head->next;
            count++;
        }
        return count == k;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!hasKNodes(head, k)) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;

        //REverse k nodes
        while(curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // connect remaining
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
