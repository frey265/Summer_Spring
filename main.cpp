#include <iostream>
#include "graph.h"

int main() {
    Node A(0);
    Node B(1);
    Node C(2);
    A.addEdge(1,3);
    A.addEdge(2,4);
    B.addEdge(2,5);
    std::vector<Node> Node;
    Node.push_back(A);
    Node.push_back(B);
    Node.push_back(C);
    //dijkstra(Node,0);
    Ford(Node,0);
    int i =0;
    bfs(Node);
    //A->C<-B
    return 0;
}
