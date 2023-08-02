#include <bits/stdc++.h>
using namespace std;

// gfg POtd
// Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
// Note: You can only move left, right, up and down, and only through cells that contain 1.

class Solution {
  public:
      bool valid(int i,int j,vector<vector<int>>&visited,vector<vector<int>>& A,int N,int M) 
    {
      if(i< 0 || i>=N || j<0 || j>=M || visited[i][j]==1 || A[i][j]==0)
      {
          return false;
      }
      
      return true;
    }
      
      
 
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)
        {
            return -1;
        }
        vector<vector<int>>visited(N,vector<int>(M,0));
        vector<vector<int>>distance(N,vector<int>(M,INT_MAX));
        queue< pair<pair<int,int>, int> >q;
        
        
        q.push({{0,0},0});
        visited[0][0]=1;
        
        int row[]={0,0,-1,1};
        int col[]={-1,1,0,0};
        while(!q.empty())
        {
            pair<pair<int,int>,int>front = q.front();
            q.pop();
            int r = front.first.first;
            int c = front.first.second;
            
           
            int dist = front.second;
            if(r==X && c==Y)
            {
                return dist;
            }
            for(int i=0;i<4;i++)
            {
                int nr = r+row[i];
                int nc = c+col[i];
                
                if(valid(nr,nc,visited,A,N,M))
                {
                    visited[nr][nc]=1;
                    q.push({{nr,nc},dist+1});
                }
            }
            
        }
         return -1;
       
    }
};


// leet code potd
// 46. Permutations
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

class Solution {
public:
    vector<vector<int>> arr;
    void backtrack(vector<int>& nums, int n, int index){
        if(index == n - 1){
            arr.push_back(nums);
            return;
        }
        for(int i=index; i<n; i++){
            swap(nums[index], nums[i]);
            backtrack(nums, n, index+1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        backtrack(nums, n, 0);
        return arr;
    }
};