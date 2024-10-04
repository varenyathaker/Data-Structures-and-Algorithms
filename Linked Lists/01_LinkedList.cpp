#include <bits/stdc++.h>

using namespace std; 

class Node {
    public:
    int data; 
    Node* next; 
    
    public: 
    
    Node (int data1, Node* next1) {
        data = data1; 
        next = next1; 
    }
    Node(int data1){
        data = data1; 
        next = nullptr; 
    }
};

int main() {
    vector <int> arr = {1, 2, 3, 4}; 
    Node* x = new Node(arr[0], nullptr); 

    cout << x << endl; //0x20680c822b0
    cout << x->next << endl; //0 
    cout << x->data << endl; //1

}