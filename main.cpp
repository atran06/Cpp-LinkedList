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

void print(LinkedList<int>& list) {
     for(int i = 0; i < list.size(); i++) {
          cout << list.get(i) << " ";
     }
     cout << endl;
}

int main() {
     LinkedList<int> list;
     populate(list);

     print(list);
     cout << endl;

     list.prepend(5);

     print(list);
     cout << endl;

     list.insert(55, 5);

     print(list);
     cout << endl;

     list.remove(5);

     print(list);
     cout << endl;

     list.clear();

     print(list);

     return 0;
}
