#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i, j;
        for (i = 0, j = n-1; i < n; i++) {
            // cout << "i=" << i << " j=" << j << endl;
            if ((numbers[i] + numbers[j]) > target) {
                while (((numbers[i] + numbers[j]) > target) && j > i) {
                    j--;
                    // cout << ">i=" << i << " j=" << j << endl;
                }
                if ((numbers[i] + numbers[j]) == target) break;
            }
            else if ((numbers[i] + numbers[j]) < target) {
                while (((numbers[i] + numbers[j]) < target) &&  j < n-1) {
                    j++;
                    // cout << "<i=" << i << " j=" << j << endl;
                }
                if ((numbers[i] + numbers[j]) == target) break;
            }
            else break;
        }

        vector<int> res;
        res.push_back(i);
        res.push_back(j);
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
        vector<int> numbers = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(numbers, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}