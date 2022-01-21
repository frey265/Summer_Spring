#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>

    struct Edge{
        int to;
        int weight;
        Edge(int putTo, int putWeight)
        {
            this->to = putTo;
            this->weight = putWeight;
        }
    };
    struct Node{
        int id;
        std::vector<Edge> edges;
        void addEdge(int to, int weight)
        {
            edges.emplace_back(to, weight);
        }
        Node(int inputId){
            this->id = inputId;
        }
    };

    void check(std::vector<Node>& Graph, int nodeId, std::vector<bool>& wasVisited)
    {
        wasVisited[nodeId] = true;
        std::cout<<nodeId <<std::endl;
        for (int i = 0; i < Graph[nodeId].edges.size(); ++i)
        {
            if (!wasVisited[Graph[nodeId].edges[i].to])
            {
                check(Graph, Graph[nodeId].edges[i].to , wasVisited);
            }
        }
    }

    void cycle(std::vector<Node>& Graph)
    {
        std::vector<bool> wasVisited(Graph.size(), false);
        for (int i = 0; i < Graph.size(); ++i)
        {
            if (!wasVisited[i])
            {
                check(Graph, i, wasVisited);
            }
        }

    }

    void bfs(std::vector<Node>& Graph) //width
    {
        std::queue<int> q;
        std::vector<bool> wasVisited(Graph.size(), false);

        for (int i = 0; i < Graph.size(); ++i)
        {
            if (!wasVisited[i])
            {
                wasVisited[i] = true;
                q.push(i);

                while (!q.empty())
                {
                    int u = q.front();
                    std::cout << u << std::endl;
                    q.pop();
                    for (int j = 0; j < (int) Graph[u].edges.size(); j++)
                    {
                        if (!wasVisited[Graph[u].edges[j].to])
                        {
                            wasVisited[Graph[u].edges[j].to] = true;
                            q.push(Graph[u].edges[j].to);

                        }
                    }
                }
            }


        }

    }

    void dfs(std::vector<Node>& Graph)  // depth
    {
        std::stack<int> s;
        std::vector<bool> wasVisited(Graph.size(), false);

        for (int i = 0; i < Graph.size(); ++i)
        {
            if (!wasVisited[i])
            {
                wasVisited[i] = true;
                s.push(i);

                while (!s.empty())
                {
                    int u = s.top();
                    s.pop();
                    std::cout << u << std::endl;
                    for (int j = 0; j < (int) Graph[u].edges.size(); j++)
                    {
                        if (!wasVisited[Graph[u].edges[j].to])
                        {
                            wasVisited[Graph[u].edges[j].to] = true;
                            s.push(Graph[u].edges[j].to);

                        }
                    }
                }
            }


        }

    }

    void dijkstra(std::vector<Node>& Graph, int u)
    {
        std::vector <std::vector <int> > Matrix(Graph.size(), std::vector <int> (Graph.size(), INT16_MAX) );
        for (int i = 0; i < Graph.size(); ++i)
        {
            for (int j = 0; j < Graph[i].edges.size(); ++j)
            {
                if (i == j)
                {
                    Matrix[i][j] = 0;
                } else {
                    Matrix[i][Graph[i].edges[j].to] = Graph[i].edges[j].weight;
                }
            }
        }

        std::vector<int> dist(Graph.size(), INT16_MAX);
        std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater<std::pair<int,int>>> q;
        dist[u] = 0;

        q.push(std::make_pair(0, u));
        while (!q.empty())
        {
            std::pair<int, int> u = q.top();
            q.pop();
            if (u.first > dist[u.second]) continue;
            for (int i = 0; i < (int) Graph.size(); i++)
            {
                int v = i, len = Matrix[u.second][i];

                if (dist[v] > dist[u.second] + len)
                {
                    dist[v] = dist[u.second] + len;
                    q.push(std::make_pair(dist[v], v));
                }
            }
        }
        int k = 0;
    }

    void Ford(std::vector<Node>& Graph, int u)
    {
        std::vector <std::vector <int> > Matrix(Graph.size(), std::vector <int> (Graph.size(), INT16_MAX) );
        for (int i = 0; i < Graph.size(); ++i)
        {
            for (int j = 0; j < Graph[i].edges.size(); ++j)
            {
                if (i == j)
                {
                    Matrix[i][j] = 0;
                } else {
                    Matrix[i][Graph[i].edges[j].to] = Graph[i].edges[j].weight;
                }
            }
        }
        for (int k = 0; k < Graph.size(); k++)
        {	//We go through all the vertices and look for a shorter path through the vertex k
            for (int i = 0; i < Graph.size(); i++)
            {
                for (int j = 0; j < Graph.size(); j++)
                {
                    Matrix[i][j] = std::min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
                    //The new edge value is the minimum between the old edge and the sum of the edges
                }
            }
        }
        std::vector<int>dist = Matrix[u];
        int k = 0;
    }
#endif //LAB3_GRAPH_H
