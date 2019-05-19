#include <iostream>
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

  void addNeighbor(Node *newNode) {
    m_neighbors.push_back(newNode);
  }

  void printNeighbors() {
    for(unsigned int i = 0; i < m_neighbors.size(); ++i) {
      cout << m_neighbors[i]->m_value << endl;
    }
  }

  bool dfs(int destination) {
    if(m_value == destination) {
      return true;
    }
    for(unsigned int i = 0; i < m_neighbors.size(); ++i) {
      cout << "Going to " << m_neighbors[i]->m_value << endl;
      bool success = m_neighbors[i]->dfs(destination);
      if(success) {
	return true;
      } else {
	cout << "Backtracking to " << m_value << endl;
      }
    }
    return false;
  }
 private:
  int m_value;
  vector<Node *> m_neighbors;
};

class Graph {
 public:
  Graph() {
    // empty
  }

  Graph(int numNodes) {
    for(int i = 0; i < numNodes; ++i) {
      m_nodes.push_back(new Node(i));
    }
  }

  Node *getNode(int index) {
    return m_nodes[index];
  }

  void addEdge(int source, int destination) {
    m_nodes[source]->addNeighbor(m_nodes[destination]);
  }

  void dfs(int source, int destination) {
    cout << m_nodes[source]->dfs(destination) << endl;
  }
 private:
  vector<Node *> m_nodes;
};

int main() {
  Graph myGraph(10);
  myGraph.addEdge(4, 5);
  myGraph.getNode(4)->printNeighbors();
  myGraph.dfs(4, 5);
  myGraph.dfs(5, 4);
  return 0;
}
