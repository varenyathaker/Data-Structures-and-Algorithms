#include <stdio.h> 
#include <stdlib.h>

struct Node {
    int coeff, power;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;
struct Node* ans = NULL;

struct Node* insert(struct Node* head, int val, int pow) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = val;
    temp->power = pow;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;  
    } 
    else {
        struct Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;  
    }

    return head;  
}

struct Node* multiply(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    ans = NULL;  

    
    while (temp1 != NULL) {
        temp2 = head2;  
        while (temp2 != NULL) {
            int value = (temp1->coeff) * (temp2->coeff);
            int pow = temp1->power + temp2->power;
            ans = insert(ans, value, pow);  
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return ans;
}

void display(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("empty list\n");
        return;
    }

    while (temp != NULL) {
        printf("%d - %d    ", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("\n");
}

void remove_duplicates(struct Node* head) {
    struct Node* temp1 = head;
    struct Node* temp2 = NULL;
    struct Node* prev = NULL;
    
    while (temp1 != NULL && temp1->next != NULL) {
        prev = temp1;
        temp2 = temp1->next;
        
       
        while (temp2 != NULL) {
            if (temp1->power == temp2->power) { 
                
                temp1->coeff += temp2->coeff;
                
                
                prev->next = temp2->next;
                free(temp2);
                
            } 
            else {
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}

int main() {
    
    head1 = insert(head1, 3, 2);
    head1 = insert(head1, 5, 1);
    head1 = insert(head1, 6, 0);

    
    head2 = insert(head2, 6, 1);
    head2 = insert(head2, 8, 0);

    
    ans = multiply(head1, head2);
    remove_duplicates(ans); 

    
    display(ans);

    return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
			
		
	
