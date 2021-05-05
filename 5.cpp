class Solution {
public:
    string longestPalindrome(string s) {
        int m = 1;
        int m1= 1;
        s = "$" + s + "%";
        
        for (int i = 1; i < s.size(); ++i)
        {
            for (int j = 1; i-j>=0 && i+j < s.size(); ++j)
            {
                if (s[i-j] != s[i+j])
                {
                    if ((j-1)*2+1 > m)
                    {
                        m = (j-1)*2+1;
                        m1 = i-j+1;
                        
                    }
                    break;
                }
            }
            
            if (i+1 < s.size() && s[i] == s[i+1])
            {
                if (2 > m)
                {
                    m = 2;
                    m1 = i;

                }
                
                for (int j = 1; i-j>=0 && i+j+1 < s.size(); ++j)
                {
                    if (s[i-j] != s[i+j+1])
                    {
                        if ((j-1)*2+2 > m)
                        {
                            m = (j-1)*2+2;
                            m1 = i-j+1;

                        }
                        break;
                    }
                }
            }
            
        }
        return s.substr(m1, m);
    }
};