class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{0, 1};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&nums](int a, int b){return nums[a] < nums[b];});
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[index[i]] + nums[index[j]] < target)
            {
                ++i;
            }
            else if (nums[index[i]] + nums[index[j]] > target)
            {
                --j;
            }
            else
            {
                return vector<int>{index[i], index[j]};
            }
        }
        return vector<int>{0, 1};
    }
};

class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                return vector<int>{m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return vector<int>{0, 1};
    }
};