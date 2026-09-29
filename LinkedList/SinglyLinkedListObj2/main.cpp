#include <iostream>
#include "Car.h"
#include "SinglyLinkedList.h"

using namespace std;

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
		myList.addAtPos(Car(10,"xxxxx", 666666),pos);
	myList.display2();	
	
	return 0;
}
