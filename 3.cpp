class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        {
            return 0;
        }
        
        int r = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            set<char> c;
            c.insert(s[i]);
            for (int j = i+1; j <= s.size(); ++j)
            {
                if (j == s.size() || c.count(s[j]))
                {
                    r = max(r, j-i);
                    break;
                }
                else
                {
                    c.insert(s[j]);
                }
            }
          
        }
        return r;
    }
};


class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        {
            return 0;
        }
        
        int r = 1;
        bool c[256] = {false};
        
        int i = 0;
        int j = 0;
        while (i < s.size() && j < s.size())
        {
            while (c[s[j]] == false && j < s.size())
            {
                c[s[j]] = true;
                r = max(r, j - i + 1);
                ++j;
            }
            
            while (s[i] != s[j])
            {
                c[s[i]] = false;
                ++i;
            }
            
            ++i;
            ++j;
        }
           
        return r;
    }
};


class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        {
            return 0;
        }
        
        int r = 1;
        int c[256] = {-1};
        for (int i = 0; i < 256; ++i)
        {
            c[i] = -1;
        }
        
        int i = 0;
        int j = 0;
        while (j < s.size())
        {
            if (c[s[j]] >= i)
            {
                i = c[s[j]] + 1;
            }
            
            c[s[j]] = j;
            r = max(r, j - i + 1);

            ++j;
        }
           
        return r;
    }
};