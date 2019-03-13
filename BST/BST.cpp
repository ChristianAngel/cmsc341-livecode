#include <iostream>
#include "BST.h"

using namespace std;

void BST::insert(int data) {
  if(m_root == NULL) {
    Node *newNode = new Node(data);
    m_root = newNode;
  } else {
    m_root->insert(data);
  }
}

void BST::inorderTraversal() {
  if(m_root != NULL) {
    m_root->inorderTraversal();
    cout << endl;
  } else {
    cout << "Tree is empty" << endl;
  }
}

void BST::preorderTraversal() {
  if(m_root != NULL) {
    m_root->preorderTraversal();
    cout << endl;
  } else {
    cout << "Tree is empty" << endl;
  }
}

void BST::postorderTraversal() {
  if(m_root != NULL) {
    m_root->postorderTraversal();
    cout << endl;
  } else {
    cout << "Tree is empty" << endl;
  }
}
