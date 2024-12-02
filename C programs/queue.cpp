#include <bits/stdc++.h> 
using namespace std; 

class Queue{
	int front; 
	int rear; 
	int maxSize; 
	int currSize; 
	string *arr;

	public: 
		Queue(){
			front = -1; 
			rear = -1; 
			
			currSize = 0;
			arr = new string[16]; 
		} 
	Queue(int maxSize){
		front = -1; 
		rear = -1; 
		(* this).maxSize = maxSize; 
		currSize = 0;
		arr = new string[maxSize]; 
	}
	
	void enqueue(string s) {
		if(front == -1){
			front++ ; 
			 
		} 
		if(currSize==maxSize){
			cout << "Queue is full\n"; 
			return; 
		}
		rear = (rear+1)%maxSize; 
		arr[rear] = s; 
		currSize++;
	} 

	string dequeue() {
		if(front==-1){
			cout << "Queue is empty" << endl ; 
			return "" ; 

		} 
		string s = arr[front]; 
		front = (front+1)%maxSize; 
		if(front==rear){
			front = -1; 
			rear = -1 ;
		} 
		currSize--; 
		return arr[front]; 
	} 

	void display(){

		if(front == -1 or front == rear){
			cout << "Empty\n"; 
		} 
		while(front!=rear){
			cout << arr[front] << " " ;
			front = (front+1)%maxSize; 
		} 
		cout << endl; 
	} 

	


};

int main() {
	Queue cq(3); 
	cq.enqueue("varenya"); 
	cq.enqueue("vijesh");
	cq.enqueue("yukta");
	cq.dequeue(); 
	cq.display(); 
	return 0; 
}


		
