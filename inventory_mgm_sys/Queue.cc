#include"Queue.h"

Queue::Queue(){
    this->head = NULL;
    this->tail= NULL;
}

Queue::~Queue(){
    Node* currNode;
    Node* nextNode;

    currNode = head;

    while(currNode != NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

bool Queue::isEmpty(){
    Node* currNode = head;
    if(currNode != NULL){
        return false;
    }
    return true;
}

void Queue::peekFirst(WHLocation** loc){
    Node* firstNode = head;
    if(firstNode != NULL){
        *loc = firstNode->data;
    }
    else{
        *loc = NULL;
    }
}

void Queue::popFirst(WHLocation** loc){
    Node* currNode = head;
    if(this->isEmpty()){
        *loc = NULL;
    }
    else{
        *loc = head->data;
        head = head->next;
        delete currNode;
    }

}

void Queue::addLast(WHLocation* loc){
    Node* newNode;
    Node* currNode = head;
    Node* prevNode;

    newNode = new Node;
    newNode->data = loc;
    newNode->next = NULL;
    
    if(this->isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        //cout<<"Yes you are here!"<<endl;
        int size = 0;
        while(currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = newNode;
        tail = newNode;
        
    }
}

void Queue::print() const{
  Node* currNode = head;
  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}