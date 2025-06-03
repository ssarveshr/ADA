#include<stdio.h>
#include<limits.h>
#define V_MAX 100

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

void printMST(int parent[],int graph[][V_MAX],int V)
{
    printf("MST\nEdge    Weight\n");
    for(int i=1;i<V;i++)
    {
        printf("%d - %d     %d\n",parent[i],i,graph[i][parent[i]]);
    }
}


void primMST(int graph[][V_MAX],int V)
{
    int parent[V_MAX];
    int mstSet[V_MAX];
    int key[V_MAX];
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=0;
    }
    key[0]=0;
    mstSet[0]=-1;

    for(int count =0;count<V-1;count++)
    {
        int u=minKey(key,mstSet,V);
        mstSet[u]=1;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v]!=0 && mstSet[v]==0 && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printMST(parent,graph,V);
}

int main()
{
    int E,V;
    printf("enter no of edges and vertices : ");
    scanf("%d%d",&E,&V);
    int graph[V_MAX][V_MAX];
    printf("enter src dest and weight");
    int src,dest,weight;
    for(int i=0;i<E;i++)
    {
        scanf("%d%d%d",&src,&dest,&weight);
        graph[src][dest]=weight;
        graph[dest][src]=weight;
    }
    primMST(graph,V);
}