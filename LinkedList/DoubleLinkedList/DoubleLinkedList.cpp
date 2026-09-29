#include <iostream>

using namespace std;

class Node{
	public:
		int 	data;
		Node 	*next, *prev;
		
		Node(int x) : data(x), next(nullptr), prev(nullptr){}
};

class DoubleLinkedList{
	private:
		Node *head, *tail;
	public:
		DoubleLinkedList(): head(nullptr), tail(nullptr){}
		~DoubleLinkedList(){}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		void addFirst(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
		}
		void addLast(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->prev=tail;
				tail->next=newNode;
				tail=newNode;
			}
		}
		
		void display(){
			Node *cur=head;
			while (cur!=nullptr){
				cout<<cur->data<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};
int main(){
	DoubleLinkedList myList;
	myList.addFirst(6);
	myList.addFirst(4);
	myList.addFirst(9);
	myList.addFirst(3);
	myList.addFirst(8);
	myList.display();
	myList.addLast(3);
	myList.addLast(2);
	myList.addLast(5);
	myList.display();
	return 0;
}
