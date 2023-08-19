/*****************************************************************/
/*   Grafo c/ lista de adjacencias | ESDA | LEEC | 2022/23      */      
/*****************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "graph.hpp"

Graph::Graph(int v)
{
    if (v > 0) {
        this->v = v; // atribui o número de vértices
        this->adj.resize(v);
    }
}

int Graph::addEdgeUndirected(int v1, int v2)
{
 
    if ((v1 >= 0 && v1 < v) && (v2 >= 0 && v2 < v)) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        return 0;
    } 
    return -1;
}

int Graph::identifies_substation()
{
    /*responder aqui*/
    int k = -1;
    int min = 100;
    for(int i = 0; i < (int) adj.size(); i++){
        if((int) adj[i].size()<min){
            min=adj[i].size();
            k=i;
        }
    }

    return k;
}
int Graph::substation_complete()
{
    /*responder aqui*/
    int k = -1;
    int max = 0;
    for(int i=0; i< (int) adj.size(); i++){
        if((int) adj[i].size()>max){
            max=adj[i].size();
            k=i;
        }
    }
    return k;
}

void Graph::print()
{
    for(int i=0; i < this->v; i++){
        cout << i << " -> ";
        for(auto it : this->adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}

