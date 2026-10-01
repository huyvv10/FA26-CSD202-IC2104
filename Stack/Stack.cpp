#include <iostream>
using namespace std;
class Node {
	public:
		int data;
		Node *next;
		Node(int x) : data(x), next(nullptr) {}
};

class Stack {
	private:
		Node *head;
	public:
		Stack() : head(nullptr) {}
		~Stack() {
			Node *cur=head;
			while (cur!=nullptr) {
				Node* tmp=cur;
				cur=cur->next;
				delete tmp;
			}
			head=nullptr;
		}
		bool isEmpty() {
			return head==nullptr;
		}

		//Insert an element x into the top of stack - addFirst
		void push(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}

		void display() {
			Node *cur=head;
			while (cur!=nullptr) {
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}

		//Remove an element at the top of Stack
		void pop() {
			Node *tmp=head;
			if (isEmpty()) {
				cout<<"Stack is empty."<<endl;
				return;
			}
			head=head->next;
			delete tmp;
		}

		//Return the data of element at the top of stack without remove.
		int top() {
			if (isEmpty()) {
				cout<<"Stack is empty."<<endl;
				return -999;
			}
			return head->data;
		}
};

//Convert decimal to binary
void dec2bin(int n) {
	int r;
	Stack myStk;
	while (n!=0) {
		r = n%2;
		myStk.push(r);
		n=n/2;
	}
	string S="";
	while (!myStk.isEmpty()) {
		S+=to_string(myStk.top());
		myStk.pop();
	}
	cout<<S<<endl;
}

int main() {
	Stack myStk;
	myStk.push(5);
	myStk.push(2);
//	myStk.push(7);
//	myStk.push(9);
//	myStk.push(4);
	myStk.display();
	myStk.pop();
	myStk.pop();
	myStk.display();
	cout<<"The top element of stack: "<<myStk.top()<<endl;
	myStk.push(6);
	myStk.push(3);
	myStk.display() ;
	dec2bin(22);
	return 0;
}
