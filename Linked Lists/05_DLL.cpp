#include <bits/stdc++.h>
#include <vector>
using namespace std; 

class Node {
    public: 
    int data; 
    Node* next; 
    Node* prev; 

    public: 

    Node (int data1, Node* next1, Node* prev1){
        data = data1; 
        next = next1; 
        prev = prev1; 
    }

    Node(int data1){
        data = data1; 
        next = nullptr; 
        prev = nullptr; 
    }

};

Node* convertToDLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head; 
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; 
        prev = temp; 

    } 
    return head; 
}

void printDLL(Node *head){
    while(head!= NULL){
        cout << head->data << " "; 
        head = head->next;
    }
    return; 
}

int main() {
    vector <int> ans = {1, 3, 4, 7, 8, 9}; 
    Node* head = convertToDLL(ans); 
    printDLL(head); 
    return 0; 
}