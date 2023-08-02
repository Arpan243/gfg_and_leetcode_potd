#include <bits/stdc++.h>
using namespace std;


// gfg potd
// Shortest path in Directed Acyclic Graph
// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

class Solution {
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(n);
        for (auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>>pq;
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int node=temp.second;
            int d=temp.first;
            for (auto it:adj[node])
            {
                int nextNode=it.first;
                int nextDis=it.second;
                if (nextDis+d<dis[nextNode])
                {
                    dis[nextNode]=nextDis+d;
                    pq.push({dis[nextNode],nextNode});
                }
            }
        }
        for (int i=0;i<n;i++)
        {
            if (dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};