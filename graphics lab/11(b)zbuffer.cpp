#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
int driver=DETECT,mode;
   initgraph(&driver,&mode,NULL);
 int n,n1[10],x[10][10],y[10][10],z1[10][10],j,z,i,k,x1,y1,z2,delta,l,m,p,minx1[10],maxx1[10],maxy1[10],miny1[10];
float a[10],b[10],c[10],g,h;
 int maxx=getmaxx(),maxy=getmaxy();
 int buffer[50][50],print[50][50];
 cout<<"Enter the no. of planes :";
 cin>>n;
 //cout<<"Enter the equation of the planes i.e. a b c d (ax+by+cz+d=0):\n";
 for(i=0;i<n;i++)
 {
	cout<<"enter the number of points for the plane no"<<i<<"\n";
	cin>>n1[i];
	cout<<"enter the x,y,z co-ordinate"<<"\n";
	
	for(j = 0;j<=n1[i];j++)
	{
		cin>>x1>>y1>>z2;
		x[i][j] = x1;
		y[i][j] = y1;
		z1[i][j] = z2;
 	}
    //cin>>a[i]>>b[i]>>c[i]>>d[i];
 }

for(i=0;i<n;i++)
{ 
  minx1[i]=maxx;
  miny1[i]=maxy;
  maxx1[i]=0;
  maxy1[i]=0;
}
for(i=0;i<n;i++)
 {
	for(j = 0;j<n1[i];j++)
            {
                if(x[i][j]<minx1[i])
                      minx1[i]=x[i][j];
                 if(y[i][j]<miny1[i])
                      miny1[i]=y[i][j];
                 if(x[i][j]>maxx1[i])
                      maxx1[i]=x[i][j];
               if(y[i][j]>maxy1[i])
                      maxy1[i]=y[i][j];
                    
            }

 }
 for(i=0;i<n;i++)
  {
    cout<<minx1[i]<<"  "<<miny1[i]<<"  "<<maxx1[i]<<"  "<<maxy1[i]<<endl;
 }
for(i = 0;i<n;i++)
{
    delta = x[i][0]*(y[i][1]*z1[i][2] - y[i][2]*z1[i][1]) - y[i][0]*(x[i][1]*z1[i][2] - x[i][2]*z1[i][1]) + z1[i][0]*(x[i][1]*y[i][2] - x[i][2]*y[i][1]);
      l = (y[i][1]*z1[i][2] - y[i][2]*z1[i][1]) - y[i][0]*(z1[i][2] - z1[i][1]) + z1[i][0]*(y[i][2] - y[i][1]);
      m = x[i][0]*(z1[i][2] - z1[i][1]) - (x[i][1]*z1[i][2] - x[i][2]*z1[i][1]) + z1[i][0]*(x[i][1] - x[i][2]);
      p = x[i][0]*(y[i][1] - y[i][2]) - y[i][0]*(x[i][1] - x[i][2]) + (x[i][1]*y[i][2] - x[i][2]*y[i][1]);
      a[i] = (float)(l)/((float)(delta));
       b[i] = (float)(m)/((float)(delta));	 
       c[i] = (float)(p)/((float)(delta));	
	cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;	
}
float t=0.0;
int b1;
 
 for(i=0;i<50;i++)
  for(j=0;j<50;j++)
     {
  print[i][j]=0; 
  buffer[i][j]=1000;
  }
 
for(k=0;k<n;k++)
  {
   
   for(b1=0;b1<n1[k];b1++) 
   {
     for(t=0;t<=1;t+=.01)
      { 
       g=x[k][b1];
       h=y[k][b1];
       g+=((x[k][b1+1]-x[k][b1])*t);
       h+=((y[k][b1+1]-y[k][b1])*t);
          z=(-a[k]*(int)(g)-b[k]*(int)(h)+1)/c[k];
         if(z<buffer[(int)(g)][(int)(h)])
            {
            buffer[(int)(g)][(int)(h)]=z;
            print[(int)(g)][(int)(h)]=k+1;
             }     
                      //cout<<g<<" "<<h<<endl;
      }
   }
  
   }
   
   
 
   for(i=minx1[0];i<=maxx1[0];i++)
  {
  for(j=miny1[0];j<=maxy1[0];j++)
     {
      
          z=(-a[0]*(i)-b[0]*(j)+1)/c[0];
         if(z<buffer[(i)][(j)])
            {
            buffer[(i)][(j)]=z;
            print[(i)][(j)]=1;
             }      
              
             //cout<<g<<" "<<h<<endl;
      }
}
  for(i=0;i<50;i++)
{
  for(j=0;j<50;j++)
{   cout<<print[i][j]<<" ";
   putpixel(i,j,print[i][j]+2);
}
 cout<<endl;
}

getch();
 //closegraph();
}
