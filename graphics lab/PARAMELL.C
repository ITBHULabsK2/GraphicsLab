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
  int h,k,dif;
  float x,y,a,b,i,j;
  float theta=0,thetaEnd=pi/2;
  /* read result of initialization */
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  dif=thetaEnd*100;
  printf("enter the the centre and radius in sequence h,k,r\n\ scren resolution is %d and %d \n",getmaxx(),getmaxy());
  scanf("%d,%d,%f,%f",&h,&k,&a,&b);

  cleardevice();
  x=a; y=0;
  while(dif>0){
  i=x*cos(.01)-(a/b)*y*sin(.01);
  j=(b/a)*x*sin(.01)+y*cos(.01);
  x=i;y=j;
  theta+=.01;
  dif=(thetaEnd-theta)*100;
  putpixel((int)x+h,(int)y+k,6);
  putpixel((int)(-x)+h,(int)y+k,6);
  putpixel((int)x+h,(int)(-y)+k,6);
  putpixel((int)(-x)+h,(int)(-y)+k,6);
  delay(10);
  }
  putpixel(a+h,k,10);
  putpixel(h,k,4);
  getch();
  closegraph();
  return;
 }
