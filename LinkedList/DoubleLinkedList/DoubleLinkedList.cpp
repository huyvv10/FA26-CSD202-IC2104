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
		
		~DoubleLinkedList(){
			Node *cur=head;
			while (cur!=nullptr){
				Node *tmp=cur;
				cur=cur->next;
				delete tmp;
			}
		}
		
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
		
		//Return number of nodes existing in the list
		int countNodes(){
			Node *cur=head;
			int count=0;
			while (cur!=nullptr){
				count++;
				cur=cur->next;
			}
			return count;
		}		
		
		//Insert an element with value as x into position pos
		void addAtPos(int x, int pos){
			int n=countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0){ addFirst(x); return;}
			if (pos==n){ addLast(x); return;}
			int i=0;
			Node *cur=head;
			while (i!=pos){
				i++;
				cur=cur->next;
			}
			Node *newNode = new Node(x);
			newNode->next=cur;
			newNode->prev=cur->prev;
			cur->prev->next=newNode;
			cur->prev=newNode;
		}
		
		void removeFirst(){
			if (isEmpty()) return;
			if (head->next==nullptr){				
				Node *tmp=head;
				head=tail=nullptr;
				delete tmp;
			} else {
				Node *tmp=head;
				head=head->next;
				head->prev=nullptr;
				delete tmp;
			}
		}
		
		void removeLast(){
			if (isEmpty()) return;
			if (head->next==nullptr){				
				Node *tmp=head;
				head=tail=nullptr;
				delete tmp;
			} else {	
				Node *tmp=tail;
				tail=tail->prev;
				tail->next=nullptr;
				delete tmp;
			}
		}
		
		//Remove an element at the position pos.
		void removeAtPos(int pos){
			int n=countNodes();
			if (pos<0 || pos>=n) return;
			int i=0;
			Node *cur=head;
			while (i!=pos){
				i++;
				cur=cur->next;
			}	
			Node *tmp=cur;
			cur->prev->next=cur->next;
			cur->next->prev=cur->prev;
			delete tmp;
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
	cout<<"Number of nodes: "<<myList.countNodes()<<endl;
	int x, pos;
	cout<<"Input x = "; cin>>x;
	cout<<"Input position pos = "; cin>>pos;
	myList.addAtPos(x, pos);
	myList.display();
	cout<<"Remove first"<<endl;
	myList.removeFirst(); 
	myList.display();
	cout<<"Remove last"<<endl;
	myList.removeLast(); 
	myList.display();
	return 0;
}
