#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
  m_head = NULL;
  m_tail = NULL;
}

Queue::~Queue() {
  clear();
}

void Queue::enqueue(int data) {
  if(isEmpty()) {
    m_head = new Node;
    m_head->setData(data);
    m_head->setNext(NULL);
    m_tail = m_head;
  } else {

    Node *prev = m_tail;
    /*for(Node *temp = m_head; temp != NULL; temp = temp->getNext()) {
      if(temp->getNext() == NULL) {
	prev = temp;
      }
      }*/

    Node *newNode = new Node;
    newNode->setNext(NULL);
    newNode->setData(data);
    prev->setNext(newNode);
    m_tail = newNode;
  }
}

int Queue::dequeue() {
  if(isEmpty()) {
    return 0;
  }
  
  int data = m_head->getData();
  Node *temp = m_head;
  m_head = m_head->getNext();
  delete temp;
  return data;
}

int Queue::front() { }

void Queue::clear() {
  while(!isEmpty()) {
    dequeue();
  }
}

bool Queue::isEmpty() {
  return m_head == NULL;
}

Queue::QueueIterator Queue::qBegin() {
  return QueueIterator(m_head);
}

Queue::QueueIterator Queue::qEnd() {
  return QueueIterator(NULL);
}

Queue::QueueIterator::QueueIterator(Node * node) {
  m_node = node;
}

void Queue::QueueIterator::operator++(int dummy) {
  m_node = m_node->getNext();
}

bool Queue::QueueIterator::operator!=(const Queue::QueueIterator& rhs) {
  return m_node != rhs.m_node;
}

int Queue::QueueIterator::operator*() {
  return m_node->getData();
}
