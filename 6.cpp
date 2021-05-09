class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        vector<vector<char>> v(numRows, vector<char>(s.size(), '\0'));
        int i = 0, j = 0, k = 0;
        bool down = true;
        while (k < s.size())
        {
            v[i][j] = s[k];
            if (i == 0)
            {
                down = true;
            }
            if (i == numRows-1)
            {
                down = false;
            }
            
            
            if (down)
            {
                ++i;
            }
            else
            {
                --i;
                ++j;
            }
            ++k;
        }
        
        string res;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < s.size(); ++j)
            {
                if (v[i][j] != '\0')
                {
                    res += v[i][j];
                }
            }
        }
        return res;
    }
};