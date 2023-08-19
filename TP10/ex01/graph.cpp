/*****************************************************************/
/*   Grafo c/ listas de adjacencias | ESDA | LEEC | 2022/23      */      
/*****************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"

Graph::Graph(int v)
{
    if (v > 0) {
        this->v = v; // atribui o número de vértices
        this->adj.resize(v);
    }
}

int Graph::addEdgeDirected(int v1, int v2)
{
    /* Alinea 1.a */
    if(v1 < 0 || v1 >= v || v2 < 0 || v2 >= v) {
        return -1;
    }
    adj[v1].push_back(v2);
    return 0;
}

int Graph::removeEdge(int v1, int v2)
{
    /* Alinea 1.a */
    if (v1 < 0 || v1 >= v || v2 < 0 || v2 >= v) {
        return -1;
    }

    bool edgeRemoved = false;
    for (auto it = adj[v1].begin(); it != adj[v1].end(); ) {
        if (*it == v2) {
            it = adj[v1].erase(it);
            edgeRemoved = true;
        } else {
            it++;
        }
    }

    if (!edgeRemoved) {
        return 0;
    }

    for (auto it = adj[v2].begin(); it != adj[v2].end(); ) {
        if (*it == v1) {
            it = adj[v2].erase(it);
        } else {
            ++it;
        }
    }

    return 1;
}

bool Graph::existsNeighbor(int v1, int v2)
{
    /* Alinea 1.a */
    if (v1 < 0 || v1 >= v || v2 < 0 || v2 >= v) {
        return -1;
    }
	bool edgeRemoved = false;
    for (auto it = adj[v1].begin(); it != adj[v1].end(); ) {
        if (*it == v2) {
            edgeRemoved = true;
            break;
        } else {
            it++;
        }
    }
    return edgeRemoved;
}


int Graph::outDegree(int v)
{
    /* Alinea 1.b */
    return adj[v].size();
}

vector<list<int>> Graph::transposeGraph()
{
    /* Alinea 1.c */
    
    return {};
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

void Graph::print(vector<list<int>> vet)
{
    for(int i=0; i < (int)vet.size(); i++){
        cout << i << " -> ";
        for(auto it : vet[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}


