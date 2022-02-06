#ifndef LIST_H
#define LIST_H

#include "Product.h"

class List
{
  class Node
  {
    public:
      Product* data;
      Node*    next;
  };

  public:
    List();
    ~List();
    void add(Product*);

    bool isEmpty();
    void findProduct(const string&, Product**);
    
    void print() const;

  private:
    Node* head;

};

#endif

