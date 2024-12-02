#include <stdio.h>  
#include <stdlib.h>

struct Node {
	int data; 
	struct Node* next; 
}; 

struct Node* head = NULL; 

struct Node* insertbeg(struct Node* head, int value) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	
	temp->data = value; 
	temp->next = head; 
	
	head = temp; 
	return head; 
} 

struct Node* insertend (struct Node* head, int value){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* curr = head; 
	while(curr->next!=NULL){
		curr = curr->next; 
	}
	curr->next = temp; 
	temp->data = value; 
	temp->next = NULL; 
	return head; 
} 

struct Node* deleteHead (struct Node* head){
	struct Node* temp = head; 
	
	if(head==NULL) printf("empty list\n");
	else head = head->next; 
	
	free(temp);
	return head; 
	
} 


void display(struct Node* head){
	struct Node* temp = head; 
	if(head==NULL){
		printf("empty list\n"); 
		return;
	} 
	while(temp!=NULL){
		printf("%d  ", temp->data);  
		temp = temp->next;
	} 
	//printf("%d  ", temp->data);
	
}

int main(){
	head = insertbeg(head, 1); 
	head = insertend(head, 2); 
	head = insertend(head, 3);
	head = deleteHead(head); 
	head = insertbeg(head, 4);  
	 
	display(head);
} 
		
		
		
		
		
		
		
		
		
		
		
		
		
		
