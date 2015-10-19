#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int gdriver,gmode;
    gmode=VGAMAX; gdriver=VGA;
    initgraph(&gdriver,&gmode,"");
    int h,k,r;
    printf("maximum value of x=%d",getmaxx());
    printf("\nmaximum value of y=%d",getmaxy());
    printf("\nenter the coordinate of the circle:");
    scanf("%d %d ", &h ,&k);
    printf("enter the radious of the circle:");
    scanf("%d",& r);
    int x=0,y=r,decision_parameter=3-2*r;
    while(x<=y)
    {
          putpixel(x+h,y+k,6);
          putpixel(y+h,x+k,6);
          putpixel(-y+h,x+k,6);
          putpixel(-x+h,y+k,6);
          putpixel(-x+h,-y+k,6);
          putpixel(-y+h,-x+k,6);
          putpixel(y+h,-x+k,6);
          putpixel(x+h,-y+k,6);
          if(decision_parameter<0)
          {
             decision_parameter=decision_parameter+4*x+6;
             x=x+1;
          }
          else
          {
             decision_parameter=decision_parameter+4*(x-y)+10;
             x=x+1;
             y=y-1;
          }
     }
    getch();
    closegraph();
    cleardevice();
return 0;
}

