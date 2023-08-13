#include <bits/stdc++.h>
using namespace std;

// GFG POtd
// Nth Fibonacci Number
// Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

class Solution
{
public:
    int mod = 1e9 + 7;
    int nthFibonacci(int n)
    {
        long long int a = 0, b = 1, c;
        long long int cnt = 1;
        if (n == 1)
            return a;
        else if (n == 2)
            return b;
        else
        {
            cnt = 2;
            while (cnt <= n)
            {
                c = (a + b) % mod;
                a = b;
                b = c;
                cnt++;
            }
        }
        return c;
    }
};

// Leet Code
// Check if There is a Valid Partition For The Array

// You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

// We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

// The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
// The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
// The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
// Return true if the array has at least one valid partition. Otherwise, return false.

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, dp, 0, n);
    }

    bool helper(vector<int> &arr, vector<int> &dp, int start_indx, int n)
    {
        if (start_indx >= n)
            return true;

        if (dp[start_indx] != -1)
            return dp[start_indx];

        if (start_indx + 1 < n && arr[start_indx] == arr[start_indx + 1])
        {
            dp[start_indx] = helper(arr, dp, start_indx + 2, n);
            if (dp[start_indx])
                return true;

            if (start_indx + 2 < n && arr[start_indx] == arr[start_indx + 2])
            {
                dp[start_indx] = helper(arr, dp, start_indx + 3, n);
                if (dp[start_indx])
                    return true;
            }
        }

        if (start_indx + 2 < n && arr[start_indx + 1] - arr[start_indx] == 1 && arr[start_indx + 2] - arr[start_indx] == 2)
        {
            dp[start_indx] = helper(arr, dp, start_indx + 3, n);
            if (dp[start_indx])
                return true;
        }

        dp[start_indx] = 0;
        return false;
    }
};