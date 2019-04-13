#include <iostream>

#include "Heap.h"

using namespace std;


int main() {
  Heap myHeap;
  cout << myHeap.getLeft(2) << endl;
  cout << myHeap.getRight(2) << endl;
  cout << myHeap.getParent(5) << endl;
  cout << myHeap.getParent(6) << endl;

}
