# include <iostream>
# include <vector>
# include <limits>

using namespace std;

vector<int> BF(vector<vector<int>> &edgeList,int V,int source){
    vector<int> dist(V,numeric_limits<int>::max());
    dist[source] = 0;

    for(int i = 0 ; i < V ; i++){
        for(const auto &edge : edgeList){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] + w < dist[v] && dist[u] != numeric_limits<int>::max()){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(const auto &edge : edgeList){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if(dist[u] + w < dist[v] && dist[u] != numeric_limits<int>::max()){
            cout << "Negative weight cycle detected!\n";
            return {};
        }
    }
    return dist;
}
int main(){
    int vertices,edges,source;

    cout << "No of Vertices : ";
    cin >> vertices;

    cout << "No of Edges : ";
    cin >> edges;

    cout << "Source vertex : ";
    cin >> source;

    vector<vector<int>> edgeList(edges,vector<int>(3));

    cout << "Enter the edges (source , dest , weight) : \n";
    for(auto &edge : edgeList){
        cin >> edge[0] >> edge[1] >> edge[2];
    }

    vector<int> result = BF(edgeList,vertices,source);

    if(!result.empty()){
        cout << "Shortest paths from vertex " << source << ":\n";
        for(int i = 0 ; i < vertices ; i++){
            if(result[i] == numeric_limits<int>::max()){
                cout << "Vertex " << i << " : "<< "INF\n";
            }else{
                cout << "Vertex " << i << " : "<< result[i] << "\n";
            }
        }
    }return 0;
}