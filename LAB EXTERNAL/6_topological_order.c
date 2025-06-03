#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct
{
    int V;
    int **adjMatrix;
} Graph;

Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int **)calloc(V, sizeof(int *));
    for (int i = 0; i < V; i++)
        graph->adjMatrix[i] = (int *)calloc(V, sizeof(int));
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
}

void topologicalSort(Graph *graph)
{
    int V = graph->V, inDegree[MAX_VERTICES] = {0}, queue[MAX_VERTICES], front = 0;
    int rear = -1;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph->adjMatrix[i][j] == 1)
                inDegree[j]++;

    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0)
            queue[++rear] = i;

    
    printf("Topological ordering of vertices: ");
    while (front <= rear)
    {
        int vertex = queue[front++];
        printf("%d ", vertex);
        for (int i = 0; i < V; i++)
            if (graph->adjMatrix[vertex][i] == 1 && --inDegree[i] == 0)
                queue[++rear] = i;
    }
    printf("\n");
}
// Driver code
int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    Graph *graph = createGraph(V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges (source vertex, destination vertex):\n");
    for (int i = 0, src, dest; i < E; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    topologicalSort(graph);
    return 0;
}