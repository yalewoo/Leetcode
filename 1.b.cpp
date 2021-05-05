class Solution {
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