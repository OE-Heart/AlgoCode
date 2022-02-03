#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> requests;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int size = requests.size();
        while (size > 0 && t-requests.front() > 3000) {
            requests.pop();
            size--;
        }
        requests.push(t);
        size++;

        return size;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */