#include <bits/stdc++.h>
using namespace std; 

class Queue {
    int *arr; 
    int front; 
    int rear;
    int currSize, maxSize;
    public: 
        Queue() {
            arr = new int[16]; 
            front = -1; 
            rear = -1; 
            currSize = 0; 
        }
    Queue(int maxSize){
        ( * this).maxSize = maxSize; 
        arr = new int[maxSize];
        front = -1; 
        rear =  -1; 
        currSize = 0;
    }

    void push(int element) {
        if(currSize==maxSize){
            cout << "Queue is full" << endl; 
            exit(1); 
        }
        if(rear == -1){
            rear = 0; 
            front = 0;
        }
        else {
            rear = (rear+1)%maxSize;
        }
        arr[rear] = element; 
        currSize++; 
        cout << "The element push was " << element << endl;
    }
    int pop() {
        if(front = -1){
            cout << "Queue is Empty" << endl; 
            exit(1); 
        }
        int popped = arr[front]; 
        if(currSize==1){
            front = -1; 
            rear = -1;
        }
        else{
            front = (front+1)%maxSize;
        }
        currSize--; 
        return popped; 
    }
    int top() {
        if (front == -1) {
        cout << "Queue is Empty" << endl;
        exit(1);
        }
        return arr[front];
    }

    int size() {
        return currSize;
    }
};

int main() {
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;

    return 0;
}