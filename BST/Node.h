#include <cstddef>
#include <iostream>
using namespace std;

class Node {
 public:
  Node() {
    m_data = 0;
    m_left = NULL;
    m_right = NULL;
  }

  Node(int data) {
    m_data = data;
    m_left = NULL;
    m_right = NULL;
  }

  ~Node() {
    if(m_left != NULL) {
      delete m_left;
    }

    if(m_right != NULL) {
      delete m_right;
    }

    cout << "Deleting " << m_data << endl;
  }
  
  int getData() {
    return m_data;
  }

  void setData(int data) {
    m_data = data;
  }

  Node *getLeft() {
    return m_left;
  }
  
  Node *getRight() {
    return m_right;
  }

  void setLeft(Node *left) {
    m_left = left;
  }

  void setRight(Node *right) {
    m_right = right;
  }

  void insert(int data);
  void inorderTraversal();
  void preorderTraversal();
  void postorderTraversal();
  
 private:
  int m_data;
  Node *m_left;
  Node *m_right;
};
