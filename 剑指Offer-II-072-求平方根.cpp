#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 1;
        int right = min(x / 2, (int)pow(2, 16));
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mid > x / mid) right = mid - 1;
            else if (mid < x / mid && mid + 1 <= x / (mid + 1)) left = mid + 1;
            else return mid;
        }
        return 0;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mid <= x / mid) {
                if (mid + 1 > x / (mid + 1)) return mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return 0;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}