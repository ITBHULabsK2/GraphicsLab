#include<iostream>
#include<cmath>
using namespace std;
#include<graphics.h>

float arr[800][2];
#define round(a) (int)(a+0.5)

int main()
{
    int a,b,c,d,gd=VGA,gm=VGAMAX;
    initgraph(&gd,&gm,"");
    float ymin,ymax;
   cout<<"Enter 'a','b','c','d' for eqn ax2+by2+cz2=d..";
   cin>>a>>b>>c>>d;
   for(int i=-400;i<400;i++)
   {
      arr[i+400][0]=getmaxy();
      arr[i+400][1]=0;
     }
   for(int i=-40;i<40;i++)
   {
     for(int j=-400;j<400;j++)
     {
         if(d-a*j*j-c*i*i>=0){
         ymin=-sqrt(d-a*j*j-c*i*i);
         ymax=sqrt(d-a*j*j-c*i*i);
         if(ymin<arr[j+400][0])
         arr[j+400][0]=ymin;
         if(ymax>arr[j+400][1])
         arr[j+400][1]=ymax;
         cout<<ymin<<" "<<ymax<<endl;
         }
         }
     }
     
     for(int i=-400;i<400;i++)
     {
     if(arr[i+400][0]!=getmaxy() && arr[i+400][1]!=0)
    {
    putpixel(400+i,300-round(arr[i+400][0]),RED);
     putpixel(400+i,300-round(arr[i+400][1]),RED);
      cout<<arr[i+400][0]<<" "; 
     }
      }
      getch();
      closegraph();
      
      
    } 
