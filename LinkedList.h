/***************************************************************************
 * C++ LinkedList
 *
 * Filename: LinkedList.h
 * Description: An implementation of a Singly LinkedList in C++ following
 *              the same method structure as the Java one.
 * Last Modified: 10-25-18
 * Author: Arthur Tran
 *
 * https://arthurtran.com/
 * https://github.com/atran06/Cpp-LinkedList
 ***************************************************************************/

#pragma once

#include <iostream>

template<typename Type>
class LinkedList {
     struct Node {
          Type value;
          Node* next;
     };

     private:
          Node* head; //the first Node in the list
          Node* tail; //the last Node in the list
          int numItems; //keeps track of how many Nodes are in the list

          /*
           * Getters
           */
          Node* getHead() {
               return this -> head;
          }
          Node* getTail() {
               return this -> tail;
          }
          Node* getNode(int index) { //returns the Node at specified index
               Node* toReturn = this -> head;
               for(int i = 0; i < index; i++) {
                    toReturn = toReturn -> next;
               }
               return toReturn;
          }

     public:
          /*
           * Constructor and Destructor
           */
          LinkedList() : head(NULL), tail(NULL), numItems(0) {}

          ~LinkedList() {
               Node* current = this -> head;
               while(current != NULL) {
                    Node* temp = current -> next;
                    delete current;
                    current = temp;
               }
          }

          /*
           * Function: clear()
           * Desc: Goes through every node in the list and deletes it.
           * Params: none
           * Returns: void
           */
          void clear() {
               Node* current = this -> head;
               while(current != NULL) {
                    Node* temp = current -> next;
                    delete current;
                    current = temp;
               }
               head = NULL;
               tail = NULL;
               numItems = 0;
          }

          /*
           * Function: size()
           * Desc: Returns the size of the list.
           * Params: none
           * Returns: Returns numItems
           */
          int size() {
               return this -> numItems;
          }

          /*
           * Function: get()
           * Desc: Gets the Node's value at specified index
           * Params:
          *    index - The index to obtain the value from
           * Returns: Returns the Node's value variable
           */
          Type get(int index) {
               Node* toReturn = this -> head;
               for(int i = 0; i < index; i++) {
                    toReturn = toReturn -> next;
               }
               return toReturn -> value;
          }

          /*
           * Function: append()
           * Desc: Creates a new Node with the specified Type as the value and adds it to the end
           *       of the list.
           * Params:
           *   toAppend - The value to append to the list
           * Returns: void
           */
          void append(Type toAppend) {
               Node* toAdd = new Node();
               toAdd -> value = toAppend;

               if(this -> head == NULL) { //list empty
                    this -> head = toAdd;
                    this -> tail = this -> head;
               } else {
                    this -> tail -> next = toAdd;
                    this -> tail = toAdd;
               }
               numItems++;
          }

          /*
           * Function: prepend()
           * Desc: Creates a new Node with the specified Type as the value and adds it to the beginning
           *       of the list.
           * Params:
           *   toPrepend - The value to prepend to the list
           * Returns: void
           */
          void prepend(Type toPrepend) {
               Node* toAdd = new Node();
               toAdd -> value = toPrepend;

               if(this -> head == NULL) { //list empty
                    this -> head = toAdd;
                    this -> tail = toAdd;
               } else {
                    toAdd -> next = this -> head;
                    this -> head = toAdd;
               }
               numItems++;
          }

          /*
           * Function: toRemove()
           * Desc: Removes a Node at the specified index from the list
           * Params:
           *   index - Index to remove
           * Returns: Returns the Node's value that has just been removed or NULL if nothing was removed
           */
          Type remove(int index) {
               if(index < this -> numItems) { //accounts for an empty list as well
                    this -> numItems--;
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
               return NULL;
          }

          /*
           * Function: insert()
           * Desc: Creates a new Node with the specified Type as the value and inserts it at the
           *       specified index.
           * Params:
           *   value - The value to insert into the list
           *   index - Index to insert to
           * Returns: void
           */
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
               this -> numItems++;
          }

          /*
           * Function: indexOf()
           * Desc: Gets the index of the specified Type in the list
           * Params:
           *   toFind - The Type to find
           * Returns: Returns the index of the Type or -1 if not found
           */
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
