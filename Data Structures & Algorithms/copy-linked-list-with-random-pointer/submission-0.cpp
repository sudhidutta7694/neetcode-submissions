/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Two Pass Method
        unordered_map<Node*, Node*> oldToCopy;

        Node* curr = head;

        //1st Pass: Construct the deep copies
        while (curr) {
            Node* copy = new Node(curr->val);
            oldToCopy[curr] = copy;
            curr = curr->next;
        }

        curr = head;

        //2nd pass: Construct the links
        //(solves the problem of linking way further next/random nodes)
        while (curr) {
            Node* copy1 = oldToCopy[curr];
            copy1->next = oldToCopy[curr->next];
            copy1->random = oldToCopy[curr->random]; 
            curr = curr->next;
        }

        return oldToCopy[head];
    }
};
