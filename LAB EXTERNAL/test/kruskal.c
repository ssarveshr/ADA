#include<stdio.h>
#include<stdlib.h>

#define MAX_EDGES 1000

typedef struct edge
{
    int src,dest,weight;
}Edge;

typedef struct grh
{
    int E,V;
    Edge edges[MAX_EDGES];
}Graph;

typedef struct subset
{
    int parent,rank;
}Subset;

Graph* createGraph(int V,int E)
{
    Graph*g=(Graph*)malloc(sizeof(Graph));
    g->E=E;
    g->V=V;
    return g;
}

int find(Subset subsets[],int i)
{
    if(subsets[i].parent!=i)
        subsets[i].parent=find(subsets,subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[],int x,int y)
{
    int xroot=find(subsets,x);
    int yroot=find(subsets,y);

    if(subsets[xroot].rank<subsets[yroot].rank)
        subsets[xroot].parent=yroot;
    else if(subsets[xroot].rank>subsets[yroot].rank)
        subsets[yroot].parent=xroot;
    else
    {
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a,const void*b)
{
    Edge* a_edge=(Edge*)a;
    Edge* b_edge=(Edge*)b;
    return a_edge->weight-b_edge->weight;
}


void kruskalMST(Graph* g)
{
    Edge mst[g->V];
    int e=0,i=0;

    qsort(g->edges,g->E,sizeof(Edge),compare);
    Subset*subsets=(Subset*)malloc(g->V*sizeof(Subset));

    for(int v=0;v<g->V;v++)
    {
        subsets[v].parent=v;
        subsets[v].rank=0;
    }

    while(e<g->V-1 && i<g->E)
    {
        Edge next_edge=g->edges[i++];
        int x=find(subsets,next_edge.src);
        int y=find(subsets,next_edge.dest);

        if(x!=y)
        {
            mst[e++]=next_edge;
            Union(subsets,x,y);
        }
    }

    printf("MST\n");
    for(int i=0;i<e;i++)
    {
        printf("(%d , %d)--> %d\n",mst[i].src,mst[i].dest,mst[i].weight);
    }
}


int main()
{
    printf("enter no of edges and vertice of graph : ");
    int E,V;
    scanf("%d%d",&E,&V);
    Graph*g=createGraph(V,E);
    printf("enter edges and thier weights\n");
    for(int i=0;i<E;i++)
    {
        scanf("%d%d%d",&g->edges[i].src,&g->edges[i].dest,&g->edges[i].weight);
    }

    kruskalMST(g);
}