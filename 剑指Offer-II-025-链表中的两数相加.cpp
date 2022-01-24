#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res;
        ListNode *p1 = reverseList(l1);
        ListNode *p2 = reverseList(l2);
        int n1 = p1->val;
        int n2 = p2->val;
        ListNode *ptr1, *ptr2;
        if (n1 < n2) {
            ptr1 = p2->next;
            ptr2 = p1->next;
        }
        else {
            ptr1 = p1->next;
            ptr2 = p2->next;
        }
        int carry = 0;
        while (ptr2 != NULL) {
            ptr1->val += ptr2->val+carry;
            if (ptr1->val >= 10) {
                carry = 1;
                ptr1->val %= 10;
            }
            else carry = 0;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while (ptr1 != NULL) {
            ptr1->val += carry;
            if (ptr1->val >= 10) {
                carry = 1;
                ptr1->val %= 10;
            }
            else carry = 0;
            ptr1 = ptr1->next;
        }

        if (n1 < n2) res = reverseList(p2->next);
        else res = reverseList(p1->next);
        res = res->next;

        if (carry) {
            res = new ListNode(1, res);
        }

        return res;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* p = head;
        ListNode* next;
        while (p != NULL) {
            res->val++;
            next = p->next;
            p->next = res->next;
            res->next =  p;
            p = next;
        }

        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}