#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            Node* res = new Node(insertVal);
            res->next = res;
            return res;
        }

        Node* p = head;
        while (p->next != head) {
            if (p->next->val < p->val) {
                if (p->next->val >= insertVal) break;
                else if (p->val <= insertVal) break;
            }
            if (p->val <= insertVal && p->next->val >= insertVal) break;
            p = p->next;
        }
        p->next = new Node(insertVal, p->next);

        return head;
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

Node* stringToNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    Node* dummyRoot = new Node(0);
    Node* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new Node(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string NodeToString(Node* node) {
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
        Node* head = stringToNode(line);
        getline(cin, line);
        int insertVal = stringToInteger(line);
        
        Node* ret = Solution().insert(head, insertVal);

        string out = NodeToString(ret);
        cout << out << endl;
    }
    return 0;
}