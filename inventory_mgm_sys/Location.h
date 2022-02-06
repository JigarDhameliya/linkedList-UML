#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

using namespace std;

class Location{
    public:
        string getId();
        string getProduct();
        int getQuantity();
        string getNONE();
        Location(const char& c, const int i);

        bool isEmpty();
        bool isAvailable();
        void print();

        //Virtual member functions
        virtual int getCapacity() = 0;
        virtual bool add(const string& pName, int quantity) = 0;
        virtual bool remove(int quantity) = 0;

        //Extra Functions
        void setProduct(const string& pName);
        void setQuantity(int Q);

    private:
        string id;
        string product;
        int quantity;
        static string NONE;

    protected:
        //string product;
};
#endif