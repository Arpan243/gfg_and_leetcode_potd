#include <bits/stdc++.h>
using namespace std;


// GFG POtd 
// Largest prime factor
// Given a number N, the task is to find the largest prime factor of that number

class Solution{
public: 
     bool check_prime(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            return false;
        }
        return true;
    }
    long long int largestPrimeFactor(int N){
        // code here
        int p=0;
        for(int i=2;i<=N;i++)
        {  
            if(N%i==0 && check_prime(i))
            {
                p=i;
                N/=i;
            }
        }
        return p;
    }


};

// Leet Code 
// Minimize the Maximum Difference of Pairs

// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero

class Solution {
public:
   //able to  find p pairs with maximum difference of mid or not
    bool solve(vector<int>& nums,int d,int p){
        int n=nums.size();
        int c=0;
         for (int i = 0; i  < n-1; i++){

            if (nums[i + 1] - nums[i] <= d) {
               c++;
               i++;//no index appears more than once amongst the p pairs
            }
            if(c>=p)//able to find
            return true;
           }
           return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    int n=nums.size();
    //maximum difference is maximum element - minimum element
    int lo = 0, hi = nums[n-1] - nums[0];
    //we are checking for all the difference by binary search instead of linear search
    while (lo < hi) {
        int mid = (lo + hi) / 2;
      
        if (solve(nums,mid,p))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
};