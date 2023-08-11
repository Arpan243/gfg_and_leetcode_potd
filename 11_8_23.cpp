#include <bits/stdc++.h>
using namespace std;

// GFG POtd
// Coin Change
// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
// Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {
        vector<long long int> prev(sum + 1, 0), curr(sum + 1);

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                    curr[j] = 1LL;
                else
                {
                    if (coins[i - 1] <= j)
                        curr[j] = curr[j - coins[i - 1]] + prev[j];
                    else
                        curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return curr[sum];
    }
};

// Leet Code
// Coin Change II

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &dp, vector<int> &coins)
    {
        if (i == 0)
        {
            return (j % coins[i] == 0);
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int nt = f(i - 1, j, dp, coins), tk = 0;
        if (j >= coins[i])
        {
            tk = f(i, j - coins[i], dp, coins);
        }
        return dp[i][j] = tk + nt;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, dp, coins);
    }
};