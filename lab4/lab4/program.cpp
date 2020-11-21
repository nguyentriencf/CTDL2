#include<iostream>
#include<fstream>
using namespace std;
#include"common.h"
#include"Graph.h"

int main()
{
	Graph g;
	openGraph(g);
	cout << "So dinh do thi: " << g.NumVertices;
	cout << "\nSo canh do thi: " << g.NumEdges;
	if (g.Directed)
		cout << "\nDo thi co huong";
	else
		cout << "\nDo thi vo huong";
	Resetflags(g);
	DFS_Recursion(g, 4);
	return 0;
}