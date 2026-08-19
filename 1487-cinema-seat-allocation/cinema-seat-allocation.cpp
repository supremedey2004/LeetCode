#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store reserved seats for each row
        unordered_map<int, unordered_set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        // Initially, every row can have 2 groups
        long long ans = 2LL * n;

        for (auto &entry : mp) {
            unordered_set<int>& seats = entry.second;

            // This row was initially counted as 2 groups
            ans -= 2;

            bool left = true;    // 2,3,4,5
            bool middle = true;  // 4,5,6,7
            bool right = true;   // 6,7,8,9

            // Check left block
            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int i = 4; i <= 7; i++) {
                if (seats.count(i)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int i = 6; i <= 9; i++) {
                if (seats.count(i)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return (int)ans;
    }
};