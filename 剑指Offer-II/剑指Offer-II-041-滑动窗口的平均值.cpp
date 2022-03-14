#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> window;
    int maxSize = 0;
    double sum = 0;
    MovingAverage(int size) {
        maxSize = size;
    }
    
    double next(int val) {
        int size = window.size();
        if (size < maxSize) {
            window.push(val);
            size++;
            sum += val;
        }
        else {
            sum -= window.front();
            window.pop();
            window.push(val);
            sum += val;
        }

        return sum/size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */