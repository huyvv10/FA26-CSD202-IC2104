#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int _data){
			this->data=_data;	
			this->next=nullptr;
		}	
};

class SinglyLinkedList{
	private: 
		Node *head, *tail;
	public:
		SinglyLinkedList(){
			head=tail=nullptr;
		}	
		
		~SinglyLinkedList(){
			Node *cur=head;
			while (cur!=nullptr){
				Node* tmp=cur;
				cur=cur->next;
				delete tmp;
			}
			head=tail=nullptr;
		}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		//Insert an element with value as x into the begining of the list
		void addFirst(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		//Insert an element with value as x into the last of the list
		void addLast(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}
		
		//Return number of nodes are existing in the list
		int countNodes(){
			int count=0;
			Node *cur=head;
			while (cur!=nullptr){
				count++;
				cur=cur->next;
			}
			return count;
		}
		
		//Insert x into position pos
		void addAtPos(int x, int pos){
			int n=countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0){addFirst(x); return;}
			if (pos==n){addLast(x); return;}
			int i=0;
			Node *cur=head;
			while (i!=pos-1){
				i++;
				cur=cur->next;
			}
			Node *newNode = new Node(x);
			newNode->next=cur->next;
			cur->next=newNode;			
		}
		
		//Get the maximum value within the list
		int getMax(){
			int max=head->data;
			Node *cur=head->next;
			while (cur!=nullptr){
				if (cur->data>max) max = cur->data;
				cur=cur->next;
			}
			return max;
		}
		
		//Get the minimum value within the list
		int getMin(){
			int max=head->data;
			Node *cur=head->next;
			while (cur!=nullptr){
				if (cur->data<max) max = cur->data;
				cur=cur->next;
			}
			return max;
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
	SinglyLinkedList myList;
	myList.addFirst(2);
	myList.addFirst(6);
	myList.addFirst(9);
	myList.addFirst(7);
	myList.display();
	myList.addLast(3);
	myList.addLast(5);
	myList.addLast(9);
	myList.display();
	cout<<"Number of nodes: "<<myList.countNodes()<<endl;	
	int x, pos;
	cout<<"Input value x = "; cin>>x;
	cout<<"Input position to add pos = "; cin>>pos;
	myList.addAtPos(x,pos);
	myList.display();
	cout<<"The maximum value in the list: "<<myList.getMax()<<endl;
	cout<<"The minimum value in the list: "<<myList.getMin()<<endl;
	return 0;
}
