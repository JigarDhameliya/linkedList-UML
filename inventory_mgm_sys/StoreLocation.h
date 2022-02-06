#ifndef STORELOCATION_H
#define STORELOCATION_H

#include <iostream>
#include <string>
#include "defs.h"

#include "Location.h"

using namespace std;

class StoreLocation: public Location{
    public:
        StoreLocation(char a = 'A');
        void setProduct(const string& pName);
        int getFreeSpace();
        
        //Virtual Member functions.
        virtual int getCapacity();
        virtual bool add(const string& pName, int amount);
        virtual bool remove(int amount);

        void print();

    private:
        static const char a;
        static const int capacity = SLOC_CAPACITY;
        //I guess using const here will make nextId non useable else where so i decide to drop it here.
        static int nextId;
};
#endif