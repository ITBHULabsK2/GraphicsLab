#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#define pi 3.1416
void main()
{
  int gd=DETECT,gm;
  int h,k,r,dif;
  int x=0,y;
  float p;
  /* read result of initialization */
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  printf("enter the the centre and radius in sequence h,k,r\n\ scren resolution is %d and %d \n",getmaxx(),getmaxy());
  scanf("%d,%d,%d,%d",&h,&k,&r);
  y=r;
  p=3/2-r;

  cleardevice();

  while(x<=y){
  x++;
  if(p<0){
  p+=4*x+6;
  }
  else{
  y--;
  p+=4*x+10-4*y;
  }
  putpixel(x+h,y+k,6);
  putpixel(-x+h,y+k,5);
  putpixel(x+h,-y+k,4);
  putpixel(-x+h,-y+k,3);
  putpixel(y+h,x+k,2);
  putpixel(-y+h,x+k,7);
  putpixel(y+h,-x+k,8);
  putpixel(-y+h,-x+k,9);
  delay(10);
  }

  getch();
  closegraph();
  return;
 }
