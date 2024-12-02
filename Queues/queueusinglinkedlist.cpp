#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node* next;
};

#define SIZE  5
int currsize = 0; 

struct Node* head = NULL;

struct Node* enqueue(struct Node* head, int value) {
    if(currsize==SIZE){
        printf("\n LIst FUll\n"); 
        return head; 
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;  
        head = newNode;
    } 
    else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;  
        }
        temp->next = newNode;  
        newNode->next = head;  
    }
    printf("INserted %d \n", value);  
    currsize++; 
     
    return head;
}

struct Node* dequeue(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    } 
    else if (head->next == head) { 
        free(head);
        return NULL;
    } 
    else {
        struct Node* temp = head;
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;  
        }
        head = head->next;    
        last->next = head;    
        free(temp);
        return head;
    }
    currsize--; 
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

int main() {
    head = enqueue(head, 1);
    head = enqueue(head, 2);
    head = enqueue(head, 3);
    head = enqueue(head, 4);
    head = enqueue(head, 5);
    head = enqueue(head, 6);
    head = dequeue(head);
    display(head);
    return 0;
}
