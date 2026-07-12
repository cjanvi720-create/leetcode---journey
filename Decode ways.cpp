class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = s[0] != '0';

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            
            if(s[i - 2] != '0'){
                int two = stoi(s.substr(i - 2, 2));
                
                if (two >= 0 && two <= 26)
                    dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
