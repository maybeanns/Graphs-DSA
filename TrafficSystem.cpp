// driving map using graph
#include <bits/stdc++.h>
using namespace std;

// vertex= point A, B
// edge= road
// edge weight = time taken to go from point A to B

class Graph
{
    private:
    struct edge
    {
        int weight;
        int destination;
    };

    struct node
    {
        vector<edge> edges;
    };

    vector<node> nodes;


public:
      Graph(int numNodes) : nodes(numNodes) {}

    void addEdge(int source, int destination, int weight) {
        nodes[source].edges.push_back({destination, weight});
        nodes[destination].edges.push_back({source, weight});
    }

   vector<int> dijkstra(int start) {
        int numNodes = nodes.size();
       vector<int> distance(numNodes, numeric_limits<int>::max());
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const edge& edge : nodes[u].edges) {
                int v = edge.destination;
                int weight = edge.weight;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        return distance;
    }
};

int main() {
    // Number of nodes in the graph
    const int numNodes = 5;

    // Create a graph
    Graph graph(numNodes);

    // Adding edges with weights (travel time)
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 10);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 9);
    graph.addEdge(2, 3, 6);
    graph.addEdge(3, 4, 7);

    // Taking user input for source and destination
    int source, destination;
    cout << "Enter source node: ";
    cin >> source;
    cout << "Enter destination node: ";
    cin >> destination;

    // Finding the shortest path using Dijkstra's algorithm
    vector<int> shortestPath = graph.dijkstra(source);

    // Output the shortest travel time
    cout << "Shortest travel time from node " << source << " to node " << destination << ": " << shortestPath[destination] <<endl;

    return 0;
}