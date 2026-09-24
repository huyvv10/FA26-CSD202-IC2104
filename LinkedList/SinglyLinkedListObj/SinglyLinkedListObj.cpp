#include <iostream>
#include <string>
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
		
		void addFirst (Car x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
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
		}
};

int main(){
	SinglyLinkedList myList;
	myList.addFirst(Car(1,"Toyota Camry", 55000));
	myList.addFirst(Car(2,"Kia morning xls", 25000.5));
	myList.addFirst(Car(3,"Vinfast VF9", 75000));
	myList.addFirst(Car(4,"Toyota Vios", 27000));
	myList.display2();
	return 0;
}
