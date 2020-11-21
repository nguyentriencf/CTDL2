#pragma once
#define UPPER		100	
#define ZERO		0		
#define MAX			20		
#define INF			1000	
#define YES			1		
#define NO			0		
#define NULLDATA	-1		


typedef char LabelType;
typedef int CostType;
typedef CostType MaTrix[MAX][MAX];


struct Vertex
{
	LabelType Label;
	int Visited;
};


struct Edge
{
	int Source;
	int Target;
	CostType Weight;
	int Marked;
};


struct Path
{
	CostType Length;
	int Parent;
};


struct Graph
{
	bool Directed;
	int NumVertices;
	int NumEdges;
	MaTrix Cost;
	Vertex Vertices[MAX]; //ds đỉnh
};
