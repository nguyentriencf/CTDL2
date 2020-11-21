
Vertex CreateVertex(LabelType lab)
{
	Vertex v;
	v.Label = lab;
	v.Visited = NO;
	return v;
}


void DisplayVertex(Graph g, int pos)
{
	cout << g.Vertices[pos].Label << "\t";
}


Graph InitGraph(bool directed)
{
	Graph graph;

	graph.NumEdges = 0;
	graph.NumVertices = 0;
	graph.Directed = directed;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (i == j)
				graph.Cost[i][j] = 0;
			else
				graph.Cost[i][j] = INF;

	return graph;
}


void ResetFlags(Graph& g)
{
	for (int i = 0; i < MAX; i++)
		g.Vertices[i].Visited = NO;
}


bool IsConnected(Graph g, int start, int end)
{
	return (g.Cost[start][end] == 0 || g.Cost[start][end] == INF);
}


void AddVertex(Graph& g, LabelType lab)
{
	Vertex v = CreateVertex(lab);
	g.Vertices[g.NumVertices] = v;
	g.NumVertices += 1;
}

// Doc du lieu
void OpenGraph(Graph& g)
{
	ifstream input("DoThi1.txt");

	if (!input)
	{
		cout << "\nLoi doc file nhap lai ten file\n";
		system("pause");
		exit(-1);
	}

	int numVertices = 0;
	int numEdges = 0;
	bool directed = false;
	LabelType label;

	input >> numVertices;
	input >> numEdges;
	input >> directed;

	g = InitGraph(directed);
	g.NumEdges = numEdges;

	// Khởi tạo nhãn của các đỉnh
	for (int i = 0; i < numVertices; i++)
	{
		input >> label;
		AddVertex(g, label);
	}

	for (int i = 0; i < numVertices; i++)
		for (int j = 0; j < numVertices; j++)
			input >> g.Cost[i][j];

	input.close();
}
