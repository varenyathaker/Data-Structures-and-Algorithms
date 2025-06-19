#include <bits/stdc++.h>
using namespace std;

vector <int> bfsofGraph(vector<vector<int>> adj, int n){
    int vis[n] = {0}; 
    queue <int> q; 

    //0-based indexing 
    q.push(0); 
    vis[0] = 1;

    vector <int> ans; 
    
    while(!q.empty()){
        int node = q.front(); 
        q.pop();
        ans.push_back(node);  

        
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
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

    vector <int> ansd = bfsofGraph(a, n+1); 
    cout << endl; 
    for(int i = 0; i < ansd.size(); i++){
        cout << ansd[i] << " " ; 
    }
}