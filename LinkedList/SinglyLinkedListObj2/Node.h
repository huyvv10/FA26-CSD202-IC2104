#pragma once
#include "Car.h"

class Node{
	public:
		Car data;
		Node *next;
		
		Node(const Car& x);
};