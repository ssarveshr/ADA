#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void warshal(int dis[10][10],int n_vertice)
{
    int i,j,k;
    for(i=1;i<=n_vertice;i++)
        for(j=1;j<=n_vertice;j++)
            for(k=1;k<=n_vertice;k++)
                dis[j][k]=max(dis[j][k],dis[j][i] && dis[i][k]);
}

int main()
{
    int dis[10][10]={0};
    printf("enter no of edges : ");
    int no_edge;
    scanf("%d",&no_edge);
    printf("enter no of vertice : ");
    int no_vertice;
    scanf("%d",&no_vertice);
    
    printf("enter src dest of edges \n");
    int src,dest;
    for(int i=1;i<=no_edge;i++)
    {
        printf("edge %d : ",i);
        scanf("%d%d",&src,&dest);
        dis[src][dest]=1;
    }

    printf("adjacency matrix \n");
    for(int i=1;i<=no_vertice;i++)
    {
        for(int j=1;j<=no_vertice;j++)
        {
            printf("%d\t",dis[i][j]);
        }
        printf("\n");
    }

    warshal(dis,no_vertice);

    printf("transitive closure \n");
    for(int i=1;i<=no_vertice;i++)
    {
        for(int j=1;j<=no_vertice;j++)
        {
            printf("%d\t",dis[i][j]);
        }
        printf("\n");
    }
    
}