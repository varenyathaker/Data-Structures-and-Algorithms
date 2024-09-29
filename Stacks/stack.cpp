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