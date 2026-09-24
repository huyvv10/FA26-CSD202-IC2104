#include <iostream>
using namespace std;
class Node {
	public:
		int data;
		Node *next;
		Node(int _data) {
			this->data=_data;
			this->next=nullptr;
		}
};

class SinglyLinkedList {
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList() {
			head=tail=nullptr;
		}

		~SinglyLinkedList() {
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

		//Insert an element with value as x into the begining of the list
		void addFirst(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}

		//Insert an element with value as x into the last of the list
		void addLast(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}

		//Return number of nodes are existing in the list
		int countNodes() {
			int count=0;
			Node *cur=head;
			while (cur!=nullptr) {
				count++;
				cur=cur->next;
			}
			return count;
		}

		//Insert x into position pos
		void addAtPos(int x, int pos) {
			int n=countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0) {
				addFirst(x);
				return;
			}
			if (pos==n) {
				addLast(x);
				return;
			}
			int i=0;
			Node *cur=head;
			while (i!=pos-1) {
				i++;
				cur=cur->next;
			}
			Node *newNode = new Node(x);
			newNode->next=cur->next;
			cur->next=newNode;
		}

		//Get the maximum value within the list
		int getMax() {
			int max=head->data;
			Node *cur=head->next;
			while (cur!=nullptr) {
				if (cur->data>max) max = cur->data;
				cur=cur->next;
			}
			return max;
		}

		//Get the minimum value within the list
		int getMin() {
			int max=head->data;
			Node *cur=head->next;
			while (cur!=nullptr) {
				if (cur->data<max) max = cur->data;
				cur=cur->next;
			}
			return max;
		}

		//Return node at the position pos
		Node *getNodeAtPos(int pos){
			int n=countNodes();
			if (pos<0 || pos>=n) return nullptr;
			int i=0;
			Node *cur=head;
			while (i!=pos){
				i++;
				cur=cur->next;
			}
			return cur;
		}
		
