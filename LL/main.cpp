#include <iostream>
#include "LL.h"

using namespace std;

int main() {
  LL myList;
  myList.insertBegin(0);
  myList.insertBegin(1);
  myList.insertBegin(2);
  myList.insertBegin(3);
  myList.insertBegin(4);
  myList.print();
  cout << myList.deleteAt(2) << endl;
  myList.print();
  cout << myList.deleteAt(1) << endl;
  myList.print();
  cout << myList.deleteAt(2) << endl;
  myList.print();
  return 0;
}
