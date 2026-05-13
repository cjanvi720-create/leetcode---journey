class Solution {
public:
    bool isPalindrome(int x) {
        //negative or ending with 0(except o)
        if(x < 0 || (x % 10 == 0 && x !=0))
              return false;

        int rev = 0;
        while(x > rev){
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }
        //even length OR odd length
        return (x== rev || x == rev / 10);              
    }
};