		//Delete the element at the begining of the list
		void removeFirst(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				Node *tmp=head;
				head=tail=nullptr; 
				delete tmp; return;
			}
			Node *tmp=head;
			head=head->next;
			delete tmp;
		}

		//Delete the element at the last of the list
		void removeLast(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				Node *tmp=head;
				head=tail=nullptr; 
				delete tmp; return;
			}	
			Node *cur=head;
			while (cur->next!=tail){
				cur=cur->next;
			}
			Node *tmp=tail;
			cur->next=nullptr;
			tail=cur;
			delete tmp;					
		}

		//Delete the element at the position pos
		void removeAtPos(int pos){
			int n=countNodes();
			if (n==0 || pos<0 || pos>=n) return;
			if (pos==0){removeFirst(); return;}
			if (pos==n-1){removeLast(); return;}
			int i=0;
			Node *cur=head;
			while (i+1!=pos){
				i++;
				cur=cur->next;
			}
			Node *tmp=cur->next;
			cur->next=cur->next->next; //cur->next=tmp->next;
			delete tmp;
		}
		
		//Delete all elements with value as x
		void removeAll(int x){
			if (isEmpty()) return;
			while (head!=nullptr && head->data==x){
				removeFirst();
			}
			while (head!=nullptr && tail->data==x){
				removeLast();
			}
			Node *cur=head;
			while (cur!=nullptr && cur->next!=nullptr){
				if (cur->next->data==x){
					Node *tmp=cur->next;
					cur->next=tmp->next;
					delete tmp;
				} else
					cur=cur->next;
			}
		}
		
		//Sort the list in ascending order
		void sortAsc(){
			Node *cur=head;
			while (cur->next!=nullptr){
				Node *p=cur->next;
				while (p!=nullptr){
					if (cur->data>p->data){
						int tmp=cur->data;
						cur->data=p->data;
						p->data=tmp;
					}
					p=p->next;
				}
				cur=cur->next;
			}
		}
		
		//Sort the list in descending order
		void sortDesc(){
			Node *cur=head;
			while (cur->next!=nullptr){
				Node *p=cur->next;
				while (p!=nullptr){
					if (cur->data<p->data){
						int tmp=cur->data;
						cur->data=p->data;
						p->data=tmp;
					}
					p=p->next;
				}
				cur=cur->next;
			}			
		}
		
		//Sort the list in the range [pos1, pos2] in ascending order
		//Sort from The [first Max, second Min]
		void sortInRangeAsc(int pos1, int pos2){
			int i=0, j;			
			Node *cur=head;
			while (cur!=nullptr && i!=pos1){
				i++;
				cur=cur->next;
			}			
			while (cur->next!=nullptr && i<pos2){
				Node *p=cur->next;
				j=i+1;
				while (p!=nullptr && j<=pos2){
					if (cur->data>p->data){
						int tmp=cur->data;
						cur->data=p->data;
						p->data=tmp;
					}
					j++;
					p=p->next;
				}
				i++;
				cur=cur->next;
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

};
void menu() {
	cout<<"\n------Singly Linked List------"<<endl;
	cout<<"1. Add First"<<endl;
	cout<<"2. Add Last"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Count nodes"<<endl;
	cout<<"5. Add at pos"<<endl;
	cout<<"6. Get max"<<endl;
	cout<<"7. Get min"<<endl;
	cout<<"8. Get at pos"<<endl;
	cout<<"9. Remove first"<<endl;
	cout<<"10. Remove last"<<endl;
	cout<<"11. Remove at a specific position"<<endl;
	cout<<"12. Remove all"<<endl;
	cout<<"13. Sort in ascending order"<<endl;
	cout<<"14. Sort in descending order"<<endl;
	cout<<"15. Sort in the range [x,y]"<<endl;
	cout<<"0. Quit"<<endl;
	cout<<"Your selection: ";
}

int main() {
	SinglyLinkedList myList;
	myList.addFirst(2);
	myList.addFirst(6);
	myList.addFirst(9);
	myList.addFirst(7);
	myList.display();
	myList.addLast(3);
	myList.addLast(5);
	myList.addLast(9);
	myList.addLast(3);
	myList.addLast(8);
	myList.addLast(6);
	myList.addLast(8);
	myList.display();
	int x, pos, sel;
	do {
		menu();
		cin>>sel;
		switch(sel) {
			case 1:
				cout<<"Input value x = ";
				cin>>x;
				myList.addFirst(x);
				myList.display();
				break;
			case 2:
				cout<<"Input value x = ";
				cin>>x;
				myList.addLast(x);
				myList.display();
				break;
			case 3:
				myList.display();
				break;
			case 4:
				cout<<"Number of nodes: "<<myList.countNodes()<<endl;
				break;
			case 5:
				cout<<"Input value x = "; cin>>x;
				cout<<"Input position to add pos = "; cin>>pos;
				myList.addAtPos(x,pos);
				myList.display(); break;
			case 6:
				cout<<"The maximum value in the list: "<<myList.getMax()<<endl;
				break;
			case 7:
				cout<<"The minimum value in the list: "<<myList.getMin()<<endl;
				break;
			case 8:
				cout<<"Get node at pos"<<endl;
				cout<<"Input position to get: "; cin>>pos;
				Node *p;
				p = myList.getNodeAtPos(pos);
				if (p!=nullptr)
					cout<<"The value at position "<<pos<<" is:"<<p->data<<endl;
				else
					cout<<"The list is empty or position is out of range."<<endl;
				break;
			case 9:
				cout<<"Remove first"<<endl;
				myList.removeFirst(); 
				myList.display(); break;
			case 10:
				cout<<"Remove last"<<endl;
				myList.removeLast(); 
				myList.display(); break;
			case 11:
				cout<<"Remove at pos"<<endl;
				cout<<"Input position to delete: "; cin>>pos;
				myList.removeAtPos(pos);
				myList.display();
				break;
			case 12:
				cout<<"Remove all"<<endl;
				cout<<"Input value to remove: "; cin>>x;
				myList.removeAll(x);
				myList.display(); break;
			case 13:
				cout<<"Sort in ascending order"<<endl;
				myList.sortAsc();
				myList.display(); break;
			case 14:
				cout<<"Sort in descending order"<<endl;
				myList.sortDesc();
				myList.display(); break;
			case 15:
				cout<<"Sort in range"<<endl;
				myList.sortInRangeAsc(2,7);
				myList.display(); break;
			case 0:
				cout<<"Bye bye"<<endl; break;
			default:
				cout<<"Invalid selection. Please select again."<<endl;
		}
	} while (sel!=0);

	return 0;
}
