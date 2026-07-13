class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0')
        return false;

        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    void solve(string s, int idx, int parts, string current) {
        if (parts == 4 && idx == s.size()) {
            current.pop_back();
            ans.push_back(current);
            return;
        }
        if (parts >= 4)
        return;
        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            if (isValid(part)) {
                solve(s, idx + len, parts + 1, current + part + ".");
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};
