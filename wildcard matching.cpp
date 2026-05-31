class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        int s_ptr = 0, p_ptr = 0;
        int star_idx = -1, s_tmp_idx = -1;

        while (s_ptr < n) {
            // 1. Agar characters match karein ya '?' ho
            if (p_ptr < m && (p[p_ptr] == s[s_ptr] || p[p_ptr] == '?')) {
                s_ptr++;
                p_ptr++;
            }
            // 2. Agar '*' mile
            else if (p_ptr < m && p[p_ptr] == '*') {
                star_idx = p_ptr;
                s_tmp_idx = s_ptr;
                p_ptr++;
            }
            // 3. Agar mismatch ho par peeche '*' tha (Backtrack)
            else if (star_idx != -1) {
                p_ptr = star_idx + 1;
                s_tmp_idx++; // Yahan integer overflow nahi hoga kyunki s_ptr string length tak hi jayega
                s_ptr = s_tmp_idx;
            }
            // 4. Koi match nahi
            else {
                return false;
            }
        }

        // Bache hue stars ko handle karo
        while (p_ptr < m && p[p_ptr] == '*') {
            p_ptr++;
        }

        return p_ptr == m;
    }
};
