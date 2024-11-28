# include <iostream>
# include <climits>

using namespace std;

const int V = 5;

int minDistance(int g[V][V],int dist[V],bool visited[V]){
    int min_index;
    int min = INT_MAX;
    for(int i = 0 ; i < V ; i++){
        if(dist[i] < min && !visited[i]){
            min = dist[i];
            min_index = i;
        }
    }return min_index;
}
void printSolution(int g[V][V],int dist[V]){
    cout << "Printing final table... " << endl;
    cout << "Vertex \tDistance from Source\n";
    for(int i = 0 ; i < V ; i++){
        cout << i << "\t" << dist[i] << "\n";
    }
}
void Dijkstra(int g[V][V],int src){
    int dist[V];
    bool visited[V];

    for(int i = 0 ; i < V ; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;

    for(int count = 0 ; count < V-1 ; count++){
        int u = minDistance(g,dist,visited);
        visited[u] = true;
        for(int v = 0 ; v < V ; v++){
            if(g[u][v] && !visited[v] && g[u][v] + dist[u] < dist[v] && dist[u] != INT_MAX){
                dist[v] = dist[u] + g[u][v];
            }
        }
    }
    printSolution(g,dist);
}

int main(){
    int g[V][V];
    cout << "Enter the adjacency matrix : " << endl;
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            cin >> g[i][j];
        }
    }
    
    Dijkstra(g,0);
    return 0;
}