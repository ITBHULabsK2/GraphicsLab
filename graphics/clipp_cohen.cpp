#include <iostream>
using namespace std;
#include <graphics.h>
#include <math.h>
#include <stdio.h>

int x1Win,y1Win,x2Win,y2Win;
int xMax, yMax;
int x1Line,y1Line,x2Line,y2Line;

void clipValid();
int zone(int x1,int y1);
void drawView(int x1,int y1,int x2,int y2);
void clip();
void clip_special(int i);
int main()
{
	int gdriver,gmode;
        gmode=VGAMAX; gdriver=VGA;
        initgraph(&gdriver,&gmode,"");
        xMax=getmaxx(), yMax=getmaxy();
        int x1,y1,x2,y2;
	cout<<"Enter the diagonal coordinates for the window \n->";
	cin>>x1>>y1>>x2>>y2;
	x1Win=x1, y1Win=y1,x2Win=x2, y2Win=y2;
	rectangle(x1,y1,x2,y2);
	cout<<"\n\nEnter the end points of the line\n->";
	cin>>x1>>y1>>x2>>y2;
	x1Line=x1, y1Line=y1, x2Line=x2, y2Line=y2;
	getch();
	line(x1Line,y1Line,x2Line,y2Line);
	
	clipValid();
	getch();
	return 0;
}

void clipValid()
{
	int r1,r2;
	r1=zone(x1Line,y1Line);
	r2=zone(x2Line,y2Line);
	
	if(r1 & r2)
		//drawView(x1Line,y1Line,x2Line,y2Line);
		line(x1Line,y1Line,x2Line,y2Line);
	else if(r1==0 && r2==0)
			drawView(x1Line,y1Line,x2Line,y2Line);
		else if(r1==0)
			clip_special(1);
		else if(r2==0)
			clip_special(2);
		else	
			clip();
	
	return;	
}

int zone(int x,int y)
{
	int r;
	if(x<x1Win && y<y1Win)
		return 9;
	else if (x<x1Win && (y<=y2Win && y>=y1Win))
			return 1;
	else if (x<x1Win && (y<=yMax && y>=y2Win))
			return 5;
	else if((x<=x2Win && x>=x1Win) && (y<=yMax && y>=y2Win))
			return 4;
	else if ((x<=xMax && x>=x2Win) && (y<=yMax && y>=y2Win))
			return 6;
	else if ((x>x2Win) && (y<=y2Win && y>=y1Win))
			return 2;
	else if ((x>x2Win) && (y<y1Win))
			return 10;
	else if ((x<=x2Win && x>=x1Win) && (y<y1Win))
			return 8;
	else if((x<=x2Win && x>=x1Win) && (y<=y2Win && y>=y1Win))
			return 0;
	else 
		return -1;
}

void clip()
{
	float m=(float)(y2Line-y1Line)/(x2Line-x1Line);
	float xa,xb,ya,yb;
	xa = (y1Win-y1Line)/m + x1Line;
	xb = (y2Win-y1Line)/m + x1Line;
	ya = m*(x1Win-x1Line) + y1Line;
	yb = m*(x2Win-x1Line) + y1Line;
	cout <<"\n\n"<<m<<"\t"<<xa<<"\t"<<xb<<"\t"<<ya<<"\t"<<yb<<"\n";
	
	if(x1Win<=xa && x2Win>=xa)
		{
			if(x1Win<=xb && x2Win>=xb)
			{
				drawView(xa,y1Win,xb,y2Win);
			}
			else if(y1Win<=ya && y2Win>=ya)
			{
				drawView(xa,y1Win,x1Win,ya);
			}
			else if(y1Win<=yb && y2Win>=yb)
			{
				drawView(xa,y1Win,x2Win,yb);
			}
		}
		else if(x1Win<=xb && x2Win>=xb)
		{
			if(y1Win<=ya && y2Win>=ya)
			{
				drawView(xb,y2Win,x1Win,ya);
			}
			else if(y1Win<=yb && y2Win>=yb)
			{
				drawView(xa,y1Win,x2Win,yb);
			}
		}
		else if(y1Win<=ya && y2Win>=ya)
		{
			drawView(x1Win,ya,x2Win,yb);
		}	
		
	return;
}

void clip_special(int i)
{
	float m=(float)(y2Line-y1Line)/(x2Line-x1Line);
	float xa,xb,ya,yb;
	xa = (y1Win-y1Line)/m + x1Line;
	xb = (y2Win-y1Line)/m + x1Line;
	ya = m*(x1Win-x1Line) + y1Line;
	yb = m*(x2Win-x1Line) + y1Line;
	cout <<"\n\n"<<m<<"\t"<<xa<<"\t"<<xb<<"\t"<<ya<<"\t"<<yb<<"\n";
	
	switch (i)
	{
		case 1:
			if(((x1Line<=xa && x2Line>=xa)||(x1Line>=xa && x2Line<=xa)) && (x1Win<=xa && x2Win>=xa))
				drawView(x1Line,y1Line,xa,y1Win);
			else if(((x1Line<=xb && x2Line>=xb)||(x1Line>=xb && x2Line<=xb)) && (x1Win<=xb && x2Win>=xb))	
				drawView(x1Line,y1Line,xb,y2Win);
			else if(((y1Line<=ya && y2Line>=ya)||(y1Line>=ya && y2Line<=ya)) && (y1Win<=ya && y2Win>=ya))
				drawView(x1Line,y1Line,x1Win,ya);
			else if(((y1Line<=yb && y2Line>=yb)||(y1Line>=yb && y2Line<=yb)) && (y1Win<=yb && y2Win>=yb))
				drawView(x1Line,y1Line,x2Win,yb);
			break;
		case 2:
			if(((x1Line<=xa && x2Line>=xa)||(x1Line>=xa && x2Line<=xa)) && (x1Win<=xa && x2Win>=xa))
				drawView(x2Line,y2Line,xa,y1Win);
			else if(((x1Line<=xb && x2Line>=xb)||(x1Line>=xb && x2Line<=xb)) && (x1Win<=xb && x2Win>=xb))	
				drawView(x2Line,y2Line,xb,y2Win);
			else if(((y1Line<=ya && y2Line>=ya)||(y1Line>=ya && y2Line<=ya)) && (y1Win<=ya && y2Win>=ya))
				drawView(x2Line,y2Line,x1Win,ya);
			else if(((y1Line<=yb && y2Line>=yb)||(y1Line>=yb && y2Line<=yb)) && (y1Win<=yb && y2Win>=yb))
				drawView(x2Line,y2Line,x2Win,yb);
			break;
	}
	return;
}

void drawView(int x1,int y1,int x2,int y2)
{
	getch();
	setcolor(RED);
	line(x1,y1,x2,y2);
	return;
}
