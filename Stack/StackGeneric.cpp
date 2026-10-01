#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>	//Generic type

class Node{
	public:
		T data;
		Node *next;
		Node(T x) : data(x), next(nullptr){}	
};

template <typename T>
class Stack{
	private:
		Node<T> * head;
	public:
		Stack() : head(nullptr) {}
		~Stack(){}
		bool isEmpty(){
			return head==nullptr;
		}
		
		//Insert an element x into the top of stack - addFirst
		void push(T x){
			Node<T> *newNode = new Node<T>(x);
			if (isEmpty()) {
				head=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		void display(){
			Node<T> *cur=head;
			while (cur!=nullptr){
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
		
		//Remove an element at the top of Stack
		void pop(){
			Node<T> *tmp=head;
			if (isEmpty()) {
				throw runtime_error("Stack is empty."); return;
			}
			if (head->next==nullptr){
				head=nullptr;
			} else {
				head=head->next;
			}
			delete tmp;
		}
		
		//Return the data of element at the top of stack without remove.
		T top(){
			if (isEmpty()) {
				throw runtime_error("Stack is empty.");
			}
			return head->data;
		}
};

//Convert decimal to binary
void dec2bin(int n){
	int r;
	Stack<int> myStk;
	while (n!=0){
		r = n%2;
		myStk.push(r);
		n=n/2;
	}
	string S="";
	while (!myStk.isEmpty()){
		S+=to_string(myStk.top());
		myStk.pop();
	}
	cout<<S<<endl;	
}

int main(){
	Stack<int> myStk;
	myStk.push(5);
	myStk.push(2);
//	myStk.push(7);
//	myStk.push(9);
//	myStk.push(4);
	myStk.display();
	myStk.pop();
//	myStk.display();
	cout<<"The top element of stack: "<<myStk.top()<<endl;
//	myStk.push(6);
	myStk.push(3);
	myStk.display() ;
	dec2bin(22);
	return 0;
}
