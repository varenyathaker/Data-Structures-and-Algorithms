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

int lengthOfLL (Node* head){
    int count =0; 
    Node * temp = head; 
    while(temp->next!=NULL){
        count++;  
        temp = temp->next; 
    }
    return count; 
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

Node* deleteHead(Node* head){
    if (head == NULL) return head ;
    Node* temp = head; 
    head = head-> next; 
    free(temp); 
    return head; 
}

Node* deleteTail(Node* head){
    if(head==NULL or head->next == NULL) return NULL; 
    Node* curr = head; 
    while(curr->next->next != NULL){
        curr = curr->next; 
    }
    Node* temp = curr->next; 
    curr-> next = nullptr; 
    return head;  
}

Node* deleteK( Node* head, int k ){
    if(head == nullptr) return head; 
    if(k==1) return deleteHead(head); 

    int count = 0; 
    Node* temp = head; 
    Node* prev = nullptr; 
    while(temp!=NULL){
        count++; 
        if(count == k){
            prev->next = prev->next->next; 
            free(temp);
            break ; 
        }
        prev = temp ;
        temp  = temp->next; 
    }
    return head; 

}

Node* deletevalue( Node* head, int k ){
    if(head == nullptr) return head; 
    if(head->data == k) return deleteHead(head); 

    
    Node* temp = head; 
    Node* prev = nullptr; 
    while(temp!=NULL){
        
        if(temp->data == k){
            prev->next = prev->next->next; 
            free(temp);
            break ; 
        }
        prev = temp ;
        temp  = temp->next; 
    }
    return head; 

}



int main() {
    vector <int> ans = {90, 1, 2, 34, 5, 100, 7}; 
    Node* head = convertToLL(ans); 
    head = deleteHead(head);
    head = deleteTail(head);
    head = deleteK(head, 4) ;
    head = deletevalue(head, 34); 
    printLL(head); 
}