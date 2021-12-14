class Solution {
public:
//Intuitive method
//Check before overflow
//INT_MAX = 2147483647
//INT_MIN = -2147483648
//if current result == INT_MAX/10 and reminder > 7, overflow will happen
//if current result == INT_MIN/10 and reminder < -8, overflow will happen
//Runtime faster than 100.00%
//MU less than 76.31%
    int reverse(int x) {
        int result = 0;
        int count = 0;
        while(x!=0){
            int reminder = x%10;
            if (result > INT_MAX/10 || (result == INT_MAX / 10 && reminder > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN / 10 && reminder < -8)) return 0;
            result = (reminder + result*10);
            count++;
            x -= reminder;
            x /= 10;
        }
        return result;
    }
};