#include <iostream>

template<typename Type>
class LinkedList {
     struct Node {
          Type value;
          Node* next;
     };

     private:
          Node* head;
          Node* tail;
          int numItems;

     public:
          LinkedList() : head(NULL), tail(NULL), numItems(0) {}
          ~LinkedList() {
               Node* current = this -> head;
               while(current != NULL) {
                    Node* temp = current -> next;
                    delete current;
                    current = temp;
               }
          }
          void clear() {
               Node* current = this -> head;
               while(current != NULL) {
                    Node* temp = current -> next;
                    delete current;
                    current = temp;
               }
               head = NULL;
               tail = NULL;
          }
          void print() {
               Node* current = this -> head;
               while(current != NULL) {
                    std::cout << current -> value << std::endl;
                    current = current -> next;
               }
          }
          Node* getHead() {
               return this -> head;
          }
          Node* getTail() {
               return this -> tail;
          }
          int size() {
               return this -> numItems;
          }
          Type get(int index) {
               Node* toReturn = this -> head;
               for(int i = 0; i < index; i++) {
                    toReturn = toReturn -> next;
               }
               return toReturn -> value;
          }
          Node* getNode(int index) {
               Node* toReturn = this -> head;
               for(int i = 0; i < index; i++) {
                    toReturn = toReturn -> next;
               }
               return toReturn;
          }
          void append(Type toAppend) {
               if(this -> head == NULL) { //list empty
                    this -> head = new Node();
                    this -> head -> value = toAppend;
                    this -> tail = this -> head;
               } else {
                    this -> tail -> next = new Node();
                    this -> tail = this -> tail -> next;
                    this -> tail -> value = toAppend;
               }
               numItems++;
          }
          Type remove(int index) {
               if(index < this -> numItems) {
                    numItems--;
                    if(this -> head == this -> tail) { //list has one item
                         this -> head = NULL;
                         this -> tail = NULL;
                    } else {
                         Node* toRemove = getNode(index);
                         Type toRemoveValue = toRemove -> value;

                         if(toRemove == this -> head) {
                              this -> head = this -> head -> next;
                              delete toRemove;
                         } else {
                              Node* previous = getNode(index - 1);

                              previous -> next = toRemove -> next;
                              delete toRemove;
                         }
                         return toRemoveValue;
                    }
               }
               return -1;
          }
          void insert(Type value, int index) {
               Node* toAdd = new Node();
               toAdd -> value = value;

               if(index <= this -> numItems) {
                    if(index == 0) { //head
                         toAdd -> next = this -> head;
                         head = toAdd;
                    } else {
                         Node* atIndex = getNode(index);
                         Node* previous = getNode(index - 1);

                         toAdd -> next = atIndex;
                         previous -> next = toAdd;
                    }
               }
          }
          int indexOf(Type toFind) {
               int index = 0;
               Node* current = this -> head;
               while(current != NULL) {
                    if(current -> value == toFind) return index;

                    current = current -> next;
                    index++;
               }
               return -1;
          }
};
