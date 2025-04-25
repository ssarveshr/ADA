#include<stdio.h>
#include<stdlib.h>

#define MAX_EDGE 1000

typedef struct edge
{
    int src,dest,weight;
}edge;

typedef struct graph
{
    int V,E;
    edge edges[MAX_EDGE];
}graph;

typedef struct subset
{
    int parent;
    int rank;
}subset;

graph *createGraph(int V,int E)
{
    graph* g=(graph*)malloc(sizeof(graph));
    g->E=E;
    g->V=V;
    return g;
}

int find(subset sub[],int i)
{
    if(sub[i].parent!=i)
    {
        sub[i].parent=find(sub,sub[i].parent);
    }
    return sub[i].parent;
}

int compare(const void* a,const void* b)
{
    edge* a_val=(edge*)a;
    edge* b_val=(edge*)b;
    return a_val->weight-b_val->weight;
}
void Union(subset sub[],int x,int y)
{
    x=find(sub,x);
    y=find(sub,y);
    if(sub[x].rank<sub[y].rank)
    {
        sub[x].parent=y;
    }
    else if(sub[x].rank>sub[y].rank)
    {
        sub[y].parent=x;
    }
    else
    {
        sub[y].parent=x;
        sub[x].rank++;
    }
}

void kruskalMST(graph*g)
{
    edge mst[g->E];
    int e=0,i=0;

    qsort(g->edges,g->E,sizeof(edge),compare);

    subset* sub=(subset*)malloc(g->V*sizeof(subset));

    for(int v=0;v<g->V;++v)
    {
        sub[v].parent=v;
        sub[v].rank=0;
    }

    while(e<g->V -1 && i<g->E)
    {
        edge next=g->edges[i++];
        int x=find(sub,next.src);
        int y=find(sub,next.dest);

        if(x!=y)
        {
            mst[e++]=next;
            Union(sub,x,y);
        }

    }

    printf("min span tre\n");
    for(int i=0;i<e;i++)
    {
        printf("(%d , %d) -> %d\n",mst[i].src,mst[i].dest,mst[i].weight);
    }
}

int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    graph* g = createGraph(V, E);

    printf("Enter edges and their weights:\n");
    for (int i = 0; i < E; ++i) 
    {
        scanf("%d %d %d", &g->edges[i].src, &g->edges[i].dest, &g->edges[i].weight);
    }

    kruskalMST(g);
    return 0;
}