#pragma once
// tạo một đỉnh có nhã lab
Vertex CreateVertex(LabelType lab)
{
	Vertex v;
	v.Label = lab;
	v.Visited = NO;
	return v;
}

// hiển thị thông tin
void DisplayVertex(Graph g, int pos)
{
	cout << g.Vertices[pos].Label << "\t";
}

 //khởi tạo một đồ thị
 //directed = true: đồ thị có hương
Graph InitGraph(bool directed)
{
	Graph g;
	g.NumEdges = 0;
	g.NumVertices = 0;
	g.Directed = directed; // có hương hay không

	// khởi tạo ma trân kề
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (i == j)
				g.Cost[i][j] = 0;
			else
				g.Cost[i][j] = INF;
	return g;	
}

// thiết lập trạng thái của các đỉnh
void Resetflags(Graph& g)
{
	for (int i = 0; i < MAX; i++)
		g.Vertices[i].Visited = NO;
}
 //kiểm tra strart và end có được kết nối với nhau bởi 1 cạnh không
bool IsConnected(Graph g, int start, int end)
{
	return(g.Cost[start][end] != 0 && g.Cost[start][end] != INF);
}


// thêm một đỉnh
void AddVertex(Graph& g, LabelType lab)
{
	Vertex v = CreateVertex(lab);
	g.Vertices[g.NumVertices] = v;
	g.NumVertices += 1;
}


// đọc đò thị
void openGraph(Graph& g)
{
	ifstream input("dothi.txt");

	if (!input)
	{
		cout << "\nLoi doc file nhap lai file\n";
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


	// khởi tạo nhãn của các đỉnh
	for(int i = 0; i < numVertices; i++)
	{
		input >> label;
		AddVertex(g, label);
	}
	// đọc ma trận kề từ file
	for (int i = 0; i < numVertices; i++)
		for (int j = 0; j < numVertices; j++)
			input >> g.Cost[i][j];
	input.close();
}

int TimKiemDT(Graph g, int v)
{
	for (int i =0; i < g.NumVertices; i++)
	{
		if (g.Vertices[i].Visited == NO && (g.Cost[v][i] != 0 && g.Cost[v][i] != INF))
		{
			return i;
		}
	}
	return NULLDATA;
}

void DFS_Recursion(Graph& g, int start)
{
	g.Vertices[start].Visited = YES;
	DisplayVertex(g, start);
	while (true)
	{
		int v = TimKiemDT(g, start);
		if (v == NULLDATA)
		{
			break;
			DFS_Recursion(g, v);
		}
	}
}

// & với Graph g

// input >>