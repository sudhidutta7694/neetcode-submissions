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

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* head1 = list1;
//         ListNode* head2 = list2;

//         ListNode* mergedList = new ListNode(0);
//         ListNode* head = mergedList;

//         while (head1 && head2) {
//             if (head1->val < head2->val) {
//                 mergedList->next = new ListNode(head1->val);
//                 head1 = head1->next;
//             } else {
//                 mergedList->next = new ListNode(head2->val);
//                 head2 = head2->next;
//             }

//             mergedList = mergedList->next;
//         }

//         if (head1) {
//             mergedList->next = head1;
//         } else {
//             mergedList->next = head2;
//         }

//         return head->next;
//     }
// };

//A more space optimised version:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        //assign not null list
        curr->next = list1 ? list1 : list2;

        return dummy.next;
    }
};