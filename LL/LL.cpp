#include <cstddef>
#include <iostream>
#include "LL.h"

using namespace std;

LL::LL() {
  m_head = NULL;
  m_tail = NULL;
}

LL::~LL() {
  while(m_head) {
    Node *temp = m_head;
    m_head = m_head->getNext();
    delete temp;
  }
}

void LL::insertBegin(int data) {
  Node *newNode = new Node();
  newNode->setData(data);
  newNode->setNext(m_head);
  newNode->setPrev(NULL);
  if(m_head) {
    m_head->setPrev(newNode);
  }
  m_head = newNode;
  if(!m_tail) {
    m_tail = m_head;
  }
}

void LL::insertEnd(int data) {
  Node *newNode = new Node();
  newNode->setData(data);
  newNode->setNext(NULL);
  newNode->setPrev(m_tail);
  if(m_tail) {
    m_tail->setNext(newNode);
  }
  m_tail = newNode;
  if(!m_head) {
    m_head = m_tail;
  }
}

int LL::deleteBegin() {
  if(!m_head) {
    return 0;
  }

  int data = m_head->getData();

  Node *temp = m_head;
  m_head = m_head->getNext();

  if(m_head) {
    m_head->setPrev(NULL);
  } else {
    m_tail = NULL;
  }

  delete temp;
  
  return data;
}

int LL::deleteEnd() {
  if(!m_tail) {
    return 0;
  }

  int data = m_tail->getData();

  Node *temp = m_tail;
  m_tail = m_tail->getPrev();

  if(m_tail) {
    m_tail->setNext(NULL);
  } else {
    m_head = NULL;
  }

  delete temp;
  
  return data;
}

int LL::deleteAt(int index) {
  Node *temp = m_head;

  for(int i = 0; i < index; i++) {
    temp = temp->getNext();
  }

  if(temp == m_head) {
    return deleteBegin();
  }

  if(temp == m_tail) {
    return deleteEnd();
  }

  int data = temp->getData();
  Node *prev = temp->getPrev();
  Node *next = temp->getNext();
  prev->setNext(next);
  next->setPrev(prev);

  delete temp;
  return data;
}

void LL::print() {
  for(Node *temp = m_head; temp != NULL; temp = temp->getNext()) {
    cout << temp->getData() << " ";
  }
  cout << endl;
}
