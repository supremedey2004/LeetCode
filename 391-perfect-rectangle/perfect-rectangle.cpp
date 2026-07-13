class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;

        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        unordered_set<string> corners;

        auto toggle = [&](int x, int y) {
            string key = to_string(x) + "," + to_string(y);
            if (corners.count(key))
                corners.erase(key);
            else
                corners.insert(key);
        };

        for (auto &r : rectangles) {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            area += 1LL * (x2 - x1) * (y2 - y1);

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            toggle(x1, y1);
            toggle(x1, y2);
            toggle(x2, y1);
            toggle(x2, y2);
        }

        long long expected = 1LL * (maxX - minX) * (maxY - minY);
        if (area != expected)
            return false;

        if (corners.size() != 4)
            return false;

        if (!corners.count(to_string(minX) + "," + to_string(minY)))
            return false;
        if (!corners.count(to_string(minX) + "," + to_string(maxY)))
            return false;
        if (!corners.count(to_string(maxX) + "," + to_string(minY)))
            return false;
        if (!corners.count(to_string(maxX) + "," + to_string(maxY)))
            return false;

        return true;
    }
};