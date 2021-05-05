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