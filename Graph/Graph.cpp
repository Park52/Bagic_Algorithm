#include "Graph.h"

Graph* CreateGraph()
{
	Graph* NewGraph = (Graph*)malloc(sizeof(Graph));
	NewGraph->VertexCount = 0;
	NewGraph->Vertices = NULL;

	return NewGraph;
}

void DestroyGraph(Graph* G)
{
	while (G->Vertices != NULL)
	{
		Vertex* Vertices = G->Vertices->Next;
		DestroyVertex(G->Vertices);
		G->Vertices = Vertices;
	}

	free(G);
}

Vertex* CreateVertex(int Data)
{
	Vertex* NewVertex = (Vertex*)malloc(sizeof(Vertex));

	NewVertex->Data = Data;
	NewVertex->Next = NULL;
	NewVertex->Visited = NotVisited;
	NewVertex->AdjacencyList = NULL;
	NewVertex->Index = -1;

	return NewVertex;
}

void DestroyVertex(Vertex* V)
{
	while (V->AdjacencyList != NULL)
	{
		Edge* Edge = V->AdjacencyList->Next;

		DestroyEdge(V->AdjacencyList);

		V->AdjacencyList = Edge;
	}

	free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
	Edge* NewEdge = (Edge*)malloc(sizeof(Edge));

	NewEdge->From = From;
	NewEdge->Target = Target;
	NewEdge->Weight = Weight;
	NewEdge->Next = NULL;

	return NewEdge;
}

void DestroyEdge(Edge* E)
{
	free(E);
}

void AddVertex(Graph* G, Vertex* V)
{
	Vertex* VertexList = G->Vertices;
	
	if (VertexList == NULL)
	{
		G->Vertices = V;
	}
	else
	{
		while (VertexList->Next != NULL)
		{
			VertexList = VertexList->Next;
		}

		VertexList->Next = V;
	}

	V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E)
{
	if (V->AdjacencyList == NULL)
	{
		V->AdjacencyList = E;
	}
	else
	{
		Edge* AdjacencyList = V->AdjacencyList;

		while (AdjacencyList->Next != NULL)
		{
			AdjacencyList = AdjacencyList->Next;
		}

		AdjacencyList->Next = E;
	}
}

void PrintGraph(Graph* G)
{
	Vertex* V = NULL;
	Edge* E = NULL;

	if ((V = G->Vertices) == NULL)
	{
		return;
	}
	while (V != NULL)
	{
		printf("%c : ", V->Data);

		if ((E = V->AdjacencyList) == NULL)
		{
			V = V->Next;
			printf("\n");
			continue;
		}

		while (E != NULL)
		{
			printf("%c[%d] ", E->Target->Data, E->Weight);
			E = E->Next;
		}

		printf("\n");

		V = V->Next;
	}

	printf("\n");
}
