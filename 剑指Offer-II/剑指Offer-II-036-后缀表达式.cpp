#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int a, b,c ;
        for (int i = 0; i < tokens.size(); i++) {
            switch ((char)tokens[i][0]) {
                case '+':
                    b = stack.back();
                    stack.pop_back();
                    a = stack.back();
                    stack.pop_back();
                    c = a+b;
                    stack.push_back(c);
                    break;
                case '-':
                    if (tokens[i].length() > 1) stack.push_back(stoi(tokens[i]));
                    else {
                        b = stack.back();
                        stack.pop_back();
                        a = stack.back();
                        stack.pop_back();
                        c = a-b;
                        stack.push_back(c);
                    }
                    break;
                case '*':
                    b = stack.back();
                    stack.pop_back();
                    a = stack.back();
                    stack.pop_back();
                    c = a*b;
                    stack.push_back(c);
                    break;
                case '/':
                    b = stack.back();
                    stack.pop_back();
                    a = stack.back();
                    stack.pop_back();
                    c = a/b;
                    stack.push_back(c);
                    break;
                default:
                    stack.push_back(stoi(tokens[i]));
                    break;
            }
        }

        return stack[0];
    }
};