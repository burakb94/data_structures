#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    int vertex;
    Node* next;
    Node (int vertex) {
      this->vertex = vertex;
      this->next = NULL;
    }
};

class Graph {
  public:
    int numberOfNodes;
    Node** adjList;
    Graph () {
      this->numberOfNodes = 0;
    }
    void addVertex (int node);
    void addEdge (int node1, int node2);
    void showConnections ();
};

void Graph::addVertex(int node) {
  this->adjList[node] = {};
  this->numberOfNodes++;
}

void Graph::addEdge(int node1, int node2) {
  Node* newNode = new Node (node2);
  newNode->next = this->adjList[node1];
  this->adjList[node1] = newNode;

  newNode = new Node (node1);
  newNode->next = this->adjList[node2];
  this->adjList[node2] = newNode;  
}

void Graph::showConnections() {
  for (int i=0; i<this->numberOfNodes; i++) {
    cout<<i<<" --> ";
    while (this->adjList[i]) {
      cout<<this->adjList[i]->vertex<<" ";
      this->adjList[i] = this->adjList[i]->next;
    }
    cout<<endl;
  }
}

int main() {
  Graph myGraph;
  myGraph.addVertex(6);
  myGraph.addVertex(1);
  myGraph.addVertex(2);
  myGraph.addVertex(4);
  myGraph.addVertex(3);
  myGraph.addVertex(5);
  myGraph.addVertex(0);
  myGraph.addEdge(3, 1); 
  myGraph.addEdge(3, 4); 
  myGraph.addEdge(4, 2); 
  myGraph.addEdge(4, 5); 
  myGraph.addEdge(1, 2); 
  myGraph.addEdge(1, 0); 
  myGraph.addEdge(0, 2); 
  myGraph.addEdge(6, 5);

  myGraph.showConnections();  
  return 0;  
} 