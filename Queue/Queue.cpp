#include <iostream>
using namespace std;
class Node {
	public:
		int data;
		Node *next;
		Node(int x) : data(x), next(nullptr) {}
};

class Queue {
	private:
		Node *head, *tail;
	public:
		Queue() : head(nullptr), tail(nullptr) {}
		~Queue() {
			Node *cur=head;
			while (cur!=nullptr) {
				Node* tmp=cur;
				cur=cur->next;
				delete tmp;
			}
			head=tail=nullptr;
		}

		bool isEmpty() {
			return head==nullptr;
		}

		void enqueue(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}

		void dequeue() {
			if (isEmpty()) return;
			if (head->next==nullptr) {
				Node *tmp=head;
				head=tail=nullptr;
				delete tmp;
				return;
			}
			Node *tmp=head;
			head=head->next;
			delete tmp;
		}

		int front() {
			if (isEmpty()) {
				cout<<"Queue is empty"<<endl;
				return -999;
			}
			return head->data;
		}

		int rear() {
			if (isEmpty()) {
				cout<<"Queue is empty"<<endl;
				return -999;
			}
			return tail->data;
		}
		
		void display() {
			Node *cur=head;
			while (cur!=nullptr) {
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};

int main(){
	Queue myQ;
	myQ.enqueue(5);
	myQ.enqueue(2);
	myQ.enqueue(7);
	myQ.enqueue(9);
	myQ.display();
	cout<<"The element at the begining of queue: "<<myQ.front()<<endl;
	cout<<"The element at the last of queue: "<<myQ.rear()<<endl;
	
	return 0;
}
