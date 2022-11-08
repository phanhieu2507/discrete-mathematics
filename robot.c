#include<stdio.h>
int sodinh,socanh,dinhmot,dinhhai,r,dichmot,dichhai; //dinh bat dau cua 2 robot, khoang cach min,dich den//
#define max 1000
#define oo 1000 
static int dist[max];
static int disttest[max];
static int matran[max][max];
static int hangdoi[max];
static int hangdoithu[max];
static int khoangcach[max][max];
static int truoc[max];
static int duongdimot[max],duongdihai[max];
static int matranthu[max];
int dem=0,xoa=0;
static int vitrimot[max],vitrihai[max];
int y=0,z=0; // dem so lan nhay cua robot 1 va 2 
void nhapmatran()
{    int x,y,z;    
    scanf("%d %d",&sodinh,&socanh);
    for(int i=1;i<=socanh;i++)
    {
       scanf("%d %d %d",&x,&y,&z);
       matran[x][y]=1;matran[y][x]=1;khoangcach[x][y]=z;khoangcach[y][x]=z;
    }
    scanf("%d %d",&dinhmot,&dinhhai);
    scanf("%d %d",&dichmot,&dichhai);
    scanf("%d",&r);    
   
}                                       // dung thuat toan dijkstra de tim khoang cach//
void insert(int u) //them u vao tap
{ 
  hangdoi[dem]=u;
  dem++;     
}
void deletemin()   //dinh co khoa nho nhat, xoa khoi tap
{    int a,b;
    for(int i=0;i<dem;i++)
       hangdoithu[i]=hangdoi[i];
    for(int f=0;f<sodinh;f++)
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
            hangdoi[l]=-1;
        }
        xoa++;
        
    
}
void dijkstra(int s)
{
    for(int i=-1;i<=sodinh;i++)
     {dist[i]=oo;truoc[i]=0;hangdoi[i]=0;}
    dist[s]=0;dem=0;xoa=0;
   
    for (int l = 0; l < sodinh; l++)
    {
        insert(l);
    }
    
    while(xoa!=sodinh)
    {  int u,v;
    deletemin();
        u=hangdoithu[xoa-1];
           for(v=0;v<sodinh;v++)
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
int distance(int s,int t) // tim khoang cach ngan nhat giua 2 dinh s va t
{ int x=0;
    dijkstra(s);
     x=dist[t];
      return x;
}
void timduongdingannhat()  // dung thuat toandijkstra de tim duong di 
{       int dinhthu,x=0,t=0;
   dijkstra(dinhmot);
     dinhthu=dichmot;
     while(dinhthu!=dinhmot)
     {    matranthu[x]=dinhthu;
          dinhthu=truoc[dinhthu];
          x++;
     } 
     matranthu[x]=dinhmot;
     while(x!=0)
     {
         duongdimot[y]=matranthu[x];
         y++;x--;
     }  duongdimot[y]=dichmot; 
     dijkstra(dinhhai);
     dinhthu=dichhai;
     while(dinhthu!=dinhhai)
     {    matranthu[t]=dinhthu;
          dinhthu=truoc[dinhthu];
          t++;
     } 
     matranthu[t]=dinhhai;
     while(t!=0)
     {
         duongdihai[z]=matranthu[t];
         z++;t--;
     }  duongdihai[z]=dichhai;
  
}
int timlichdichuyen()
{  vitrimot[0]=duongdimot[0];
   vitrihai[0]=duongdihai[0];
   static int k=1;
   int m=0,n=0;
   while(k!=(y+z+1))
   {
       if(distance(duongdimot[m+1],vitrihai[n])>r&&distance(duongdihai[n+1],vitrimot[m])<=r)
       {    vitrimot[k]=duongdimot[m+1];
            vitrihai[k]=duongdihai[n];
               k++;m++;
       } else 
       if(distance(duongdihai[n+1],vitrimot[m])>r&&distance(duongdimot[m+1],vitrihai[n])<=r)
       {    vitrihai[k]=duongdihai[n+1];
            vitrimot[k]=duongdimot[m];
               k++;n++;
       } else if (distance(duongdimot[m+1],vitrihai[n])>r&&distance(duongdihai[n+1],vitrimot[m])>r)
       {
           vitrimot[k]=duongdimot[m+1];
            vitrihai[k]=duongdihai[n];
               k++;m++;
       }
       else {return 0; break;}  
   }
}
int main()
{    nhapmatran();
     timduongdingannhat();
     timlichdichuyen();
     if(timlichdichuyen()==0) printf("Khong the !"); 
     else for(int i=0;i<=(y+z);i++)
     {
         printf("%d   %d \n",vitrimot[i],vitrihai[i]);
     }
 
return 0;
}