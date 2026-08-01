class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
   private:
    int capacity;
    unordered_map<int, Node*> mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

   public:
    LRUCache(int _capacity) {
        capacity = _capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->val = value;

            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            deleteNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        insertAfterHead(node);

        mp[key] = node;
    }
};
