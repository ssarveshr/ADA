#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 100

int minKey(int key[],int mstSet[],int V)
{
    int min=INT_MAX,min_index;

    for(int v=0;v<V;v++)
    {
        if(mstSet[v]==0 && key[v]<min)
        {
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}

void printMst(int parent[],int graph[][INT_MAX],int V)
{
    printf("edge   weight\n");
    for(int i=1;i<V;i++)
    {
        printf("%d - %d   %d\n",parent[i],i,graph[i][parent[i]]);
    }
}

void primMst(int graph[][INT_MAX],int V)
{
    int parent[INT_MAX];
    int mstSet[INT_MAX];
    int key[INT_MAX];

    for(int i=0;i<V;i++)
    {
        mstSet[i]=0;
        key[i]=INT_MAX;
    }
    parent[0]=-1;
    key[0]=0;

    for(int cnt=0;cnt< V-1;cnt++)
    {
        int u=minKey(key,mstSet,V);
        mstSet[u]=1;

        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && mstSet[v]==0 && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printMst(parent,graph,V);
}

int main()
{
    int E,V;
    printf("enter number of edges and vertices : ");
    scanf("%d %d",&V,&E);
    int graph[INT_MAX][INT_MAX]={0};
    printf("enter source edge and weight : \n");
    int src,dest,weight;
    for(int i=0;i<E;i++)
    {
        scanf("%d %d %d",&src,&dest,&weight);
        graph[src][dest]=weight;
        graph[dest][src]=weight;
    }
    primMst(graph,V);
    
}