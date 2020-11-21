#include<iostream>
#include<fstream>
using namespace std;
#include"common.h"
#include"Graph.h"

int main()
{
	Graph g;
	OpenGraph(g);
	cout << "So dinh do thi:" << g.NumVertices;
	cout << "\nSo canh:" << g.NumEdges;
	if (g.Directed)
		cout << "\nDo thi co huong";
	else
		cout << "\nDo thi vo huong";
	return 0;
}