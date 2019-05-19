#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Node.h"
#include "Path.h"

using namespace std;

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

  void addEdge(int source, int destination, int weight) {
    m_nodes[source]->addNeighbor(m_nodes[destination], weight);
  }

  Path dfs(int source, int destination) {
    stack<Path> stack;
    Node *sourceNode = m_nodes[source];
    Node *destNode = m_nodes[destination];
    Path starter;
    starter.addNode(sourceNode, 0);
    stack.push(starter);
    while(true) {
      Path currentPath = stack.top();
      stack.pop();
      Node *endNode = currentPath.getLast();
      if(endNode == destNode) {
	return currentPath;
      }

      vector<pair<Node *, int> > neighbors = endNode->getNeighbors();
      for(int i = 0; i < neighbors.size(); ++i) {
	Path newPath(currentPath);
	newPath.addNode(neighbors[i].first, neighbors[i].second);
	stack.push(newPath);
      }
    }
  }

  Path bfs(int source, int destination) {
    queue<Path> queue;
    Node *sourceNode = m_nodes[source];
    Node *destNode = m_nodes[destination];
    Path starter;
    starter.addNode(sourceNode, 0);
    queue.push(starter);
    while(true) {
      Path currentPath = queue.front();
      queue.pop();
      Node *endNode = currentPath.getLast();
      if(endNode == destNode) {
	return currentPath;
      }

      vector<pair<Node *, int> > neighbors = endNode->getNeighbors();
      for(int i = 0; i < neighbors.size(); ++i) {
	Path newPath(currentPath);
	newPath.addNode(neighbors[i].first, neighbors[i].second);
	queue.push(newPath);
      }
    }
  }

  Path ucs(int source, int destination) {
    priority_queue<Path> priority_queue;
    Node *sourceNode = m_nodes[source];
    Node *destNode = m_nodes[destination];
    Path starter;
    starter.addNode(sourceNode, 0);
    priority_queue.push(starter);
    while(true) {
      Path currentPath = priority_queue.top();
      priority_queue.pop();
      Node *endNode = currentPath.getLast();
      if(endNode == destNode) {
	return currentPath;
      }

      vector<pair<Node *, int> > neighbors = endNode->getNeighbors();
      for(int i = 0; i < neighbors.size(); ++i) {
	Path newPath(currentPath);
	newPath.addNode(neighbors[i].first, neighbors[i].second);
	priority_queue.push(newPath);
      }
    }
  }

  /*
  void dfs(int source, int destination) {
    cout << m_nodes[source]->dfs(destination) << endl;
  }
  */
 private:
  vector<Node *> m_nodes;
};

int main() {
  Graph myGraph(10);
  myGraph.addEdge(1, 2, 2);
  myGraph.addEdge(1, 4, 8);
  myGraph.addEdge(2, 3, 3);
  myGraph.addEdge(3, 4, 1);

  Path dfsresult = myGraph.dfs(1, 4);
  Path bfsresult = myGraph.bfs(1, 4);

  cout << dfsresult << endl;
  cout << bfsresult << endl;

  //myGraph.dfs(4, 5);
  //myGraph.dfs(5, 4);
  return 0;
}
