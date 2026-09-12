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
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* beforeStartNode = dummyNode;
        beforeStartNode->next = head;
        ListNode* temp = head;
        int idx = 1;

        while (idx != left) {
            beforeStartNode = beforeStartNode->next;
            temp = temp->next;
            idx++;
        }

        ListNode* startNode = temp;

        while (idx != right) {
            temp = temp->next;
            idx++;
        }

        ListNode* endNode = temp;
        ListNode* afterEndNode = temp->next;
        endNode->next = nullptr;

        ListNode* newHead = reverseLL(startNode);
        beforeStartNode->next = newHead;
        startNode->next = afterEndNode;
        // while (newHead->next) {
        //     newHead = newHead->next;
        // }

        //newHead->next = afterEndNode;

        return dummyNode->next;
    }
};