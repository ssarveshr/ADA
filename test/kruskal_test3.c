#include<stdio.h>
#include<stdlib.h>
#define V_MAX 100

typedef struct edge
{
    int src,dest,weight;
}edge;

typedef struct graph
{
    int E,V;
    edge edges[V_MAX];
}graph;

typedef struct subset
{
    int parent,rank;
}subset;

graph* createGraph(int v,int e)
{
    graph* g=(graph*)malloc(sizeof(graph));
    g->E=e;
    g->V=v;
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

int compare(const void*a,const void *b)
{
    edge* a_val=(edge*)a;
    edge* b_val=(edge*)b;
    return a_val->weight-b_val->weight;
}


void kruskalMst(graph* g)
{
    edge mst[g->V];
    int e=0,i=0;

    qsort(g->edges,g->E,sizeof(edge),compare);

    subset *sub=(subset*)malloc(g->V*sizeof(subset));

    for(int v=0;v<g->V;v++)
    {
        sub[v].parent=v;
        sub[v].rank=0;
    }

    while(e<g->V-1&& i<g->E)
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
    printf("min st \n");
    for(int i=0;i<e;i++)
    {
        printf("(%d,%d) -> %d\n",mst[i].src,mst[i].dest,mst[i].weight);
    }
}

int main()
{
    int e,v;
    printf("enter numb of edge and weights : ");
    scanf("%d %d",&e,&v);
    graph *g=createGraph(v,e);
    printf("Enter edges and their weights:\n");
    for (int i = 0; i < e; ++i) 
    {
        scanf("%d %d %d", &g->edges[i].src, &g->edges[i].dest, &g->edges[i].weight);
    }

    kruskalMst(g);
    return 0;
}