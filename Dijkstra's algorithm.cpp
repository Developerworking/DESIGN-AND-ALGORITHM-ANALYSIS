#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination, weight;
};

void dijkstra(int start, const vector<vector<Edge>>& graph, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    distances[start] = 0;

    using pii = pair<int, int>; // pair (distance, node)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distances[node]) continue;

        for (const Edge& edge : graph[node]) {
            int nextNode = edge.destination;
            int nextDist = dist + edge.weight;

            if (nextDist < distances[nextNode]) {
                distances[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // If the graph is undirected
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distances;
    dijkstra(start, graph, distances);

    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INF) {
            cout << "Node " << i << " is unreachable" << endl;
        } else {
            cout << "Node " << i << " : " << distances[i] << endl;
        }
    }

    return 0;
}
