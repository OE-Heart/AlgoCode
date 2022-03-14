#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        vector<Node*> stack;
        Node* p = head;
        Node* top;
        while (p->next != NULL || p->child != NULL || stack.size() != 0) {
            if (p->child != NULL) {
                if (p->next != NULL) stack.push_back(p->next);
                p->next = p->child;
                p->child->prev = p;
                p->child = NULL;
                p = p->next;
            }
            else if (p->next != NULL) p = p->next;
            else {
                top = stack.back();
                stack.pop_back();
                p->next = top;
                top->prev = p;
                p = p->next;
            }
        }

        return head;
    }
};