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




int main() {
    vector <int> ans = {1, 2, 3, 4, 56, 7}; 
    Node* head = convertToLL(ans);
    printLL(head); 
    cout << lengthOfLL(head) << endl;  
    
    return 0  ; 
}
