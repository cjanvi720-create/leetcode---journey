class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int max_area = 0, n = matrix[0].size();
        vector<int> h(n+1,0);

        for (auto& row : matrix) {
            stack<int> s;
            for (int i = 0; i <= n; ++i) {
                if (i < n) h[i] = (row[i] == '1') ? h[i] + 1 : 0;
                while (!s.empty() && h[s.top()] > h[i]) {
                    int height = h[s.top()]; s.pop();
                    int width = s.empty() ? i : i - s.top() - 1;
                    max_area = max(max_area, height * width);
                }
                s.push(i);
            }
        }
        return max_area;
    }
};
