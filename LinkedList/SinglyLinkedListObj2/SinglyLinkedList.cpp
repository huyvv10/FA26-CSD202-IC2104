#include <iostream>
#include <iomanip>
#include <string>

#include "Car.h"
#include "Node.h"
#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail (nullptr) {}
SinglyLinkedList::~SinglyLinkedList() {}

bool SinglyLinkedList::isEmpty() {
	return head==nullptr;
}

void SinglyLinkedList::addFirst2 (Car x) {
	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		newNode->next=head;
		head=newNode;
	}
}

bool SinglyLinkedList::checkCondition(Car x, char c, double price) {
	int n = x.name.length();
	for (int i=0; i<n; i++)
		if (tolower(x.name[i])==tolower(c) || x.price<price) return true;
	return false;
}

//If car name containing 'x' or 'X'
//or car price<30000, do nothing
//Otherwise insert car to the begining of the list
void SinglyLinkedList::addFirst(Car x) {
	if (checkCondition(x, 'x', 30000)) return;
	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		newNode->next=head;
		head=newNode;
	}
}

void SinglyLinkedList::addLast (Car x) {
	if (checkCondition(x, 'x', 30000)) return;
	Node *newNode = new Node(x);
	if (isEmpty()) {
		head=tail=newNode;
	} else {
		tail->next=newNode;
		tail=newNode;
	}
}

//Return number of cars within the list
int SinglyLinkedList::countNodes() {
	int count=0;
	Node *cur=head;
	while (cur!=nullptr) {
		count++;
		cur=cur->next;
	}
	return count;
}

void SinglyLinkedList::display() {
	Node *cur=head;
	while (cur!=nullptr) {
		cur->data.showCar();
		cur=cur->next;
	}
}
void SinglyLinkedList::display2() {
	std::cout<<std::left<<
	    std::setw(5)<<"ID"<<
	    std::setw(20)<<"NAME"<<
	    std::right<<std::setw(10)<<"PRICE"<<std::endl;
	std::cout<<std::left<<
	    std::setw(5)<<"--"<<
	    std::setw(20)<<"----"<<
	    std::right<<std::setw(10)<<"-----"<<std::endl;
	Node *cur=head;
	while (cur!=nullptr) {
		cur->data.showCar2();
		cur=cur->next;
	}
	std::cout<<std::endl;
}

void SinglyLinkedList::addAtPos(Car x, int pos) {
	int n = countNodes();
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

//Insert Car(10, "Huyndai santafe", 42000.9) before the first the most expensive
int SinglyLinkedList::getMaxPrice() {
	int max=head->data.price;
	Node *cur=head->next;
	while (cur!=nullptr) {
		if (cur->data.price > max) max = cur->data.price;
		cur=cur->next;
	}
	return max;
}
int SinglyLinkedList::getPos(int maxPrice) {
	int i=0, pos=0;
	Node *cur=head;
	while (cur!=nullptr) {
		if (cur->data.price==maxPrice){
			pos=i; break;
		}			
		cur=cur->next;
		i++;
	}
	return pos;
}

void SinglyLinkedList::sortAsc(){


}