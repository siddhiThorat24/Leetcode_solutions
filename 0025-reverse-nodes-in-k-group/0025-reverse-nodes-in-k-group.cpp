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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {

            // Find kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            if (kth == nullptr) {
                break;
            }

            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {

                ListNode* nextNode = curr->next;

                curr->next = prev;

                prev = curr;
                curr = nextNode;
            }

            // Connect reversed group
            ListNode* oldGroupStart = groupPrev->next;

            groupPrev->next = kth;

            groupPrev = oldGroupStart;
        }

        return dummy.next;
    }
};