#include <bits/stdc++.h>
using namespace std;

// gfg Potd
// Reverse a Stack
// You are given a stack St. You have to reverse the stack using recursion.



class Solution{
public:
    public:
    void Reverse(stack<int> &St){
        queue<int>q;
        while(!St.empty())
        {
            int x;
            x = St.top();
            St.pop();
            q.push(x);
        }
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            St.push(x);
        }
        
    }
};



// Leet Code POTD
// 139. Word Break
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

class Solution {
public:
    map<char,vector<string>> m;
    vector<int> dp;
    bool f(string s, int i){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        bool ans=false;
        for(auto it:m[s[i]]){
            if(s.substr(i,it.size())==it){
                ans|=f(s,i+it.size());
            }
        }
        return dp[i]=ans;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(),-1);
        for(auto it:wordDict){
            m[it[0]].push_back(it);
        }
        return f(s,0);
    }
};
