#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// uses stack

// function
void dfs(vector<vector<int>> adj_list, int starting_node)
{
    // var = size of list
    int num_node = adj_list.size();
    // stack for traversal
    stack<int> stk;
    // bool vector visisted to record nodes
    vector<bool> visited(num_node, false);
    // stack me starting node daal do, true kr do visited iska
    stk.push(starting_node);
    visited[starting_node] = true;

    cout << "DFS order:"<<endl;
    // function bnao
    while (!stk.empty())
    {
        // condition ke stack khali na ho

        // curr node stack ka top, value print kro, pop kra do
        int current_node = stk.top();
        stk.pop();
        cout << current_node << " ";

        // adjacency matrix explore kro
        for (int neighbour : adj_list[current_node])
        {
            if (!visited[neighbour])
            {
                stk.push(neighbour);
                visited[neighbour] = true;
            }
        }
        cout << endl;
    }
}
int main()
{
    // Example adjacency list representation of the graph
    vector<vector<int>> adjacency_list = {
        {1, 2},    // Node 0
        {0, 2, 3}, // Node 1
        {0, 1, 4}, // Node 2
        {1, 4},    // Node 3
        {2, 3}     // Node 4
    };

    int starting_node = 0; // Set the starting node for DFS

    // Call the DFS function with the adjacency list and starting node
    dfs(adjacency_list, starting_node);

    return 0;
}