
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "Location.h"

string Location::NONE = "Empty";

Location::Location(const char& c, const int i){
    stringstream ss;
    ss << c << i;
    string temp = ss.str();
    this->id = temp;
    this->product = this->NONE;
    this->quantity = 0;
}

string Location::getId(){return this->id;}
int Location::getQuantity(){return this->quantity;}
string Location::getProduct(){return this->product;}

bool Location::isEmpty(){
    if(this->quantity == 0){
        return true;
    }
    return false;
}

bool Location::isAvailable(){
    if(this->product == this->NONE){
        return true;
    }
    return false;
}

void Location::print(){
    cout<<"Location Class"<<endl;
    cout<<"Product is "<<product<<", Quantities are "<<quantity<<", and it's UID: "<<id<<endl;
    cout<<endl;
}

//int Location::getCapacity(){return 0;}

// bool Location::add(const string& pName, int quantity){return false;}

// void Location::remove(int quantity){}

void Location::setProduct(const string& pName){
    this->product = pName;
}

void Location::setQuantity(int Q){
    this->quantity = Q;
}

string Location::getNONE(){ return NONE;}