#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Define infinite as a large number. We use the maximum value for a variable of type int.
const int INF = numeric_limits<int>::max();

// Function to run Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;

    // Adding vertices individually
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Define the number of vertices in the graph
    int V = 4;

    // Define the graph as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}
