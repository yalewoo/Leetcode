class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
        {
            ++i;
        }
        bool plus = true;
        if (i < s.size() && s[i] == '-')
        {
            plus = false;
            ++i;
        }
        else if (i < s.size() && s[i] == '+')
        {
            ++i;
        }
        
        int res = 0;
        while (i < s.size())
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int c = s[i] - '0';
                if (!plus)
                    c *= -1;
            
                if (res > INT_MAX/10 || res == INT_MAX/10 && c > 7)
                {
                    return INT_MAX;
                }
                if (res < INT_MIN/10 || res == INT_MIN/10 && c < -8)
                {
                    return INT_MIN;
                }
                res = res * 10 + c;
                ++i;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};