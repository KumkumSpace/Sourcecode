#include <iostream>
#include <vector>
//Graph Coloring (Greedy Algorithm)
class Graph {
public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void greedyColoring() {
        std::vector<int> result(V, -1);
        result[0] = 0;

        for (int u = 1; u < V; ++u) {
            std::vector<bool> available(V, true);
            for (int neighbor : adj[u]) {
                if (result[neighbor] != -1) {
                    available[result[neighbor]] = false;
                }
            }

            for (int color = 0; color < V; ++color) {
                if (available[color]) {
                    result[u] = color;
                    break;
                }
            }
        }

        for (int u = 0; u < V; ++u) {
            std::cout << "Vertex " << u << " ---> Color " << result[u] << std::endl;
        }
    }

private:
    int V;
    std::vector<std::vector<int>> adj;
};
