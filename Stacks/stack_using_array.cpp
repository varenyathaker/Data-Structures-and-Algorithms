/*
VARENYA THAKER
1RV23IS135
STACK USING ARRAY
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

int main() {
    Stack s1; 
    s1.push(1); 
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.topelement() << endl; 
    s1.pop(); 
    cout << s1.topelement() << endl; 
    cout << s1.sizeofstack() << endl; 

}