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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (int i=0; i<lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            if (ele.second->next) {
                pq.push({ele.second->next->val, ele.second->next});
            }
            temp->next = ele.second;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};
