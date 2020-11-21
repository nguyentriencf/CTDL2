#pragma once
// định nghĩa hằng số
#define UPPER		100			// số phần tử tối đa
#define ZERO		0			// gIÁ TRỊ 0
#define MAX			20			// số đỉnh tối đa
#define INF			1000		// vô cùng
#define YES			1			// đã xét
#define NO			0			// chưa xét
#define NULLDATA	-1		// giá trị rỗng

// dùng cho kiểu dữ liệu đò thi

// dùng định nghĩa các kiểu dữ liệu
typedef char		LabelType;
typedef	int			CostType;
typedef CostType	MaTrix[MAX][MAX];  // ma trận


struct Vertex
{
	LabelType Label; // Nhãn của đinh
	int Visited; // trạng thái
};

// định nghĩa cạnh
struct Edge
{
	int		Source; ///đỉnh đầu
	int		target; // đỉnh cuối
	CostType	Weight; // trọng số
	int			Marked; // trạng thái
};

// định nghĩa cấu trúc đường đi
struct Path
{
	CostType		Length; //Độ dài đường đi
	int				Parent;	// đỉnh trước
};

struct Graph
{
	bool Directed;		// đt có hướng?
	int NumVertices;	// số đỉnh
	int NumEdges;		// số cạnh
	MaTrix	Cost;		//Ma trận kề
	Vertex	Vertices[MAX];	//DS đỉnh
};



