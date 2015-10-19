#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#define pi 3.1416
void line1(int x1,int y1,int x2,int y2)
{
  float dx=x2-x1;
  float dy=y2-y1;
  float x=x1,y=y1,steps,k;

  if(fabs(dx)>fabs(dy))
   steps=fabs(dx);
   else steps=fabs(dy);

 // cleardevice();

  putpixel((int)x1,(int)y1,10);
  for(k=0;k<(int)steps;k++)
  {
   x=x+(float)(dx/steps);
   y=y+(float)(dy/steps);
   putpixel((int)x,(int)y,6);

  }
  putpixel(x2,y2,10);
}
void main()
{
  int gd=DETECT,gm;
  int k;
  float x0,y0,x1,y1,xn,yn,d,c,x2,y2;
  float dx,dy,dx1,dy1,theta;
  /* read result of initialization */
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  printf("enter the the end coordinates in sequence x1,y1,x2,y2,d,c\n\ scren resolution is %d and %d \n",getmaxx(),getmaxy());
  scanf("%f,%f,%f,%f,%f,%f",&x0,&y0,&xn,&yn,&d,&c);
  if(xn<x0)
  {

  }
  if(x0==xn)
  {
  theta=(pi/2);
  dx=0;
  dy=d;
  dx1=0;
  dy1=d+c;
  }
  else
  {
  theta=atan((yn-y0)/(xn-x0));
  dx=d*cos(theta);
  dy=d*sin(theta);
  dx1=(d+c)*cos(theta);
  dy1=(d+c)*sin(theta);
  }
  cleardevice();

  //printf("%f x2= %f",theta,x2);
  for(x1=x0,y1=y0;x2<=xn;x1+=dx1,y1+=dy1)
  {
   x2=x1+dx;
   y2=y1+dy;
  //printf(" x2= %f x1=%f  ",x2,x1);
   line1(x1,y1,x2,y2);
   delay(10);
  }
  getch();
  closegraph();
  return;
 }
