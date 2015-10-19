#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#define pi 3.1416
void main()
{
  int gd=DETECT,gm;
  int h,k,r;
  int x,y;
  float xEnd;
  /* read result of initialization */
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  printf("enter the the centre and radius in sequence h,k,r\n\ scren resolution is %d and %d \n",getmaxx(),getmaxy());
  scanf("%d,%d,%d,%d",&h,&k,&r);
  xEnd=(r*cos(pi/4));

  cleardevice();

  for(x=0;x<(int)xEnd;x++){
  y=(int)sqrt(r*r-x*x);
  putpixel(x+h,y+k,6);
  putpixel(-x+h,y+k,6);
  putpixel(x+h,-y+k,6);
  putpixel(-x+h,-y+k,6);
  putpixel(y+h,x+k,6);
  putpixel(-y+h,x+k,6);
  putpixel(y+h,-x+k,6);
  putpixel(-y+h,-x+k,6);
  }

  getch();
  closegraph();
  return;
 }
