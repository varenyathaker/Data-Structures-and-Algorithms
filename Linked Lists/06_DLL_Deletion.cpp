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

Node* deleteHead(Node* head){
    if(head == NULL or head->next == NULL){
        return NULL; 
    }
    Node* prev = head; 
    head = head->next; 

    head->prev = nullptr; 
    prev->next = nullptr;  

    delete prev; 
    return head; 


}

Node* deleteTail(Node* head){
    if (head==NULL or head->next==nullptr){
        return head; 
    }
    Node* tail = head; 
    while(tail->next!=nullptr){
        tail = tail->next; 
    }
    Node* prev = tail->prev; 
    prev->next = nullptr; 
    tail->prev = nullptr; 
    delete tail; 
    return head; 
}

Node* deleteK(Node* head, int k){
    int count = 0; 
    Node* temp = head; 
    while(temp!=NULL ){
        count++; 
        if(count==k) break; 
        temp = temp->next; 
    }
    Node* prev = temp->prev; 
    Node* next = temp->next; 
    if(prev==NULL and next==NULL){
        delete(temp); 
        return NULL; 
    }
    else if(prev==NULL){
        head = deleteHead(head); 
        return head ; 
    
    }
    else if(next==NULL){
        head = deleteTail(head);
        return head;  
    }
    else{
        prev->next = next; 
        next->prev = prev; 
        temp->next = NULL; 
        temp->prev = NULL; 
        delete(temp); 
    }

    return head; 
}

void deleteNode(Node* temp){
    Node* prev = temp->prev; 
    Node* next = temp->next; 
    if(next==NULL){
        prev->next = nullptr; 
        temp->prev = nullptr; 
        free(temp); 
        return; 
    }
    prev->next  = next; 
    next->prev = prev; 
    temp->next = temp->prev = nullptr; 
    free(temp); 
}

int main() {
    vector <int> ans = {1, 3, 4, 7, 8, 9, 2, 4, 77}; 
    Node* head = convertToDLL(ans); 
    head = deleteHead(head);
    head = deleteTail(head);
    head = deleteK(head , 3);
    deleteNode(head->next->next->next);  
    printDLL(head); 
    return 0; 
}