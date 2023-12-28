#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// edge bnao
struct edge
{
    int to;
};

//bfs ke lie function 
//                  edge 2x vector named graph
//                  int vector distance
//                  int var start
void bfs(const vector<vector<edge>> &graph, vector<int> &distance, int start)
{
    // queue bnai
    queue<int> q;
    //visited vector
    vector<int> visited(graph.size(), false);

     
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (const edge &e : graph[u])
        {
            int v = e.to;
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                distance[v] = distance[u] + 1;
            }
        }
    }
}
int main()
{
    int n = 6; // Number of cities
    vector<vector<edge>> graph(n);
    // Build the graph with cities and roads
    graph[0].push_back({1}); // Example: Road from city 0 to city 1
    graph[1].push_back({2}); // Example: Road from city 1 to city 2
  
    vector<int> distance(n, -1); // Initialize distance to -1 (unreachable)
    int startCity = 0;           // Start city
    bfs(graph, distance, startCity);

    // Use the distance vector to find the shortest route to other cities
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Shortest distance from city " << startCity << " to city " << i << " is " << distance[i] << std::endl;
    }

    return 0;
}