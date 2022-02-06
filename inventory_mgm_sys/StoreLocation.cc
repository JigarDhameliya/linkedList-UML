
#include <iostream>
#include <string>

using namespace std;

#include "StoreLocation.h"

int StoreLocation::nextId = 0;

StoreLocation::StoreLocation(char a): Location(a, ++nextId){
}

void StoreLocation::setProduct(const string& pName){
    Location::setProduct(pName);
}

int StoreLocation::getFreeSpace(){
    return (this->capacity - Location::getQuantity());
}

int StoreLocation::getCapacity(){ return this->capacity;}

bool StoreLocation::add(const string& pName, int amount){
    if(Location::getProduct() == "Empty" && amount <= getCapacity()){
        Location::setProduct(pName);
        Location::setQuantity(amount);
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

bool StoreLocation::remove(int amount){
    if(getQuantity() >= amount){
        Location::setQuantity(Location::getQuantity() - amount);
        return true;
    }
    return false;
}

void StoreLocation::print(){
    Location::print();
}