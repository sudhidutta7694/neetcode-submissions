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
        if (!head || !head->next) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while (second) {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode* left = head;
        ListNode* right = prev;

        while (right) {
            ListNode* temp1 = left->next;
            ListNode* temp2 = right->next;

            left->next = right;
            right->next = temp1;

            left = temp1;
            right = temp2;
        }

        return;
    }
};
