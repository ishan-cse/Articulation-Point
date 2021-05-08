#include <iostream>
using namespace std;
void dfs(int v);
int a[20][20],alt[20][20],n,reach[20],ap[100];

int main()
{
    int i,j,k,l;
    cout<<"\n Enter no of vertex : ";
    cin>>n;

    for(i=1;i<=n;i++)
       {
        for(j=1;j<=n;j++)
        {
        a[i][j]=0;
        alt[i][j]=0;
        }
       }

    cout<<"\n Enter adjacency matrix : \n";
    for(i=1;i<=n;i++)
      {
      for(j=1;j<=n;j++)
       {
           cin>>a[i][j];
       }
      }
//give value to alternative array
       for(i=1;i<=n;i++)
       {
      for(j=1;j<=n;j++)
        {
            alt[i][j]= a[i][j];
            alt[j][i]= a[j][i];
        }
       }
//graph
       for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
        {
            a[i][j]=0;
            a[j][i]=0;
        }
//remove that row $ column
      for(int q=i;q<=n;q++)
      {
          for(int x=1;x<=n;x++)
        {
            a[x][q]=a[x][q+1];
        }
      }

      for(int q=i;q<=n;q++)
      {
        for(int y=1;y<=n;y++)
        {
            a[q][y]=a[q+1][y];
        }
      }
//check connection
     for(l=1;l<=n;l++)
     {
         reach[l]=0;
     }
dfs(1);

int nn=n-1,c=0;
   for(l=1;l<=nn;l++)
       {
           if(reach[l]==1)
            {
              c=c+1;
            }
       }

 if(c==nn)
       {
           ap[i]=0;   // connected
       }
  else
       {
           ap[i]=i;  // disconnected 
       }
//re-arrange the value of array
    for(k=1;k<=n;k++)
     {
       for(j=1;j<=n;j++)
        {
            a[k][j]= alt[k][j];
            a[j][k]= alt[j][k];
        }
     }
 }
//result    
cout<<"\n articulation point : \n";
      for(int s=1;s<=n;s++)
      {
          if(ap[s]!=0)
          {
             cout<<"\n"<< ap[s] <<"\n";
          }
      }
    return 0;
}

void dfs(int v)
{
     int m;
     reach[v]=1;
     for(m=1;m<=n;m++)
     {
         if((a[v][m]==1)&&(reach[m]==0))
            {
            dfs(m);
            }
     }
 }
