#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.count(val))
            return false;

        mp[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val))
            return false;

        int idx = mp[val];
        int last = nums.back();

        nums[idx] = last;
        mp[last] = idx;

        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};