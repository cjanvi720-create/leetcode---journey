class Solution {
private:
    // Hash map to store results of already computed substring pairs
    unordered_map<string, bool> memo;

public:
    bool isScramble(string s1, string s2) {
        // Base Case 1: If strings are identical, they are scrambles of each other
        if (s1 == s2) return true;
        
        // Base Case 2: If lengths don't match, they cannot be scrambles
        if (s1.length() != s2.length()) return false;

        // Create a unique key for the current pair of strings
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.length();
        
        // Pruning: Check if both strings have the exact same character frequencies
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return memo[key] = false; // Characters don't match
            }
        }

        // Try splitting the strings at every possible index 'i'
        for (int i = 1; i < n; i++) {
            // Case 1: Substrings are NOT swapped
            bool is_not_swapped = isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                                 isScramble(s1.substr(i), s2.substr(i));
            
            if (is_not_swapped) return memo[key] = true;

            // Case 2: Substrings ARE swapped
            bool is_swapped = isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                             isScramble(s1.substr(i), s2.substr(0, n - i));
            
            if (is_swapped) return memo[key] = true;
        }

        return memo[key] = false;
    }
};
