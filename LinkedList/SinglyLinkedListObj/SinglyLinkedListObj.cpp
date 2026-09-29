#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class Car{
	public:
		int 	id;
		string	name;
		double	price;
		Car(): id(0), name(""), price(0.0) {}
		Car(int _id, const string& _name, double _price):
			id(_id), name (_name), price(_price) {}
		
		void showCar(){
			cout<<"("<<id<<","<<name<<","<<fixed<<setprecision(2)<<price<<")";			
		}
			
		void showCar2(){
			cout<<left<<
				setw(5)<<id<<
				setw(20)<<name<<
				right<<setw(10)<<fixed<<setprecision(2)<<price<<endl;			
		}	
};

class Node{
	public:
		Car data;
		Node *next;
		Node(const Car& x) : data(x), next(nullptr){}
		
//		Node(Car x) {
//			this->data=x;
//			this->next=nullptr;
//		}
};

class SinglyLinkedList{
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList() : head(nullptr), tail (nullptr){}
		~SinglyLinkedList(){}	
		
		bool isEmpty(){
			return head==nullptr;	
		}
		
		void addFirst2 (Car x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		bool checkCondition(Car x, char c, double price){
			int n = x.name.length();
			for (int i=0; i<n; i++)
				if (tolower(x.name[i])==tolower(c) || x.price<price) return true;
			return false;				
		}
		
		//If car name containing 'x' or 'X' 
		//or car price<30000, do nothing
		//Otherwise insert car to the begining of the list		
		void addFirst(Car x){
			if (checkCondition(x, 'x', 30000)) return;
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
		}
		
		void addLast (Car x){
			if (checkCondition(x, 'x', 30000)) return;
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}
		
		//Return number of cars within the list
		int countNodes(){
			int count=0;
			Node *cur=head;
			while (cur!=nullptr){
				count++;
				cur=cur->next;
			}
			return count;
		}
		
		void display(){
			Node *cur=head;			
			while (cur!=nullptr){
				cur->data.showCar();
				cur=cur->next;
			}
		}
		void display2(){
			cout<<left<<
				setw(5)<<"ID"<<
				setw(20)<<"NAME"<<
				right<<setw(10)<<"PRICE"<<endl;				
			cout<<left<<
				setw(5)<<"--"<<
				setw(20)<<"----"<<
				right<<setw(10)<<"-----"<<endl;				
			Node *cur=head;			
			while (cur!=nullptr){
				cur->data.showCar2();
				cur=cur->next;
			}
			cout<<endl;
		}
		
		void addAtPos(Car x, int pos){
			int n = countNodes();
			if (pos<0 || pos>n) return;
			if (pos==0){ addFirst(x); return;}
			if (pos==n){ addLast(x); return;}
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
		
		//Insert Car(10, "Huyndai santafe", 42000.9) before the first the most expensive
		int getMaxPrice(){
			int max=head->data.price;
			Node *cur=head->next;
			while (cur!=nullptr){
				if (cur->data.price > max) max = cur->data.price;
				cur=cur->next;				
			}
			return max;
		}
		int getPos(int maxPrice){
			int i;
			Node *cur=head;
			while (cur!=nullptr){
				if (cur->data.price==maxPrice)
					return i;
				cur=cur->next;	
			}
			return -1;
		}
		
};

int main(){
	SinglyLinkedList myList;
	myList.addFirst(Car(1,"Toyota Camry", 55000));
	myList.addFirst(Car(2,"Kia morning xls", 25000.5));
	myList.addFirst(Car(3,"Vinfast VF9", 75000));
	myList.addFirst(Car(4,"Toyota Vios", 27000));
	myList.display2();
	myList.addLast(Car(5,"Mazda CX5", 35000.5));
	myList.addLast(Car(6,"Vinfast VF7", 41000.8));
	myList.addLast(Car(7,"Ford escape", 38000.8));
	myList.addLast(Car(8,"Phantom ghost", 358000.8));
	myList.display2();
	cout<<"Number of cars: "<<myList.countNodes()<<endl;
	int pos;
	Car x = Car(9, "Maybach", 666000);
	cout<<"Input pos = "; cin>>pos;
	myList.addAtPos(x, pos);
	myList.display2();
	pos = myList.getPos(myList.getMaxPrice());
	if (pos==0)
		myList.addAtPos(Car(10,"xxxxx", 666666),0);
	else
		myList.addAtPos(Car(10,"xxxxx", 666666),pos-1);
	myList.display2();	
	
	return 0;
}
