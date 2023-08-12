#include <bits/stdc++.h>
using namespace std;

// GFG POtd
// Longest Increasing Subsequence
// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    { 
      vector<int>dp; 
      
      dp.push_back(a[0]); 
      
      for(int i=1; i<n; i++){  
          int s=dp.size(); 
          if(a[i]>dp[s-1]) 
            dp.push_back(a[i]); 
          else{
            auto it=lower_bound(dp.begin(),dp.end(),a[i]); 
            *it=a[i]; 
          } 
      }  
      return dp.size(); 
    }
};

// Leet Code
// Unique Paths II

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size(),m =v[0].size();
        if(v[0][0] || v[n-1][m-1])return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(v[i][0])dp[i][0]=0;
            else dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<m;i++){
            if(v[0][i])dp[0][i]=0;
            else dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!v[i][j])dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};