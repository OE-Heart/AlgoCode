#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet 
{
public:
    unordered_map<int, int> num_index;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedSet() 
    {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if (num_index.find(val) != num_index.end()) return false;
        num_index[val] = (int)nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if (num_index.find(val) == num_index.end()) return false;
        int index = num_index[val];
        int back = nums.back();
        nums[index] = back;
        num_index[back] = index;
        num_index.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        int index = rand() % (int)nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */