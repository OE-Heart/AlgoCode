#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        if (a == -2147483648 && b == -1) {
            return 2147483647;
        }
        
        int tag = 0;
        if (a >= 0) {
            a = -a;
            tag++;
        }

        if (b >= 0) {
            b = -b;
            tag++;
        }

        int res = divide_core(a, b);
        if (tag == 1) return -res;
        else return res;
    }

    int divide_core(int a, int b) {
        int ret = 0;
        while (a <= b) {
            int value = b;
            int q = 1;
            while (value > 0 && a <= 2*value) {
                q += q;
                value += value;
            }
            ret += q;
            a -= value;
        }
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        
        int ret = Solution().divide(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}