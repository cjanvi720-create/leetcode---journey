 #include <climits>
 #include <cstdlib>
 using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
       //Edge case (overflow)
       if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

            //sign handle
            bool negative = (dividend < 0) ^ (divisor < 0);

            long long dvd = labs(dividend);
            long long dvs = labs(divisor);
            long long result = 0;

            while(dvd >= dvs) {
                long long temp = dvs;
                int multiple = 1;

                while( dvd >= (temp << 1)) {
                    temp <<= 1;
                    multiple <<= 1;
                }

                dvd -= temp;
                result += multiple;
            } 
            return negative ? -result : result;
    }
};
