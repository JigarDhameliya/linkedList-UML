#ifndef WHLOCATION_H
#define WHLOCATION_H

#include <iostream>
#include <string>
#include "defs.h"

#include "Location.h"

using namespace std;

class WHLocation: public Location{
    private:
        static const char b = 'B';
        static const int capacity = WHLOC_CAPACITY;
        static int nextId;
    
    public:
        WHLocation(char b = 'B');
        
        //Virtual Member functions.
        virtual int getCapacity();
        virtual bool add(const string& pName, int amount);
        virtual bool remove(int amount);

        void print();
};
#endif