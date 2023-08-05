#include <bits/stdc++.h>
using namespace std;
// Leet Code
// Unique Binary Search Trees II
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

/**
 * Definition for a binary tree node.

 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<pair<int, int>, vector<TreeNode *>> m;
    vector<TreeNode *> solve(int start, int end)
    {
        vector<TreeNode *> v;
        if (start > end)
        {
            v.push_back(NULL);
            return v;
        }
        if (start == end)
        {
            v.push_back(new TreeNode(start));
            return v;
        }
        if (m.count({start, end}))
            return m[{start, end}];
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> l = solve(start, i - 1);
            vector<TreeNode *> r = solve(i + 1, end);
            for (TreeNode *x : l)
            {
                for (TreeNode *x1 : r)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = x;
                    root->right = x1;
                    v.push_back(root);
                }
            }
        }
        return m[{start, end}] = v;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};




// gfg potd

// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
     sort(a.begin(), a.end());
    long long mindif = LLONG_MAX;
    for(int i = 0 ; i+m-1 < n ; i++){
        mindif=min((a[i+m-1]-a[i]),mindif);
        
    }
    return mindif;
    }   
};