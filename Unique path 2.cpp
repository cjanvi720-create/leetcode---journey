#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<long> dp(n,0);
        dp[0] = !g[0][0];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
