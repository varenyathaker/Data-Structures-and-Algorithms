/*
VARENYA THAKER
1RV23IS135
BALANCED PARENTHESIS
*/

#include <bits/stdc++.h>
using namespace std; 

class Stack {
    int size; 
    int* arr; 
    int top; 
    public: 
        Stack() {
            size = 100; 
            arr = new int[size]; 
            top = -1; 
        }
    void push(int x){
        top++; 
        arr[top] = x; 
    } 
    int pop() {
        int x = arr[top]; 
        top--; 
        return x; 
    }
    int topelement() {
        return arr[top]; 
    }
    int sizeofstack(){
        return top + 1; 
    }

};

bool valid(string s) {
    Stack st; 
    for(int i = 0; i < s.length() ; i++){
        if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
            st.push(s[i]); 
        }
        else {
            if(st.sizeofstack() == 0) return false; 
            char ch = st.topelement() ; 
            st.pop(); 
            if((ch=='(' and s[i]==')') or (ch=='[' and s[i]==']') or (ch=='{' and s[i]=='}')) continue; 
            else return false; 
        }
    }
    return true; //return st.empty() for invalid strings 
}

int main()
{
    string s="[(])";
    if(valid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}