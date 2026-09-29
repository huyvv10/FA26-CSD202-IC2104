#pragma once
#include "Car.h"
#include "Node.h"

class SinglyLinkedList{
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList();
		~SinglyLinkedList();	
		
		bool isEmpty();
		void addFirst2 (Car x);
		bool checkCondition(Car x, char c, double price);
		void addFirst(Car x);
		void addLast (Car x);
		int countNodes();
		void addAtPos(Car x, int pos);
		int getMaxPrice();
		int getPos(int maxPrice);
		void sortAsc();
		
		void display();
		void display2();
};