#include<iostream>
using namespace std;
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
int round (float y)
{ 
return (int)(y+0.5);
}
void DD_Line(int x1,int y1,int x2,int y2);

struct point_poly
{
    int x;
    int y;
};

struct normal_edge
{
   int x_coeff;
   int y_coeff;
};

struct line_coordinate
{
   struct point_poly start_point;
   struct point_poly end_point;
};

int mark=6;
int main()
{
       int gdriver=VGAMAX,gmode=VGA;
       initgraph(&gdriver,&gmode,"");
       setcolor(GREEN);
       int k;
       k=6;
     /*  cout<<"enter the no. of edge in the convex polygon"<<endl<<"entered point should be in clockwise direction"<<endl;
       cin>>k;*/
       struct point_poly vertex[k];
       struct normal_edge normal[k];
       int i,j;
  /*     for(i=0;i<k;i++)
       {
           cout<<"enter the coordinates(x,y) of the "<<(i+1)<<" vertex"<<endl;
           cin>>vertex[i].x>>vertex[i].y;
       } */
       vertex[0].x=200;vertex[0].y=100;
       
       vertex[1].x=300;vertex[1].y=100;
       
       vertex[2].x=400;vertex[2].y=200;
       
       vertex[3].x=400;vertex[3].y=300;
       
       vertex[4].x=300;vertex[4].y=400;

       vertex[5].x=200;vertex[5].y=400;
       
       //vertex[6].x=100;vertex[6].y=300;
       
      // vertex[7].x=100;vertex[7].y=200;
       
       for(i=0;i<k-1;i++)
	       DD_Line(vertex[i].x,vertex[i].y,vertex[i+1].x,vertex[i+1].y);

       DD_Line(vertex[k-1].x,vertex[k-1].y,vertex[0].x,vertex[0].y);

       for(i=0;i<k-1;i++)
       {
            normal[i].x_coeff=(-1)*(vertex[i+1].y-vertex[i].y);
            normal[i].y_coeff=(1)*(vertex[i+1].x-vertex[i].x);
           // cout<<" normal["<<i<<"].x_coeff="<<normal[i].x_coeff<<"  normal["<<i<<"].y_coeff="<<normal[i].y_coeff<<endl;
       }
           normal[k-1].x_coeff=(-1)*(vertex[0].y-vertex[k-1].y);
           normal[k-1].y_coeff=(1)*(vertex[0].x-vertex[k-1].x);
           // cout<<" normal["<<i<<"].x_coeff="<<normal[i].x_coeff<<"  normal["<<i<<"].y_coeff="<<normal[i].y_coeff<<endl;
      int no_lines;
      cout<<"enter the no. of the lines"<<endl;
      cin>>no_lines;
      struct line_coordinate line[no_lines];
      for(i=0;i<no_lines;i++)
      {
            cout<<"enter the end points of "<<(i+1)<<" line:"<<endl;
            cin>>line[i].start_point.x>>line[i].start_point.y>>line[i].end_point.x>>line[i].end_point.y;
            //cout<<"enter the end point of "<<(i+1)<<" line:"<<endl;
            //cin>>line[i].end_point.x>>line[i].end_point.y;
      }
      mark++;
      for(i=0;i<no_lines;i++)
      {
            DD_Line(line[i].start_point.x,line[i].start_point.y,line[i].end_point.x,line[i].end_point.y);
       }
       getch();
       cleardevice();
      // initgraph(&gdriver,&gmode,"");
       for( i=0;i<k-1;i++)
              DD_Line(vertex[i].x,vertex[i].y,vertex[i+1].x,vertex[i+1].y);

        DD_Line(vertex[k-1].x,vertex[k-1].y,vertex[0].x,vertex[0].y);
        mark=mark+2;;

       for(j=0;j<no_lines;j++)
       {
              struct normal_edge directrix;
              directrix.x_coeff=line[j].end_point.x-line[j].start_point.x;
              directrix.y_coeff=line[j].end_point.y-line[j].start_point.y;
             // cout<<"directrix.x_coeff= "<<directrix.x_coeff<<" directrix.y_coeff= "<<directrix.y_coeff<<endl<<endl;
              float t_upper=1.0,  t_lower=0.0,  t;
              struct normal_edge w;
              int DdotNormal,WdotNormal;
              for(i=0;i<k;i++)
              {
                       
                       //struct normal_edge w;
                       w.x_coeff=line[j].start_point.x-vertex[i].x;
                       w.y_coeff=line[j].start_point.y-vertex[i].y;
                      // cout<<"w.x_coeff= "<<w.x_coeff<<" w.y_coeff= "<<w.y_coeff<<endl;
                      // int DdotNormal,WdotNormal;
                       DdotNormal=directrix.x_coeff * normal[i].x_coeff + directrix.y_coeff * normal[i].y_coeff ;
                       WdotNormal= w.x_coeff * normal[i].x_coeff + w.y_coeff * normal[i].y_coeff;
                      // cout<<"wdotnormal= "<<WdotNormal<<endl;
                      // cout<<"Ddotnormal= "<<DdotNormal<<endl;
                      
                       t=(-1)*((float)WdotNormal/DdotNormal);
                      // cout<<" t= "<<t<<endl;
                       if(t>=0 && t<=1)
                       {
                             if(DdotNormal>0)
                            { //t_lower=max(t,t_lower);
                                t_lower=((t>t_lower)?t:t_lower);
                             // cout<<" t_lower= "<<t_lower<<endl;
                             }
                             else
                            { //t_upper=min(t,t_upper);
                               t_upper=((t<t_upper)?t:t_upper);
                            //  cout<<" t_upper= "<<t_upper<<endl;
                            }
                       }
              } // loop ends for checking intersection of a line.
            //  cout<<" final value of t_lower and t_upper for this line is :"<<endl;
            //  cout<<" the value of t_lower is :"<<t_lower<<endl;
                    //  cout<<" the value of t_upper is :"<<t_upper<<endl;
              struct line_coordinate clip_line;
              if(t_lower<t_upper)
             // if(1)
              {
                     // cout<<" the value of t_lower is :"<<t_lower<<endl;
                     // cout<<" the value of t_upper is :"<<t_upper<<endl;
                     // struct line_coordinate clip_line;
                      clip_line.start_point.x=(int)(line[j].start_point.x + (line[j].end_point.x-line[j].start_point.x) * t_lower);
                      clip_line.start_point.y=(int)(line[j].start_point.y + (line[j].end_point.y-line[j].start_point.y) * t_lower);
                      clip_line.end_point.x=(int)(line[j].start_point.x + (line[j].end_point.x-line[j].start_point.x) * t_upper);
                      clip_line.end_point.y=(int)(line[j].start_point.y + (line[j].end_point.y-line[j].start_point.y) * t_upper);
                      
                   /*   for(i=0;i<no_lines;i++)
                      {
                          DD_Line(line[i].start_point.x,line[i].start_point.y,line[i].end_point.x,line[i].end_point.y);
                      }*/
                      DD_Line(clip_line.start_point.x,clip_line.start_point.y,clip_line.end_point.x,clip_line.end_point.y);
              }
                   /*   for(i=0;i<no_lines;i++)
                      {
                          DD_Line(line[i].start_point.x,line[i].start_point.y,line[i].end_point.x,line[i].end_point.y);
                      }*/
         } // loops ends for the clipping line.
       getch();
       closegraph();
       cleardevice();
       //getch();
       //closegraph();
       //cleardevice();
return 0;
}

void DD_Line(int x1,int y1,int x2,int y2)
{
    float dx,dy,y,m,x;
    int xtra1,xtra2;
    
    if(x1>x2)
    {
        xtra1=y1;y1=y2;y2=xtra1;
        xtra2=x1;x1=x2;x2=xtra2;
       // printf("%d %d %d %d",x1,y1,x2,y2);
    }

    dx=x2-x1;
    dy=y2-y1;
    if (fabs(dx)>fabs(dy))
    {
        m=dy/dx;
        y=y1;
        for(x=x1;x<x2;x++)
        {
            putpixel((int)x,round(y),mark);
            y=y+m;;
        }
    }
    else
    {
        m=dx/dy;
        x=x1;
        if(y1<y2)
        {
            for(y=y1;y<y2;y++)
            {
                putpixel(round(x),(int)y,mark);
                x=x+m;//mark=6;
            }
        }

        else
        {
            for(y=y1;y>y2;y--)
            {
                putpixel(round(x),(int)y,mark);
                x=x-m;//mark=6;
            }
        }
    }
}



