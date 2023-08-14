#include <bits/stdc++.h>
using namespace std;

// GFG POtd
// Non Repeating Numbers
// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        vector<int> result;

        sort(nums.begin(), nums.end());
        if (nums.size() == 1)
        {
            return nums;
        }
        nums.push_back(-1);
        for (int i = 1; i <= nums.size(); i += 2)
        {
            if (nums[i - 1] != nums[i])
            {
                result.push_back(nums[i - 1]);
                i -= 1;
            }
        }
        result.pop_back();

        sort(result.begin(), result.end());
        return result;
    }
};

// Leet Code
// Kth Largest Element in an Array

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> p;
        for (auto x : nums)
        {
            p.push(x);
            if (p.size() > k)
            {
                p.pop();
            }
        }
        return p.top();
    }
};