#include "Node.h"

class Queue {
 public:
  Queue();
  ~Queue();
  void enqueue(int data);
  int dequeue();
  int front();
  void clear();
  bool isEmpty();

  class QueueIterator {
    
  public: 
    // Constructor for iterator for vertices adjacent to vertex v;
    // indx can be used to set m_indx for begin and end iterators
    QueueIterator(Node *node);

    // Compare iterators; only makes sense to compare with
    // end iterator
    bool operator!=(const QueueIterator& rhs);

    // Move iterator to next neighbor
    void operator++(int dummy);

    // Return neighbor at current iterator position
    int operator*();

  private:
    Node *m_node;
  };

  // Make an initial neighbor iterator
  QueueIterator qBegin();

  // Make an end neighbor iterator
  QueueIterator qEnd();

 private:
  Node * m_head;
  Node * m_tail;

};
