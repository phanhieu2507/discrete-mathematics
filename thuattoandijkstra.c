#include<stdio.h>
int sodinh,socanh;
#define max 1000
#define oo 1000
static int dist[max];
static int disttest[max];
static int matran[max][max];
static int hangdoi[max];
static int hangdoithu[max];
static int khoangcach[max][max];
static int truoc[max];
int dem=0,xoa=0;
void insert(int u) //them u vao tap
{ 
  hangdoi[dem]=u;
  dem++;     
}
void deletemin()   //dinh co khoa nho nhat, xoa khoi tap
{    int a,b;
    for(int i=0;i<dem;i++)
       hangdoithu[i]=hangdoi[i];
    for(int f=1;f<=sodinh;f++)
       disttest[f]=dist[f];
    for(int j=0;j<dem-1;j++)
    for(int k=j+1;k<dem;k++)
    {    if(disttest[hangdoithu[j]]>disttest[hangdoithu[k]])
        {   
           
            a=hangdoithu[j];
            hangdoithu[j]=hangdoithu[k];
            hangdoithu[k]=a;
        }
        
    }
        for(int l=0;l<sodinh;l++)
        {
            if(hangdoi[l]==hangdoithu[xoa])
            hangdoi[l]=0;
        }
        xoa++;
        
    
}
void dijkstra(int s)
{
    for(int i=1;i<=sodinh;i++)
     dist[i]=oo;
    dist[s]=0;
   
    for (int l = 1; l <= sodinh; l++)
    {
        insert(l);
    }
    while(xoa!=sodinh)                                          
    {  int u,v;
    deletemin();
        u=hangdoithu[xoa-1];
           for(v=1;v<=sodinh;v++)
           {   if(matran[u][v]==1)
                  { 
               if(dist[v]>khoangcach[u][v]+dist[u])
               {    
                   dist[v]=khoangcach[u][v]+dist[u];
                   truoc[v]=u;
               }}
           }
    }
}
void nhapmatran()
{   int x,y,z;
    scanf("%d",&sodinh);
   scanf("%d",&socanh);
    for (int i=0;i<socanh;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        matran[x][y]=1;
        matran[y][x]=1;
        khoangcach[x][y]=z;khoangcach[y][x]=z;
    }
}
int main()
{
    nhapmatran();
    dijkstra(1); 
    for(int i=1;i<=sodinh;i++)
    {
        int u=i;
        while (u!=1)
        {
            printf("%d <--",u);
            u=truoc[u];
        }
         printf("1\n");  
    } 
    return 0;
}
