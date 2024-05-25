#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

// Graph class represents a directed graph using adjacency list representation
class Graph {
    int V; // Number of vertices in the graph
    vector<vector<iPair>> adj; // Adjacency list

public:
    Graph(int V); // Constructor

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w);

    // Prints shortest path from src to all other vertices
    void shortestPath(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w)); // For undirected graph
}

// Function to find the shortest path from a source node to all other nodes using Dijkstra's algorithm
void Graph::shortestPath(int src) {
    // Create a priority queue to store vertices that are being preprocessed
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Create a vector for distances and initialize all distances as infinite (INT_MAX)
    vector<int> dist(V, INT_MAX);

    // Insert source itself in priority queue and initialize its distance as 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    // Looping till priority queue becomes empty (or all distances are finalized)
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance vertex, extract it from the priority queue
        // Vertex label is stored in second of pair (it has to be done this way to keep the vertices sorted
        // distance (distance must be the first item in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current adjacent of u
            int v = (*i).first;
            int weight = (*i).second;

            // If there is a shorter path to v through u
            if (dist[v] > dist[u] + weight) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    // Create a graph given in the above diagram
    int V = 9;
    Graph g(V);

    // Adding edges
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // Function call
    g.shortestPath(0);

    return 0;
}
