#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int countTime(vector<int>& piles, int k) {
        int t = 0;
        for (auto& p : piles) {
            t += p / k + ((p % k) > 0);
        }
        return t;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (countTime(piles, mid) <= h) {
                if (mid == 1 || countTime(piles, mid - 1) > h) return mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return -1;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> piles = stringToIntegerVector(line);
        getline(cin, line);
        int h = stringToInteger(line);
        
        int ret = Solution().minEatingSpeed(piles, h);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}