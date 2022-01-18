#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= n; i++) {
            res.push_back(res[i/2] + i%2);
            // cout << res[i] << endl;
        }

        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().countBits(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}