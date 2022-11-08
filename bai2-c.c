#include<stdio.h>
#include<string.h>
char mang[5757][6];
static int matran[5757][5757];
int socanh=0;
static int visited[5757];
int cc=0;
static int ccnum[5757];
static char a[6];
static char b[6];
static int x,y;
static int truoc[10000];
static int check[10000];
static int hangdoi[10000];
static int dem1,dem2,dem3;
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
          {matran[j][k]=1;socanh++;};
          dem1=0;
      }
}
void previsit(int v)
{
    ccnum[v]=cc;
}
void explore(int v)
{
    visited[v]=1; 
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
void nhaptukhoa()
{    gets(a);
     gets(b);
     for(int i=0;i<5757;i++)
     {   
         if(strcmp(mang[i],a)==0) 
         {
             x=i;
         }
         else if(strcmp(mang[i],b)==0) y=i;
         
     }
     for(int j=0;j<5757;j++)
     {
         if(ccnum[j]==ccnum[x])
            dem1++;                         //dem1=sodinhtrongthanhphanlienthong
     }   
}
void eject(int u)
{
    hangdoi[dem2]=u;
    dem2++;check[u]=1;
}
void inject()
{ for(int v=0;v<5757;v++)
   {
       if(matran[hangdoi[dem3]][v]==1&&check[v]==0)
       {
           eject(v);
           truoc[v]=hangdoi[dem3];
       }
       
   } dem3++;
}
void timduong()
{        
       if(ccnum[x]!=ccnum[y]) printf("Khong ton tai duong giua 2 diem"); 
       else
       truoc[x]=-1;
       eject(x);
       while (dem3!=dem1)
       {
           inject();
       }
           
        while(y!=x)
        {
            printf("%s <--",mang[y]);
            y=truoc[y];
            
        }
        printf("%s",mang[x]);       
      
}
void main()
{
    nhapmatran();
    dfs();
    nhaptukhoa();
    timduong();
}