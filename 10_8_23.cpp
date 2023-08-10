#include <bits/stdc++.h>
using namespace std;


// GFG POtd 
// Longest Common Subsequence
// Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets.

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2){
        // your code here
        int LCS[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0){
                    LCS[i][j]=0;
                    continue;
                }
                
                if(s1[i-1]==s2[j-1])
                    LCS[i][j]=LCS[i-1][j-1]+1;
                else
                    LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
        return LCS[n][m];

}
};

// Leet Code 
// Search in Rotated Sorted Array II


// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
            else if(nums[l] <= nums[mid])
            {
				
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
	
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }

};