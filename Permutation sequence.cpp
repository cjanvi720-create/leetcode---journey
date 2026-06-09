class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
            v.push_back(i);
        }
        v.push_back(n);

        k--;
        string ans = "";

        while (true) {
            ans += to_string(v[k/fact]);
            v.erase(v.begin() + k / fact);

            if (v.empty()) break;

            k %= fact;
            fact /= v.size();
        }
        return ans;
    }
};
