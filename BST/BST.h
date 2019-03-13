#include <cstddef>
#include "Node.h"

class BST {
 public:
  BST() {
    m_root = NULL;
  }

  ~BST() {
    delete m_root;
  }

  void insert(int data);
  void inorderTraversal();
  void preorderTraversal();
  void postorderTraversal();

  
 private:
  Node *m_root;
};
