#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        totalNum = capacity;
        curNum = 0;
        dummy = new ListNode();
        tail = dummy;
    }
    
    int get(int key) {
        if (!numToLocation.count(key)) return -1;
        moveToTail(key);
        return numToLocation[key]->val;
    }
    
    void put(int key, int value) {
        if (numToLocation.count(key)) {
            numToLocation[key]->val = value;
            numToLocation[key]->key = key;
            moveToTail(key);
        }
        else if (curNum < totalNum) {
            addTotail(key, value);
            curNum++;
        }
        else deleteHead(key, value);
    }

private:
    struct ListNode {
        int key = 0;
        int val = 0;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode(){}
        ListNode(int x, int y) : key(x), val(y) {}
    };

    int totalNum;
    int curNum;
    ListNode* dummy;
    ListNode* tail;
    unordered_map<int, ListNode*> numToLocation;

    void moveToTail(int key) {
        ListNode* node = numToLocation[key];
        if (node == tail) {
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void addTotail(int key, int value) {
        ListNode* node = new ListNode(key, value);
        tail->next = node;
        node->prev = tail;
        tail = node;
        numToLocation[key] = node;
    }

    void deleteHead(int key, int value) {
        numToLocation.erase(dummy->next->key);
        dummy->next->key = key;
        dummy->next->val = value;
        numToLocation[key] = dummy->next;
        moveToTail(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */