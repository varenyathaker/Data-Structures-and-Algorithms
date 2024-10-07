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

Node* insertAtTail(Node* head, int k){
    Node* temp = new Node(k); 
    if(head==nullptr) return temp; 

    Node* tail = head; 
    while(tail->next!=nullptr) tail = tail->next; 

    tail->next = temp; 
    temp->prev = tail ; 

    return head; 
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertToDLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    printDLL(head); 


    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    printDLL(head);

    return 0;
}

