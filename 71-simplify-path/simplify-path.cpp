class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp;

        stringstream ss(path);

        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".")
                continue;
            else if (temp == "..") {
                if (!st.empty())
                    st.pop_back();
            } else {
                st.push_back(temp);
            }
        }

        if (st.empty())
            return "/";

        string ans;
        for (string &dir : st) {
            ans += "/" + dir;
        }

        return ans;
    }
};