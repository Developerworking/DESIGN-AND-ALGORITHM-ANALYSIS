#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

void primMST(vector<vector<iPair>>& adj, int V) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    
    pq.push(make_pair(0, 0));
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto& [v, weight] : adj[u]) {
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << " \n";
}

int main() {
    int V = 9;
    vector<vector<iPair>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    };

    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    primMST(adj, V);

    return 0;
}
