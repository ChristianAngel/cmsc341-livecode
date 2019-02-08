#include "Node.h"

class LL {
 public:
  LL();
  ~LL();
  void insertBegin(int data);
  void insertEnd(int data);
  int deleteBegin();
  int deleteEnd();
  int deleteAt(int index);
  void print();
 private:
  Node *m_head;
  Node *m_tail;
};
