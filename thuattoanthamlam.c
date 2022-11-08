#include<stdio.h>

int kiemtramau(int z[],int w,int mau) 
{
     int i; 
     for(i=1;i<=w;i++) 
     if(mau==z[i]) 
     return 1; 
     return 0; 
}
int  chonmau(int g[],int l)

   { 
    int mau=1; int i; 
    do
    { 
        if(kiemtramau(g,l,mau)==0) 
        { return mau; 
        break; } 
        else 
        mau++; 
        }
        while(1); 
    } 
void tomau() 
{ int i,j,l,x,y; 
int dinh,canh;
scanf("%d-%d",&dinh,&canh);
int n=dinh;
static int a[10][10];
for(int matran=0;matran<canh;matran++)
{

    scanf("%d-%d",&x,&y);
    a[x][y]=1;
    a[y][x]=1;
}

   
  int mau,t; 
  int maudinh[28],dinhtruoc[28],mauphu[28]; 
  i=l=mau=t=1; j=2; maudinh[1]=mau; dinhtruoc[1]=1; 
  
  do{ 
      for(int kb=1;kb<=l;kb++) 
      if(a[j][dinhtruoc[kb]]==1) 
      mauphu[++t]=maudinh[dinhtruoc[kb]]; 
      
      maudinh[j]=chonmau(mauphu,t); 
      l=j; 
      dinhtruoc[l]=j;
    
      j++; t=0; }
      while(j<=n); 
      for(i=1;i<=n;i++)
      { switch(maudinh[i])
      {
          case 1:printf("mau dinh%3d: Green\n",i); break;
          case 2:printf("mau dinh%3d: Red\n",i); break;
          case 3:printf("mau dinh%3d: Black\n",i); break;
          case 4:printf("mau dinh%3d: White\n",i); break;
          case 5:printf("mau dinh%3d: Yellow\n",i); break;
          case 6:printf("mau dinh%3d: Orange\n",i); break;
          case 7:printf("mau dinh%3d: Purple\n",i); break;
          case 8:printf("mau dinh%3d: Pink\n",i); break;
          case 9:printf("mau dinh%3d: Blue\n",i); break;
          case 10:printf("mau dinh%3d: Grey\n",i); break;
      }}}
void main() 
{ 
tomau(); 
}
