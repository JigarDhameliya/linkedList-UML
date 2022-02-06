
#include <iostream>
#include <string>

using namespace std;

#include "WHLocation.h"

int WHLocation::nextId = 0;

WHLocation::WHLocation(char b):Location(b,++nextId){}

int WHLocation::getCapacity(){ return this->capacity;}

bool WHLocation::add(const string& pName, int amount){
    if(Location::isAvailable() && this->capacity >= Location::getQuantity()+amount){
        setProduct(pName);
        setQuantity(Location::getQuantity() +amount);
        return true;
    }
    else if(pName == Location::getProduct()){
        if(Location::getQuantity() + amount <= getCapacity()){
            setQuantity(Location::getQuantity() + amount);
            return true;
        }
        return false;
    }
    return false;
}

bool WHLocation::remove(int amount){
    if(getQuantity() > amount){
        Location::setQuantity(getQuantity() - amount);
        return true;
    }
    else if(getQuantity() == amount){
        setQuantity(0);
        setProduct(getNONE());
        return true;
    }
    return false;
}

void WHLocation::print(){
    cout<<"WHLocation Class: "<<endl;
    Location::print();
}