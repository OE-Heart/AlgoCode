#include <iostream>
using namespace std;

typedef struct ListNode ListNode;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* l = head;
        ListNode* r = head;
        while (true) {
            if (l != NULL && r != NULL && r->next != NULL) {
                // cout << "l=" << l->val << ", r=" << r->val << endl;
                l = l->next;
                r = r->next->next;
            }
            else {
                
                // cout << "here" << endl;
                return NULL;
            }
            if (l == r) break;
        }
        ListNode* p = head;
        while (p != l) {
            p = p->next;
            l = l->next;
        }

        return p;
    }
};