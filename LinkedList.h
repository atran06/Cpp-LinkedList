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
          Node* head;
          Node* tail;
          int numItems;
          Node* getHead() {
               return this -> head;
          }
          Node* getTail() {
               return this -> tail;
          }
          Node* getNode(int index) {
               Node* toReturn = this -> head;
               for(int i = 0; i < index; i++) {
                    toReturn = toReturn -> next;
               }
               return toReturn;
          }

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
               numItems = 0;
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
          Type remove(int index) {
               if(index < this -> numItems) {
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
               this -> numItems++;
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
