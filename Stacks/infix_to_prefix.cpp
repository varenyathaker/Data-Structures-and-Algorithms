#include <bits/stdc++.h>
#include <stack>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixtoprefix(string s){
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='('){
            s[i] = ')'; 
        }
        else if(s[i]==')'){
            s[i] = '('; 
        }
    }

    stack <char> st;
    string ans = ""; 
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        // If character is an operand, add it to the result
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            ans += ch;
        }
        else if(ch == '('){
            st.push(ch); 
        }
        else if(ch == ')'){
            while(!st.empty() and st.top()!='('){
                ans += st.top(); 
                st.pop();
            }
            st.pop(); 
        }
        else{
            if(ch == '^'){
                while(!st.empty() and (prec(ch)<=prec(st.top()))){
                    ans += st.top(); 
                    st.pop(); 
                }
                 
            }
            else {
                while (!st.empty() and (prec(ch) < prec(st.top()))){
                    ans += st.top(); 
                    st.pop(); 
                }
                
            }
            st.push(ch); 
            
        }
        
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end()); 

    cout << ans << endl; 

    
}

int main() {
    string str = "(p*q)+(m-n)";
    infixtoprefix(str);
    
}
