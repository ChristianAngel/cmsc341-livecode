#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

int main() {
  srand(time(NULL));
  
  BST myBST;
  for(int i = 0; i < 20; i++) {
    myBST.insert(rand() % 100);
  }
  cout << "In Order: ";
  myBST.inorderTraversal();
  cout << "Pre Order: ";
  myBST.preorderTraversal();
  cout << "Post Order: ";
  myBST.postorderTraversal();
}
