#include <bits/stdc++.h>
using namespace std; 

void solve(int ind, string s, string &ans){
    if(ind==s.length()){
        cout << ans << " "; 
        return; 
    }
    //picking
    ans += s[ind]; 
    solve(ind + 1, s, ans); 

    //popping for not picking / backtracking
    ans.pop_back(); 
    solve(ind+1, s, ans); 
}

int main() {
    string s; 
    cin >> s; 
    string ans = ""; 
    solve(0, s, ans); 
}