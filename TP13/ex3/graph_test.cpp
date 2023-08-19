#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "graph.hpp"
#include "graph.cpp"

using namespace std;

int main()
{
	int n = 9;
	Graph u_graph(n);

	// Testa a criação das listas de adjacências
	int cont = 0;
	if (u_graph.addEdgeUndirected(0, 4) == 0) cont ++;
	if (u_graph.addEdgeUndirected(0, 2) == 0) cont ++;
	if (u_graph.addEdgeUndirected(0, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(1, 5) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 1) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 3) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 4) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 5) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 6) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 8) == 0) cont ++;
	if (u_graph.addEdgeUndirected(5, 6) == 0) cont ++;
	if (u_graph.addEdgeUndirected(5, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(6, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(6, 8) == 0) cont ++;
	cout << "Grafo criado com " << n << " nos e " << cont << " arestas." << endl;
	u_graph.print();

	int i = u_graph.identifies_substation();
	cout << "Subestacao unica: " << i << endl;

	int j = u_graph.substation_complete();
	cout << "Subestacao comleta: " << j << endl;
	return 0;
}