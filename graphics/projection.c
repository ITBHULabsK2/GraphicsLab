#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <iostream>

 
using namespace std;

typedef struct pt
{
	int x,y,z;
}p;

p point[8];

void mainMenu();
void init();
void cube(p point[]);
void drawline(p a, p b);
void perspective(p point[]);
void parallel(p point[]);

int main()
{
	int gdriver,gmode;
        gmode=VGAMAX; gdriver=VGA;
        initgraph(&gdriver,&gmode,"");

        point[0].x=0 , point[0].y=0 , point[0].z=0;
        point[1].x=100,point[1].y=0,point[1].z=0;
        point[2].x=100,point[2].y=-100,point[2].z=0;
        point[3].x=0,point[3].y=-100,point[3].z=0;
        point[4].x=0,point[4].y=0,point[4].z=100;
        point[5].x=100,point[5].y=0,point[5].z=100;
        point[6].x=100,point[6].y=-100,point[6].z=100;
        point[7].x=0,point[7].y=-100,point[7].z=100;

       init();
       mainMenu();
       getch();
       return 0;
   }

void init()
{
	cleardevice();
        int i;
        for(i=0;i<8;i++)
        {
        	newVertices[i]=point[i];
        }
 	newOrigin.x=0 , newOrigin.y=0, newOrigin.z=0;
	setcolor(WHITE);
	line(400,0,400,300);
        line(400,300,799,300);
        line(400,300,0,600);
        putpixel(400,300,12);
        setcolor(GREEN);
        cube(point);
        return;
}

void mainMenu()
{
	      
        int choice;
        cout<<"\n\nEnter:\n1 -> Perspective Projection\n2 -> Parallel Projection\n3 -> Reset\n4 -> Exit\n-> ";
        cin>>choice;
        switch(choice)
         {
        	case 1:
        		perspective(newVertices);
        		mainMenu();
        		break;
        	case 2:
        		parallel(newVertices);
        		mainMenu();
        		break;
        	case 3:
        		init();
        		mainMenu();
        		break;
        	case 4 :
        		exit(0);
        		break;
        	default :
        		cout<<"\nEnter the correct choice\n";
        		mainMenu();
        		return;
         }
  	return;
}
void cube(p pt[])
{
	drawline(pt[0],pt[1]);
	drawline(pt[0],pt[3]);
	drawline(pt[0],pt[4]);
	drawline(pt[1],pt[2]);
	drawline(pt[1],pt[5]);
	drawline(pt[2],pt[3]);
	drawline(pt[2],pt[6]);
	drawline(pt[3],pt[7]);
	drawline(pt[4],pt[7]);
	drawline(pt[4],pt[5]);
	drawline(pt[5],pt[6]);
	drawline(pt[6],pt[7]);
}

void drawline(p a, p b)
{
	cout<<"\n\n"<<a.x<<"\t"<<a.y<<"\t"<<b.x<<"\t"<<b.y<<"\n";
	a.x = a.x + 400 -(int)((4.0/7)*(float)a.z);
	a.y = a.y + 300 +(int)((3.0/7)*(float)a.z);
	b.x = b.x + 400 - (int)((4.0/7)*(float)b.z);
	b.y = b.y + 300 +(int)((3.0/7)*(float)b.z);
	cout<<a.x<<"\t"<<a.y<<"\t"<<b.x<<"\t"<<b.y<<"\n\n";
	line(a.x, a.y, b.x, b.y);
}

void perspective(p point[])
{
}

void parallel(p point[])
{
}

