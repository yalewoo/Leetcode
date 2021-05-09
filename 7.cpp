class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0)
        {
            int c = x % 10;
            x /= 10;
            int old = res;
            
            
            if (res > INT_MAX/10 || res == INT_MAX/10 && c > 7)
            {
                return 0;
            }
            if (res < INT_MIN/10 || res == INT_MIN/10 && c < -8)
            {
                return 0;
            }
            
                
            res = res * 10 + c;
        }
        return res;
    }
};