class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int n = 0;
        int c = x;
        while (c)
        {
            c /= 10;
            ++n;
        }
        
        stack<int> s;
        for (int i = 0; i < n; ++i)
        {
            int c = x % 10;
            x /= 10;
            if (n % 2 == 1 && i == n/2)
            {
                
            }
            else if (i < n/2)
            {
                s.push(c);
            }
            else
            {
                if (c != s.top())
                {
                    return false;
                }
                s.pop();
            }
        }
        return true;
    }
};