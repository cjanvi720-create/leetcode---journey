#include <string>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> tFreq(128,0);
        vector<int> windowFreq(128,0);

        for (char c : t) {
            tFreq[c]++;
        }
        int required = 0;
        for (int count : tFreq) {
            if (count > 0) required++;
        }
        int left = 0, right = 0;
        int formed = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            windowFreq[c]++;

            if (tFreq[c] > 0 && windowFreq[c] == tFreq[c]) {
                formed++;
            }
            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                windowFreq[c]--;
                if (tFreq[c] > 0 && windowFreq[c] < tFreq[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
