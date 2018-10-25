/***************************************************************************
 * Filename: main.cpp
 * Description: Runs tests for the LinkedList class
 * Last Modified: 10-25-18
 * Author: Arthur Tran
 *
 * https://arthurtran.com/
 ***************************************************************************/

#include <iostream>
#include "LinkedList.h"

using namespace std;

void populate(LinkedList<int>& list) {
     for(int i = 0; i < 10; i++) {
          list.append((i + 1) * 10);
     }
}

int main() {
     LinkedList<int> list;
     populate(list);

     list.print();
     cout << endl;

     list.insert(55, 5);

     list.print();
     cout << endl;

     list.remove(5);

     list.print();
     cout << endl;

     list.clear();

     list.print();

     return 0;
}
