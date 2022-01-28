#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    
        vector<int> res;
        int n = asteroids.size();
        int now, tag;

        for (int i = 0; i < n; i++) {
            now = asteroids[i];
            while (now < 0) {
                if (res.size() == 0 || res.back() < 0) break;
                else {
                    tag = now + res.back();
                    res.pop_back();
                    if (tag < 0) continue;
                    else if (tag > 0) now = tag-now;
                    else now = 0;
                }
            }
            if (now != 0) res.push_back(now);
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
        vector<int> asteroids = stringToIntegerVector(line);
        
        vector<int> ret = Solution().asteroidCollision(asteroids);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}