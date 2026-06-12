class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        //last se start
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++; //simple +1
                return digits;
            }
            digits[i] = 0; //carry
        }

        //agr sab 9 the
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
