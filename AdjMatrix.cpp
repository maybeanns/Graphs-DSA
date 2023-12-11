#include <iostream>
#include <vector>

using namespace std;

void adjmatrix(vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num_node = 5;

    vector<vector<int>> adj_matrix(num_node, vector<int>(num_node, 0));

    adj_matrix[0][2] = 1;
    adj_matrix[0][1] = 1;
    adj_matrix[1][3] = 1;
    adj_matrix[1][2] = 1;
    adj_matrix[2][4] = 1;
    adj_matrix[2][3] = 1;
    adj_matrix[4][2] = 1;
    adj_matrix[3][0] = 1;
    adj_matrix[4][0] = 1;

    cout << "Adjacency Matrix:" << endl;
    adjmatrix(adj_matrix);
}

