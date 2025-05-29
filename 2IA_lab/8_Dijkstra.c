#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 10
#define INF INT_MAX

int minDistance(int dist[], bool visited[], int V)
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V)
{
    printf("Vertex \t\t Distance from Source\n");

    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V)
{
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);

        visited[u] = true;
        
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int graph[MAX_VERTICES][MAX_VERTICES] = {{0}};

    printf("Enter the source vertex, destination vertex, and weight for each edge:\n");

    for (int i = 0; i < E; i++)
    {
        int source, dest, weight;
        scanf("%d %d %d", &source, &dest, &weight);
        graph[source][dest] = weight;
        graph[dest][source] = weight;
    }

    dijkstra(graph, 0, V);
    return 0;
}
