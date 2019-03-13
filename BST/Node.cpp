#include <iostream>
#include "Node.h"

using namespace std;

void Node::insert(int data) {
  if(data != m_data) {
    if(data < m_data) {
      if(m_left == NULL) {
        m_left = new Node(data);
      } else {
	m_left->insert(data);
      }
    }
    if(data > m_data) {
      if(m_right == NULL) {
        m_right = new Node(data);
      } else {
	m_right->insert(data);
      }
    }
  }
}

void Node::preorderTraversal() {
  cout << m_data << ' ';
  if(m_left) {
    m_left->preorderTraversal();
  }
  if(m_right) {
    m_right->preorderTraversal();
  }
}

void Node::inorderTraversal() {
  if(m_left) {
    m_left->inorderTraversal();
  }
  cout << m_data << ' ';
  if(m_right) {
    m_right->inorderTraversal();
  }
}

void Node::postorderTraversal() {
  if(m_left) {
    m_left->postorderTraversal();
  }
  if(m_right) {
    m_right->postorderTraversal();
  }
  cout << m_data << ' ';
}
