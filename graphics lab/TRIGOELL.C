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
  int h,k,a,b,dif;
  int x,y;
  float theta=0,thetaEnd=pi/2;
  /* read result of initialization */
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  dif=thetaEnd*100;
  printf("enter the the centre and radius in sequence h,k,r\n\ scren resolution is %d and %d \n",getmaxx(),getmaxy());
  scanf("%d,%d,%d,%d",&h,&k,&a,&b);

  cleardevice();

  while(dif>0){
  x=(int)(a*cos(theta));
  y=(int)(b*sin(theta));
  theta+=.01;
  dif=(thetaEnd-theta)*100;
  putpixel(x+h,y+k,6);
  putpixel(-x+h,y+k,6);
  putpixel(x+h,-y+k,6);
  putpixel(-x+h,-y+k,6);
 /* putpixel(y+h,x+k,6);  */
 /* putpixel(-y+h,x+k,6);
  putpixel(y+h,-x+k,6);
  putpixel(-y+h,-x+k,6);   */
  delay(10);
  }

  getch();
  closegraph();
  return;
 }
