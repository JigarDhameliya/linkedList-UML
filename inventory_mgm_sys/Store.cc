
#include "Store.h"
Store::Store(const string& name){
    this->name = name;
    products = new List();
    
}

Store::~Store(){
    delete products;
}

void Store::findAvailableSLoc(StoreLocation** sLoc){
    for(int i=0;i<SLOCS;i++){
        if(sLocObj[i].isAvailable()){
            *sLoc = &sLocObj[i];
            return;
        }
    }
    *sLoc = NULL;
}

void Store::findAvailableWHLoc(WHLocation** whLoc){
    for(int i=0;i<WHLOCS;i++){
        if(whLocObj[i].isAvailable()){
            *whLoc = &whLocObj[i];
            return;
        }
    }
    *whLoc = NULL;
}
//What if it doesnt find something

void Store::findProduct(const string& name, Product** prod){
    products->findProduct(name,prod);
}

void Store::printStoreStock(){
    for (StoreLocation sloc : sLocObj){
        if(sloc.getProduct() != "Empty"){
            sloc.print();
        }
    }
}
void Store::printWareHouseStock(){
    for (WHLocation whloc : whLocObj){
        int temp = whloc.getQuantity();
        if(temp > 0){
            whloc.print();
        }
    }
}

void Store::printProducts(){
    products->print();
}

void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);
    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
        cout<<"stocking store location..."<<endl;
        prod->stockStoreLocation();
    }

}

void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


void Store::print(){
    cout<<"Store: "<<name<<endl;
}