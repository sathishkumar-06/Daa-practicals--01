
#include <iostream>
#include <algorithm>
using namespace std;

#define V 4
#define E 5

struct Edge {
    int src, dest, weight;
};

int parent[V];

int find(int i) {
    if (parent[i] == i)
        return i;

    return parent[i] = find(parent[i]);
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    parent[rootX] = rootY;
}

void kruskalMST(Edge edges[]) {

    sort(edges, edges + E,
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges in Minimum Spanning Tree:\n";

    int totalCost = 0;
    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {

        int x = find(edges[i].src);
        int y = find(edges[i].dest);

        if (x != y) {

            cout << edges[i].src << " - "
                 << edges[i].dest << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unite(x, y);
            count++;
        }
    }

    cout << "Total Minimum Cost: " << totalCost;
}

int main() {

    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges);

    return 0;
}
