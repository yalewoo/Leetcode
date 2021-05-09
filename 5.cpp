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


class Solution2 {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        int r = -1;
        int l = -1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            if (1 > r)
            {
                r = 1;
                l = i;
            }

            if (i + 1 < n)
            {
                dp[i][i + 1] = s[i] == s[i + 1];
                if (dp[i][i + 1] && 2 > r)
                {
                    r = 2;
                    l = i;
                }
            }
        }
        
        for (int k = 2; k < n; ++k)
        {
            for (int i = 0; i+k < n; ++i)
            {
                int j = i+k;
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j] && j - i + 1 > r)
                {
                    r = j - i + 1;
                    l = i;
                }
            }
        }

        return s.substr(l, r);
    }
};