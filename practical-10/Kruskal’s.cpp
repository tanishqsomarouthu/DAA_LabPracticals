
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[10];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int main() {
    int n, m;
    Edge e[20];

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(e, e + m, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0, count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < m && count < n - 1; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);

        if (a != b) {
            cout << e[i].u << " - " << e[i].v
                 << " : " << e[i].w << endl;

            parent[a] = b;
            cost += e[i].w;
            count++;
        }
    }

    if (count == n - 1)
        cout << "Minimum cost = " << cost << endl;
    else
        cout << "Spanning tree not possible\n";

    return 0;
}
