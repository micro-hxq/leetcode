// 566. Reshape the Matrix
// In MATLAB, there is a very useful function called 'reshape', which can reshape 
// a matrix into a new one with different size but keep its original data.

// You're given a matrix represented by a two-dimensional array, and two positive 
// integers r and c representing the row number and column number of the wanted 
// reshaped matrix, respectively.

// The reshaped matrix need to be filled with all the elements of the original matrix 
// in the same row-traversing order as they were.

// If the 'reshape' operation with given parameters is possible and legal, output the 
// new reshaped matrix; Otherwise, output the original matrix.

// Example 1:
// Input: 
// nums = 
// [[1,2],
//  [3,4]]
// r = 1, c = 4
// Output: 
// [[1,2,3,4]]

// Explanation:
// The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, 
// fill it row by row by using the previous list.

// Example 2:
// Input: 
// nums = 
// [[1,2],
//  [3,4]]
// r = 2, c = 4
// Output: 
// [[1,2],
//  [3,4]]

// Explanation:
// There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.

// Note:
// The height and width of the given matrix is in range [1, 100].
// The given r and c are all positive.

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        auto elem_num = nums.size() * nums.front().size();
        if(elem_num != r  * c)
            return nums;
        vector<vector<int>> res(r, vector<int>(c));
        auto rit1 = nums.begin();
        auto rit2 = res.begin();
        auto eit1 = rit1->begin(), eit2 = rit2->begin();
        for(size_t i = 0; i < elem_num; ++i)
        {
           if(eit1 == rit1->end())
            {
                ++rit1;
                eit1 = rit1->begin();
            }
            if(eit2 == rit2->end())
            {
                ++rit2;
                eit2 = rit2->begin();
            }
            *eit2++ = *eit1++;
        }
        return res;
    }
};

bool matrixEqual(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2)
{
    auto elem_nums1 = mat1.size() * mat1.front().size();
    auto elem_nums2 = mat2.size() * mat2.front().size();
    if(elem_nums1 != elem_nums2)
        return false;
    auto rit1 = mat1.begin();
    auto rit2 = mat2.begin();
    auto eit1 = rit1->begin(), eit2 = rit2->begin();
    for(size_t i = 0; i < elem_nums1; ++i)
    {
        if(eit1 == rit1->end())
        {
            ++rit1;
            eit1 = rit1->begin();
        }
        if(eit2 == rit2->end())
        {
            ++rit2;
            eit2 = rit2->begin();
        }
        if(*eit1++ != *eit2++)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<int>> nums1 = {{1, 2}, {3, 4}};
    auto res1 = sln.matrixReshape(nums1, 1, 4);
    CHECK_TRUE(matrixEqual(nums1, res1));
    auto res2 = sln.matrixReshape(nums1, 2, 4);
    CHECK_TRUE(matrixEqual(nums1, res2));
    
    TEST_REPORT();
}