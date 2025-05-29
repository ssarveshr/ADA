#include <math.h>
#include <stdio.h>

int max(int, int);
void warshal(int dis[10][10], int n)
{
  int i, j, k;
  for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        dis[i][j] = max(dis[i][j], dis[i][k] && dis[k][j]);
}
int max(int a, int b)
{
  if (a > b)
    return (a);
  else
    return (b);
}
int main()
{
  int dis[10][10] = {0}, n, e, u, v, i, j;
  printf("\n Enter the number of vertices:");
  scanf("%d", &n);
  printf("\n Enter the number of edges:");
  scanf("%d", &e);
  for (i = 1; i <= e; i++)
  {
    printf("\n Enter the end vertices of edge %d:", i);
    scanf("%d%d", &u, &v);
    dis[u][v] = 1;
  }
  printf("\n Matrix of input data: \n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d\t", dis[i][j]);
    printf("\n");
  }
  warshal(dis, n);
  printf("\n Transitive closure: \n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d\t", dis[i][j]);
    printf("\n");
  }
}
