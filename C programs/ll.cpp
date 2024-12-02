#include <stdio.h>  
#include <stdlib.h>
using namespace std; 

struct Node {
	int data; 
	struct Node* next; 
} 

struct Node* head = NULL; 

struct Node* insertbeg(struct Node* head, int value) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*)); 
	
	temp->data = value; 
	temp->next = head; 
	
	head = temp; 
	return head; 
} 

void insertend (struct Node* head, int value){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* curr = head; 
	while(curr->next!=NULL){
		curr = curr->next; 
	}
	curr->next = temp; 
	temp->data = value; 
	temp->next = NULL; 
} 

void deleteHead (struct Node* head){
	struct Node* temp = head; 
	
	if(head==NULL) cout << "empty list\n"; 
	else head = head->next; 
	
	free(temp); 
} 


void display(struct Node* head){
	struct Node* temp = head; 
	if(head==NULL){
		printf("empty list\n"); 
		return;
	} 
	while(temp->next!=NULL){
		printf("%d  ", temp->data);  
		temp = temp->next;
	} 
	free(temp);
}

int main(){
	struct node* head = insertbeg(head, 1); 
	insertend(head, 2); 
	insertend(head, 3); 
	display(head);
} 
		
		
		
		
		
		
		
		
		
		
		
		
		
		
