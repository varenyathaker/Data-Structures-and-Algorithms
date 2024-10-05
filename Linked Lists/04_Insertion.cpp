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

void printLL( Node* head){
    Node* curr = head; 
    while(curr!=NULL){
        cout << curr->data << endl ; 
        curr = curr->next; 
    }
}

Node* insertbeg(Node* head, int data){
    Node* temp = new Node(data); 
    temp->next = head;
    head = temp; 
    return head; 
}

Node* convertToLL (vector <int> &arr){
    Node* head = new Node(arr[0]); 
    Node* current = head; 
    for(int i = 1; i < arr.size() ; i++){
        int c = arr[i]; 
        Node* temp = new Node(c); 
        current->next = temp; 
        current = temp; 
    }
    return head; 
}

Node* insertend(Node* head, int val){
    Node* curr = head; 
    
    Node* temp = new Node(val); 
    if(head==nullptr){
        return temp; 
    }
    while(curr->next!=NULL){
        curr = curr->next; 
    }
    curr->next = temp; 
    return head; 

}

Node* insertK(Node* head, int element, int k  ){
    if(head==NULL){
        if(k==1) return new Node(element); 
        else return nullptr;
    }
    if(k==1){
        Node* temp = new Node(element, head); 
    }
    int count = 0; 
    Node* temp  = head; 
    while(temp!=NULL){
        count++; 
        if(count == k-1){
            Node* newNode = new Node(element, temp->next);
            temp->next = newNode; 
            return head; 
        }
        temp = temp->next; 

    }
    return head; 
    
}
 

int main() {
    vector <int> ans = {1, 2, 3, 4, 5}; 
    Node* head = convertToLL(ans);
    printLL(head);
    head = insertbeg(head, 2); 
    head = insertend(head, 7);
    head = insertK(head, 577, 2); 
    printLL(head);  

}