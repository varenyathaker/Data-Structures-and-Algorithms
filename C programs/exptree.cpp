#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

// Stack to hold the nodes
struct Node* head = NULL;

struct Node* newNode(char data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

// Push operation for the stack
void push(struct Node* x) {
    if (head == NULL) {
        head = x;
    }
    else {
        x->next = head;
        head = x;
    }
}

// Pop operation for the stack
struct Node* pop() {
    struct Node* p = head;
    head = head->next;
    return p;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Function to construct the expression tree from an infix expression
struct Node* constructExpressionTree(const string &infix) {
    stack<struct Node*> operands;
    stack<char> operators;
    
    for (char c : infix) {
        // If the character is an operand, create a node and push it to the operands stack
        if (isalnum(c)) {
            struct Node* temp = newNode(c);
            operands.push(temp);
        }
        /*
        // If the character is '(', push it to the operators stack
        else if (c == '(') {
            operators.push(c);
        }
        // If the character is ')', pop operators until '(' is found
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                
                struct Node* right = operands.top(); 
                operands.pop();
                struct Node* left = operands.top(); 
                operands.pop();
                
                struct Node* operatorNode = newNode(op);
                operatorNode->left = left;
                operatorNode->right = right;
                
                operands.push(operatorNode);
            }
            operators.pop(); // Pop the '('
        }*/
        // If the character is an operator
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                char op = operators.top();
                operators.pop();
                
                struct Node* right = operands.top(); 
                operands.pop();
                struct Node* left = operands.top(); 
                operands.pop();
                
                struct Node* operatorNode = newNode(op);
                operatorNode->left = left;
                operatorNode->right = right;
                
                operands.push(operatorNode);
            }
            operators.push(c);
        }
    }
    
    // Pop the remaining operators from the stack
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        
        struct Node* right = operands.top(); 
        operands.pop();
        struct Node* left = operands.top(); 
        operands.pop();
        
        struct Node* operatorNode = newNode(op);
        operatorNode->left = left;
        operatorNode->right = right;
        
        operands.push(operatorNode);
    }
    
    
    return operands.top();
}


void printInorder(struct Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}

int main() {
    string s = "a+b*c-d";
    
    
    struct Node* root = constructExpressionTree(s);
    
    // Print the inorder traversal of the expression tree
    printf("The Inorder Traversal of the Expression Tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}

