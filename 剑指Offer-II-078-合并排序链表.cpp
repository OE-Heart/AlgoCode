#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct ListNode ListNode;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        ListNode* p1 = left;
        ListNode* p2 = right;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            else {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
        }
        if (p1 != NULL) p->next = p1;
        if (p2 != NULL) p->next = p2;
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        queue<ListNode*> que;
        for (int i = 0; i < n / 2; ++i) {
            que.push(mergeList(lists[2 * i], lists[2 * i + 1]));
        }
        if (n % 2) que.push(lists.back());
        ListNode *head1, *head2;
        while (que.size() > 1) {
            head1 = que.front();
            que.pop();
            head2 = que.front();
            que.pop();
            que.push(mergeList(head1, head2));
        }
        return que.front();
    }
};