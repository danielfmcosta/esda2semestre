#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DirectedGraph {
private:
    int n;
    vector<vector<int>> adj;
public:
    DirectedGraph(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        //alínea a)
        adj[u].push_back(v);
    }

    bool hasPath(int u, int v) 
    {
        //alínea b)
        for(auto i : adj[u]) {
            if(i==v){
                return true;
            }
        }
        return false;
    }

    vector<int> topologicalSort(){

        //alínea c)

        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }


        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);  
            }
        }

        vector<int> sortedOrder;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sortedOrder.push_back(node);

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return sortedOrder;
    }
};

int main() {
    int n = 5;
    DirectedGraph graph1(n);
    graph1.addEdge(0, 1);
    graph1.addEdge(1, 3);
    graph1.addEdge(2, 3);
    graph1.addEdge(3, 4);

    if (graph1.hasPath(1, 3)) {
        cout << "There is a path from 1 to 3 in graph 1\n";
    } else {
        cout << "There is no path from 1 to 3 in graph 1\n";
    }

    vector<int> ordering = graph1.topologicalSort();
    if (ordering.empty()) {
        cout << "Graph 1 contains a cycle\n";
    } else {
        cout << "The topological ordering of graph 1 is: ";
        for (int v : ordering) {
            cout << v << " ";
        }
        cout << endl;
    }


    DirectedGraph graph2(n);
    graph2.addEdge(0, 1);
    graph2.addEdge(0, 3);
    graph2.addEdge(1, 4);
    graph2.addEdge(3, 1);
    graph2.addEdge(3, 2);
    graph2.addEdge(3, 4);


    if (graph2.hasPath(1, 3)) {
        cout << "There is a path from 1 to 3 in graph 2\n";
    } else {
        cout << "There is no path from 1 to 3 in graph 2\n";
    }
    
    ordering = graph2.topologicalSort();
    if (ordering.empty()) {
        cout << "Graph 2 contains a cycle\n";
    } else {
        cout << "The topological ordering of graph 2 is: ";
        for (int v : ordering) {
            cout << v << " ";
        }
        cout << endl;
    }

    DirectedGraph graph3(n);
    graph3.addEdge(0, 1);
    graph3.addEdge(0, 3);
    graph3.addEdge(1, 4);
    graph3.addEdge(3, 1);
    graph3.addEdge(3, 2);
    graph3.addEdge(3, 4);
    graph3.addEdge(2, 0);

    ordering = graph3.topologicalSort();
    if (ordering.empty()) {
        cout << "Graph 3 contains a cycle\n";
    } else {
        cout << "The topological ordering of graph 3 is: ";
        for (int v : ordering) {
            cout << v << " ";
        }
        cout << endl;
    }


    return 0;
}
