#include<stdio.h>
#include<string.h>
#define max 10000
char mang[5758][6];
static int A[max][max];
static int B[max][max];
static int tapdinh[max];
static int pre[max];
static int prelienthong[max];
static int post[max];
static int postlienthong[max];
static int ccnum[max];
int cc=0;
static int visited[max];
static int visitedlienthong[max];
int sodinh=5757,socanh;
int clock=1,clocklienthong=1;
void nhapmatran()
{ 
      for(int i=1;i<5758;i++)       
      {
          gets(mang[i]);
      }
      for(int j=1;j<5757;j++)
      for(int k=1;k<5758;k++)
      {    int dem=0,dem1=0;
          for(int l=1;l<5;l++)
          {
          for(int m=0;m<5;m++)
          {   
              if(mang[j][l]==mang[k][m]) dem++;
          } if(dem!=0) dem1++; dem=0;
          }
          if(dem1>=4) 
          {A[j][k]=1;B[k][j]=1;socanh++;};
          dem1=0;
      }
}
void previsit(int v)
{
    
    pre[v]=clock;
    clock+=1;
}
void previsitlienthong(int v)
{
    
    prelienthong[v]=clocklienthong;
    clocklienthong+=1;
}
void postvisit(int v)
{
    post[v]=clock;
    clock+=1;
}
void postvisitlienthong(int v)
{   ccnum[v]=cc; 
    postlienthong[v]=clocklienthong;
    clocklienthong+=1;
}
void explore(int v)
{
    visited[v]=1;
    previsit(v);
    for(int u=1;u<=sodinh;u++)
    
    if(B[v][u]==1)
    
        if(visited[u]==0)
        
            explore(u);
postvisit(v);
}
void explorelienthong(int v)
{
    visitedlienthong[v]=1;
    previsitlienthong(v);
    for(int u=1;u<=sodinh;u++)
    
    if(A[v][u]==1)
    
        if(visitedlienthong[u]==0)
        
            explorelienthong(u);
postvisitlienthong(v);
}
void DFS()
{
    for(int v=1;v<=sodinh;v++)
    {
        if(visited[v]==0)
        {
            explore(v);
        }
    }
}
void DFSLIENTHONG()
{   int v;
    for(int z=1;z<=sodinh;z++)
    {   
       v=tapdinh[z];
        if(visitedlienthong[v]==0)
        {   cc=cc+1;
            explorelienthong(v);
        }
    }
}
void sapxep()
{
   
   int sapxep=0;
   int sapdat=0;
   for(int i=1;i<=sodinh;i++)
   {
       tapdinh[i]=i;
   }
   for(int i=1;i<sodinh;i++)
       for(int j=i+1;j<sodinh-1;j++)
           if(post[i]<post[j])
           {   sapdat=post[i];
               post[i]=post[j];
               post[j]=sapdat;
               sapxep=tapdinh[i];
               tapdinh[i]=tapdinh[j];
               tapdinh[j]=sapxep;
           }
}
int main()
{
      
    nhapmatran();
    DFS();
    sapxep();
    DFSLIENTHONG();
    char u[6]; int a;
    gets(u);
    for (int i = 1; i <= 5757; i++)
    {
        if(strcmp(u,mang[i])==0) a=i;
    }
    for (int j = 1; j <=5757; j++)
    {
        if(ccnum[j]==ccnum[a]) printf("%s ",mang[j]);    } 

return 0;
}

