
#include <stdio.h>
int min(int, int);
void floyds(int dis[10][10], int n)
{
  int i, j, k;
  for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (i == j)
          dis[i][j] = 0;
        else
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);


}
int min(int a, int b)
{
  if (a < b)
    return (a);
  else
    return (b);
}
void main()
{
  int dis[10][10], w, n, e, u, v, i, j;
  printf("\n Enter the number of vertices:");
  scanf("%d", &n);
  printf("\n Enter the number of edges:\n");
  scanf("%d", &e);
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      dis[i][j] = 999;
  }


  for (i = 1; i <= e; i++)
  {
    printf("\n Enter the end vertices of edge%d with its weight \n", i);
    scanf("%d%d%d", &u, &v, &w);
    dis[u][v] = w;
  }


  printf("\n Matrix of input data:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d \t", dis[i][j]);
    printf("\n");
  }


  floyds(dis, n);


  printf("\n Transitive closure:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d \t", dis[i][j]);
    printf("\n");
  }


  printf("\n The shortest paths are:\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    {
      if (i != j)
        printf("\n <%d,%d>=%d", i, j, dis[i][j]);
    }
}
