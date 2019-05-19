#ifndef PATH_H
#define PATH_H

#include <vector>
#include "Node.h"

using namespace std;

class Path {
 public:
  Path() {
    m_pathCost = 0;
  }
  
  void addNode(Node *node, int weight) {
    m_path.push_back(node);
    m_pathCost += weight;
  }

  Node *getLast() {
    return m_path.back();
  }

  bool operator>(const Path& rhs) {
    return m_pathCost < rhs.m_pathCost;
  }

  bool operator<(const Path& rhs) {
    return m_pathCost > rhs.m_pathCost;
  }

  friend ostream& operator<<(ostream &out, const Path& path);
private:
  int m_pathCost;
  vector<Node *> m_path;
};

ostream& operator<<(ostream &out, const Path& path) {
  out << "(" << path.m_pathCost << ") ";
  for(vector<Node *>::const_iterator it = path.m_path.begin(); it != path.m_path.end(); ++it) {
    if(it == path.m_path.begin()) {
      out << (*it)->getValue();
    } else {
      out << "->" << (*it)->getValue();
    }
  }
  return out;
}

#endif
