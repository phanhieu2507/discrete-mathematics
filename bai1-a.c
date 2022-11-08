#include<stdio.h>
char mang[5757][6];
static int matran[5757][5757];
int socanh=0;
static int visited[5757];
int cc=0;
static int ccnum[5757];
void nhapmatran()
{ 
      for(int i=0;i<5757;i++)       
      {
          gets(mang[i]);
      }
      for(int j=0;j<5757;j++)
      for(int k=j+1;k<5756;k++)
      {    int dem=0;
          for(int l=0;l<5;l++)
          {   
              if(mang[j][l]==mang[k][l]) dem++;
          }
          if(dem==4) 
          {matran[j][k]=1;matran[k][j]=1;socanh++;};
          dem=0;
      }
}
void previsit(int v)
{
    ccnum[v]=cc;
}
void explore(int v)
{
    visited[v]=1; // 1: true, 0:false
    previsit(v);

    for(int u=0; u < 5757; u++)
        if (matran[v][u] == 1)
            if (visited[u]==0) explore(u);
    
}
void dfs ()
{
  
    for (int v=0; v<5757; v++)
        if (visited[v]==0) 
        {cc++; explore(v);}
}

void main()
{
    nhapmatran();
    dfs();
    printf("So thanh phan lien thong cua do thi la %d",cc);
    
}