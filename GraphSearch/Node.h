#ifndef NODE_H
#define NODE_H

#include <utility>
#include <vector>

using namespace std;

class Node {
 public:
  Node() {
    m_value = 0;
  }

  Node(int value) {
    m_value = value;
  }

  void addNeighbor(Node *newNode, int weight) {
    m_neighbors.push_back(make_pair(newNode, weight));
  }

  void printNeighbors() {
    for(unsigned int i = 0; i < m_neighbors.size(); ++i) {
      cout << m_neighbors[i].first->m_value << endl;
    }
  }

  vector<pair<Node *, int> > getNeighbors() {
    return m_neighbors;
  }

  int getValue() {
    return m_value;
  }
 private:
  int m_value;
  vector<pair<Node *, int> > m_neighbors;
};

#endif
