#include <bits/stdc++.h>
using namespace std; 

void dfs (int node, vector <vector<int>> &adj, vector <int> &vis, vector <int> &ans ){
    vis[node] = 1; 
    ans.push_back(node); 
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ans); 
        }
    }
}

vector <int> dfsofGraph(vector<vector<int>> adj, int n){
    vector <int> vis(n, 0); 
    
    //1 based indexing 
    int start = 1 ; 
    vector <int> ans; 

    dfs(start, adj, vis, ans); 
    return ans; 
}

int main(){
    int n, m; 
    cout << "Enter the number of nodes and edges : ";
    cin >> n >> m;

    vector<vector<int>> a(n+1);
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector <int> ansd = dfsofGraph(a, n+1); 
    cout << endl; 
    for(int i = 0; i < ansd.size(); i++){
        cout << ansd[i] << " " ; 
    }
}
