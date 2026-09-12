class ListNode {
public:
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}

    ListNode(int x, ListNode* y, ListNode* z)
        : val(x), prev(y), next(z) {}
};


class MyCircularQueue {
private:
    int capacity;
    ListNode* leftNode;
    ListNode* rightNode;

public:
    MyCircularQueue(int k) {
        leftNode = new ListNode(0, nullptr, nullptr);
        rightNode = new ListNode(0, leftNode, nullptr);

        leftNode->next = rightNode;

        capacity = k;
    }
    
    bool enQueue(int value) {   
        if (isFull()) {
            return false;
        }

        ListNode* newNode =
            new ListNode(value, rightNode->prev, rightNode);

        rightNode->prev->next = newNode;
        rightNode->prev = newNode;

        capacity--;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        ListNode* deletableNode = leftNode->next;

        leftNode->next = deletableNode->next;
        leftNode->next->prev = leftNode;

        delete deletableNode;

        capacity++;

        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return leftNode->next->val;
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return rightNode->prev->val;
    }
    
    bool isEmpty() {
        return leftNode->next == rightNode;
    }
    
    bool isFull() {
        return capacity == 0;
    }
};