#include <iostream>
#include <string>
using namespace std;

#include "List.h"

List::List() : head(NULL) { }

List::~List(){
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

void List::add(Product* p){
  Node* newNode;
  Node* currNode;
  Node* prevNode;

  newNode = new Node;
  newNode->data = p;
  newNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (newNode->data->getName() < currNode->data->getName())
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)
    head = newNode;
  else
    prevNode->next = newNode;

  newNode->next = currNode;
}

bool List::isEmpty(){
    Node* currNode = head;
    if(currNode != NULL){
        return false;
    }
    return true;
}

void List::findProduct(const string& name, Product** prod){
    Node* currNode = head;
    while(currNode != NULL){
        if(currNode->data->getName() == name){
            *prod = currNode->data;
            return;
        }
        currNode = currNode->next;
    }
    *prod = NULL;
    return;
}

void List::print() const{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

