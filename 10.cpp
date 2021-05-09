class Solution {
public:
    bool matchchar(char tar, char reg)
    {
        if (reg == '.')
            return true;
        return reg == tar;
    }
    bool isMatch(string s, string p) {

        if (p.empty())
        {
            return s.empty();
        }
        if (p.size() == 1)
        {
            return s.size() == 1 && matchchar(s[0], p[0]);
        }
        if (p[1] == '*')
        {
            int i = 0;
                
            while (i < s.size() && matchchar(s[i], p[0]))
            {
                if (isMatch(s.substr(i+1), p.substr(2)))
                {
                    return true;
                }
                ++i;
            }
            return isMatch(s, p.substr(2));
        }
        else
        {
            return s.size() > 0 && matchchar(s[0], p[0]) && isMatch(s.substr(1), p.substr(1));
        }
    }
};