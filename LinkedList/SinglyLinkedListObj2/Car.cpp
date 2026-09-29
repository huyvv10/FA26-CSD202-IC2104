#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h"

Car::Car() : id(0), name(""), price(0.0) {}

//conventional style
//Car::Car() {
//	this->id=0;
//	this->name="";
//	this->price=0.0;
//}

Car::Car(int _id, const std::string& _name, double _price)
	: id(_id), name(_name), price(_price) {}

void Car::showCar() {
	std::cout<<"("<<id<<","<<name<<","<<std::fixed<<std::setprecision(2)<<price<<")";
}

void Car::showCar2() {
	std::cout<<std::left<<
	    std::setw(5)<<id<<
	    std::setw(20)<<name<<
	    std::right<<std::setw(10)<<std::fixed<<std::setprecision(2)<<price<<std::endl;
}