#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Comparator function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Union-Find structure to detect cycles
class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compare);
    
    UnionFind uf(V);
    vector<Edge> result;
    
    for (auto edge : edges) {
        int srcRoot = uf.find(edge.src);
        int destRoot = uf.find(edge.dest);
        
        if (srcRoot != destRoot) {
            result.push_back(edge);
            uf.unite(srcRoot, destRoot);
        }
    }
    
    return result;
}

int main() {
    int V = 4; // Number of vertices
    vector<Edge> edges;
    
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));
    
    vector<Edge> mst = kruskalMST(edges, V);
    
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (auto edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    
    return 0;
}
