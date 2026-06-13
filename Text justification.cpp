class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int len = 0;   // total length of words only

            // Maximum words fit in one line
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line or single word -> left justify
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += ' ';
                    line += words[k];
                }

                // Fill remaining spaces at the end
                while (line.size() < maxWidth) line += ' ';
            }
            else {
                int totalSpaces = maxWidth - len;
                int each = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int spaces = each;
                        if (extra > 0) {
                            spaces++;
                            extra--;
                        }

                        while (spaces--) line += ' ';
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
