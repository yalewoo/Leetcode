class Solution {
public:
    double findK(vector<int>& nums1, vector<int>& nums2, int i1, int j1, int i2, int j2, int k)
    {
        if (nums1.size() > nums2.size())
        {
            return findK(nums2, nums1, i2, j2, i1, j1, k);
        }

        int n1 = j1 - i1;
        int n2 = j2 - i2;
        if (n1 == 0)
        {
            return nums2[i2 + k - 1];
        }
        if (n2 == 0)
        {
            return nums1[i1 + k - 1];
        }
        if (k == 1)
        {
            return min(nums1[i1], nums2[i2]);
        }

        int k1 = k / 2 > n1 ? n1 : k / 2;
        int k2 = k - k1;
        int r1 = i1 + k1 - 1;
        int r2 = i2 + k2 - 1;

        if (nums1[r1] < nums2[r2])
        {
            return findK(nums1, nums2, r1+1, j1, i2, j2, k - k1);
        }
        else
        {
            return findK(nums1, nums2, i1, j1, r2+1, j2, k - k2);
        }


    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 0)
        {
            int k1 = n / 2;
            int k2 = n / 2 + 1;
            int r1 = findK(nums1, nums2, 0, nums1.size(), 0, nums2.size(), k1);
            int r2 = findK(nums1, nums2, 0, nums1.size(), 0, nums2.size(), k2);
            return (r1 + r2) / 2.0;
        }
        else
        {
            return findK(nums1, nums2, 0, nums1.size(), 0, nums2.size(), n / 2 + 1);
        }

    }
};