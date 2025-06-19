#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void dfs (int node, vector<vector<int>>& isConnected, vector<bool>& vis){
        vis[node] = true; 
        for(int i =0; i < isConnected.size(); i++){
            if(!vis[i] and isConnected[node][i]){
                dfs(i, isConnected, vis); 
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        int prov = 0; 
        vector <bool> vis(n, false); 

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                prov++; 
                dfs(i, isConnected, vis); 
            }
        }

        return prov; 
    }
};

// we basically count the no. of starting nodes for dfs traversals 