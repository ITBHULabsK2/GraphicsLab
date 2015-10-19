#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#define pi 3.1416
void main()
{
  int gd=DETECT,gm;
  int h,k,a,b;
  int x,y;
  float xEnd;
  /* read result of initialization */
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  printf("enter the the centre and radius in sequence h,k,r\n\ scren resolution is %d and %d \n",getmaxx(),getmaxy());
  scanf("%d,%d,%d,%d",&h,&k,&a,&b);
  xEnd=a;

  cleardevice();

  for(x=0;x<(int)xEnd;x++){
  y=(int)(b*sqrt(1-((x*x)/(a* a))));
  putpixel(x+h,y+k,6);
  putpixel(-x+h,y+k,6);
  putpixel(x+h,-y+k,6);
  putpixel(-x+h,-y+k,6);
 /* putpixel(y+h,x+k,6);
  putpixel(-y+h,x+k,6);
  putpixel(y+h,-x+k,6);
  putpixel(-y+h,-x+k,6);   */
  }

  getch();
  closegraph();
  return;
 }
