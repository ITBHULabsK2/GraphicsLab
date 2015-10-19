#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define and &&
#define or ||
struct edge
	{
	int x,y;
	struct edge* next;
	};
void put(int x , int y, int color)
	{
	putpixel(400+x,300-y,color);
	}
int get(int x, int y)
	{
	return getpixel(400+x,300-y);
	}
void line(float x1,float y1, float x2, float y2,int color )
	{
	int steps=(int)sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
	float x,y,dx,dy;
	dx=(x2-x1)/steps;
	dy=(y2-y1)/steps;

	x=x1;y=y1;
	for(int i=0; i<steps;i++)
		{
		x+=dx;y+=dy;
		for(int j=0;j<1000;j++);
		put((int)x,(int)y,color);
		}
	}
int checkboundary(edge* e,int x, int y)
	{
	int x1,y1,x2,y2;
	while(e->next!=NULL)
		{
		x1=e->x;
		y1=e->y;
		x2=e->next->x;
		y2=e->next->y;
		if((x>=x1 and x<=x2) or (x>=x2 and x<=x1))
			{
			if(((y2-y1)/(float)(x2-x1)*x+(y1*x2-y2*x1)/(float)(x2-x1))==y)
				return 1;
			}
		e=e->next;
		}
	return 0;
	}
void seedfill(edge* e,int x, int y, int color)
	{
	int fill=get(x,y);
	if(/*checkboundary(e,x,y)==0 and*/ fill!=color)
		{
		put(x,y,color);

		seedfill(e,x+1,y,color);
		seedfill(e,x-1,y,color);
		seedfill(e,x,y+1,color);
		seedfill(e,x,y-1,color);
		}
	}


int main()
{	int x,y,x1,y1,x2,y2,gd=DETECT,gm;
	struct edge* starte=new edge;
	struct edge* e=starte;

	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter polygon edges");
	scanf("%d %d",&x1,&y1);
	e->x=x1;e->y=y1;
	for(scanf("%d %d",&x,&y); x!=-1 and y!=-1;scanf("%d %d",&x,&y))
		{
		e->next=new edge;
		e->next->x=x;
		e->next->y=y;
		e=e->next;
		line(x1,y1,x,y,GREEN);
		x1=x;
		y1=y;
		}
	e->next=NULL;
	seedfill(starte,0,0,GREEN);
	getch();

}
