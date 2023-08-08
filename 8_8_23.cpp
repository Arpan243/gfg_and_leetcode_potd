#include <bits/stdc++.h>
using namespace std;

// GFG POtd 
// Fraction pairs with sum 1

// Given a list of N fractions, represented as two lists numerator and denominator, the task is to determine the count of pairs of fractions whose sum equals 1.
 
 
// } Driver Code Ends
class Solution
{
    public:
    int countFractions(int n, int a[], int b[])
    {
        for(int i=0;i<n;i++)
        {
            int x=__gcd(a[i],b[i]);
            a[i]/=x;
            b[i]/=x;
        }
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[{b[i],a[i]}]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            auto x=it.first;
            int cnt=it.second;
            if(x.first!=2)
            {
                ans+=(cnt*mp[{x.first,x.first-x.second}]);
                mp[x]=0;
                
            }
        }
        int y=mp[{2,1}];
        ans+=(y*(y-1))/2;
        
        
        
        return ans;
    }
};
 
//{ Driver Code Starts.
 
// int main() {
// int t;
// cin>>t;
// while(t--)
// {
// int grid[N][N];
 
// for(int i=0;i<9;i++)
//     for(int j=0;j<9;j++)
//         cin>>grid[i][j];
        
// Solution ob;
 
// if (ob.SolveSudoku(grid) == true)  
//             ob.printGrid(grid);  
//         else
//             cout << "No solution exists";  
        
//         cout<<endl;
// }
 
// return 0;
// }
// } Driver Code Ends




// Leet Code 
// Search in Rotated Sorted Array

//There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
      int left = 0;
      int right = n-1;
      int mid= left + (right - left) / 2; //to remove int overflow
      while(left <= right){
        if(nums[mid] == target)
         return mid; 
        //the array appears to be left sorted
        if(nums[mid] >= nums[left])
        //mandatory condition
       { 
          if(target >= nums[left] && target <= nums[mid])
            {
                right = mid - 1;
            }
           else left = mid + 1;
        } 
        //the array appears to be right sorted
        else {
          if(target >= nums[mid] && target <= nums[right]) 
            left = mid + 1;
          else right = mid - 1;
        }
          mid = left + (right - left) / 2;
      }
      return -1;
    }
};