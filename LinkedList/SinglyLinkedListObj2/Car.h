#pragma once
#include <string>

class Car{
	public:
		int 	id;
		std::string	name;
		double	price;	
		
		Car();
		Car(int _id, const std::string& _name, double _price);
		
		void showCar();
		void showCar2();
};