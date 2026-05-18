// https://leetcode.com/problems/product-of-array-except-self
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        std::vector<int> result(nums.size(), 1);

        int leftProduct = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};