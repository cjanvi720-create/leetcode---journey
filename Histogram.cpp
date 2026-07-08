#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        stack<int> s;
        int max_ans = 0;
        for (int i = 0; i < h.size(); ++i) {
            while (!s.empty() && h[s.top()] >= h[i]) {
                int height = h[s.top()]; s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                max_ans = max(max_ans, height * width);
            }
            s.push(i);
        }
        return max_ans;
    }
};
