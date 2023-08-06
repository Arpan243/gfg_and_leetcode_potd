#include <bits/stdc++.h>
using namespace std;

// gfg potd
// Given a string S. The task is to find all permutations (need not be different) of a given string.

class Solution
{
public:
    void solve(vector<string> &ans, string s, int i)
    {
        if (i >= s.size())
        {
            ans.push_back(s);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            solve(ans, s, i + 1);
            swap(s[i], s[j]);
        }
    }
    vector<string> permutation(string S)
    {
        // Your code here
        vector<string> ans;
        solve(ans, S, 0);
        sort(ans.begin(), ans.end());
        return (ans);
    }
};

// Leet Code
// 920. Number of Music Playlists

// Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:

// Every song is played at least once.
// A song can only be played again only if k other songs have been played.
// Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.

class Solution
{
public:
#define ll long long
    const int MOD = 1e9 + 7;
    ll solve(int n, int goal, int k, vector<vector<int>> &dp)
    {
        if (n == 0 && goal == 0)
            return 1;
        if (n == 0 || goal == 0)
            return 0;
        if (dp[n][goal] != -1)
            return dp[n][goal];
        ll pick = solve(n - 1, goal - 1, k, dp) * n;
        ll notpick = solve(n, goal - 1, k, dp) * max(n - k, 0);
        return dp[n][goal] = (pick + notpick) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
        return solve(n, goal, k, dp);
    }
};