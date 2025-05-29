#include<stdio.h>
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
void floyds(int dis[10][10],int n_vertices)
{
    int i,j,k;
    for(i=1;i<=n_vertices;i++)
        for(j=1;j<=n_vertices;j++)
            for(k=1;k<=n_vertices;k++)
            {
                if(j==k)
                    dis[j][k]=0;
                else
                    dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
}
int main()
{
    int dis[10][10];
    printf("enter number of edges : ");
    int no_edges;
    scanf("%d",&no_edges);

    printf("enter number of vertice : ");
    int no_vertice;
    scanf("%d",&no_vertice);

    for(int i=1;i<=no_vertice;i++)
    {
        for(int j=1;j<=no_vertice;j++)
            dis[i][j]=999;
    }
    printf("enter source destination weight \n");
    int src,dest,weig;
    for(int i=1;i<=no_edges;i++)
    {
        printf("edge %d : ",i+1);
        scanf("%d%d%d",&src,&dest,&weig);
        dis[src][dest]=weig;
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

    floyds(dis,no_vertice);

    printf("Transitive closure  \n");
    for(int i=1;i<=no_vertice;i++)
    {
        for(int j=1;j<=no_vertice;j++)
        {
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }

    printf("all pair shoeted path  \n");
    for(int i=1;i<=no_vertice;i++)
    {
        for(int j=1;j<=no_vertice;j++)
        {
            if(i!=j)
                printf("\n <%d,%d>-%d ",i,j,dis[i][j]);
        }
    }
}