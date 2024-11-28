#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Representation of infinity

// Function to print the routing table for a node
void printRoutingTable(const vector<int>& dist, int source) {
    cout << "\nRouting Table for Node " << source + 1 << ":\n";
    cout << "Destination\tDistance\n";
    for (int i = 0; i < dist.size(); i++) {
        cout << i + 1 << "\t\t";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

// Function implementing Dynamic Distance Vector Routing (DVR)
void dynamicDVR(const vector<vector<int>>& cost) {
    int n = cost.size(); // Get the number of nodes
    vector<vector<int>> dist = cost; // Copy of the cost matrix

    // Check for proper dimensions
    if (n == 0 || cost[0].size() != n) {
        cerr << "Error: Cost matrix must be square (NxN)." << endl;
        return;
    }

    // Initialize the distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0; // Distance to self is 0
        }
    }

    // Apply Floyd-Warshall algorithm for shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the routing tables for all nodes
    for (int i = 0; i < n; i++) {
        printRoutingTable(dist[i], i);
    }
}

int main() {
    // Define the cost matrix for the network
    vector<vector<int>> cost = {
        {0, 3, INF, 7},
        {3, 0, 2, INF},
        {INF, 2, 0, 1},
        {7, INF, 1, 0}
    };  

    // Perform Dynamic DVR
    dynamicDVR(cost);

    return 0;
}
