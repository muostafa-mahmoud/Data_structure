#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
class Graph {
private:
    // Number of vertices
    int V;
    // Adjacency list
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // For undirected graph
        adj[v].push_back(u);
    }

    // Function to check if the current color assignment is safe for vertex v
    bool isSafe(int v, const vector<int>& color, int c) {
        for (int neighbor : adj[v]) {
            if (color[neighbor] == c) {
                // Not safe if the neighbor has the same color
                return false;
            }
        }
        return true;
    }

    // Recursive function to solve the graph coloring problem
    bool graphColoringUtil(int m, int v, vector<int>& color) {
        if (v == V) {
            // All vertices are assigned a color
            return true;
        }

        for (int c = 1; c <= m; c++) {
            if (isSafe(v, color, c)) {
                // Assign color c to vertex v
                color[v] = c;
                if (graphColoringUtil(m, v + 1, color)) {
                    // If successful, return true
                    return true;
                }
                // Backtrack
                color[v] = 0;
            }
        }
        // No valid color found
        return false;
    }

    // Function to solve the graph coloring problem
    bool graphColoring(int m) {
        // Initialize all vertices as uncolored
        vector<int> color(V, 0);
        return graphColoringUtil(m, 0, color);
    }
};

// Function to measure execution time of a function
template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args... args) {
    auto start = high_resolution_clock::now();
    func(args...);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    // Return time in seconds
    return duration.count();
}

int main() {
    // Number of vertices
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    // Number of colors
    int m = 3;

    // Measure time for graph coloring
    double coloringTime = measureExecutionTime([&g, m]() {
        if (g.graphColoring(m)) {
            cout << "Graph can be colored with " << m << " colors." << endl;
        } else {
            cout << "Graph cannot be colored with " << m << " colors." << endl;
        }
    });

    cout << "Time taken to color the graph: " << coloringTime << " seconds" << endl;

    return 0;
}