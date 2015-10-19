#include <iostream>
using namespace std;
#include <graphics.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1416
typedef struct pt
{
	int x,y,z;
}p;

p point[8];
p newOrigin, newVertices[8];

void init();
void mainMenu();
void drawline(p a, p b);
void cube(p point[]);
void translate(p point[]);
void rotate(p point[]);
void reflect(p point[]);
void scale(p point[]);
void shear(p point[]);
float* matMul(float t[4][4], float pt[4]);
void matEngine(float t[4][4], p pt[4]);

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
        cout<<"\n\nEnter:\n1 -> Translation\n2 -> Rotation\n3 -> Reflection\n4 -> Scaling\n5 -> Shearing\n6 -> Reset\n7 -> Exit\n-> ";
        cin>>choice;
        switch(choice)
         {
        	case 1:
        		translate(newVertices);
        		mainMenu();
        		break;
        	case 2:
        		rotate(newVertices);
        		mainMenu();
        		break;
        	case 3:
        		reflect(newVertices);
        		mainMenu();
        		break;
        	case 4:
        		scale(newVertices);
        		mainMenu();
        		break;
        	case 5:
        		shear(newVertices);
        		mainMenu();
        		break;
        	case 6:
        		init();
        		mainMenu();
        		break;
        	case 7 :
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

void translate(p pt[])
{
	int a,b,c,x,y,z;
	cout<<"\nEnter the new coordinates of the cube's origin -> ";
	cin>>a>>b>>c;
	x=a-newOrigin.x; y=b+newOrigin.y; z=c-newOrigin.z;
	float t[4][4]={{1,0,0,x},{0,1,0,-y},{0,0,1,z},{0,0,0,1}};
	matEngine(t,pt);
	setcolor(BLUE);
	cube(newVertices);
	return;
}

void rotate(p pt[])
{
	float t[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	float angle, theta;
	int choice;
	cout<<"Enter for rotatio \t1 -> x-axis\t2 -> y-axis \t 3 -> z-axis :";
	cin>>choice;
	cout<<"\nEnter the angle of rotation : ";
	cin>>angle;
	theta=(PI/180)*angle;
	switch(choice)
	{
		case 1:
			t[1][1]=cos(theta); t[1][2]=-sin(theta); t[2][1]=sin(theta); t[2][2]=cos(theta);
			break;
		case 2:
			t[0][0]=cos(theta); t[0][2]=sin(theta); t[2][0]=-sin(theta); t[2][2]=cos(theta);
			break;
		case 3:
			t[0][0]=cos(theta); t[0][1]=-sin(theta); t[1][0]=sin(theta); t[1][1]=cos(theta);
			break;
		default:
			cout<<"Enter correct choice\n->";
			rotate(pt);
			return;
	}
	matEngine(t,pt);
	setcolor(RED);
	cube(newVertices);
	return;
	
}

void reflect(p pt[])
{
	float t[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	int choice;
	cout<<"Enter for reflection \t1 -> xy-plane\t2 -> yz-plane \t 3 -> xz-plane :";
	cin>>choice;
	switch(choice)
	{
		case 1:
			t[2][2]=-1;
			break;
		case 2:
			t[0][0]=-1;
			break;
		case 3:
			t[1][1]=-1;
			break;
		default:
			cout<<"Enter correct choice\n->";
			reflect(pt);
			return;
	}
	matEngine(t,pt);
	setcolor(RED);
	cube(newVertices);
	return;
}

void scale(p pt[])
{
	float x,y,z;
	cout<<"\nEnter the scaling factor -> ";
	cin>>x>>y>>z;
	float t[4][4]={{x,0,0,0},{0,y,0,0},{0,0,z,0},{0,0,0,1}};
	matEngine(t,pt);
	setcolor(BLUE);
	cube(newVertices);
	return;
}

void shear(p pt[])
{
	float a,b;
	float t[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	int choice;
	cout<<"\nEnter for shearing \t 1 -> x-axis \t2 -> y-axis \t 3 -> z-axis :";
	cin>>choice;
	cout<<"Enter the shear factors : ";
	cin>>a>>b;
	switch(choice)
	{
		case 1:
			t[1][0]=-a; t[2][0]=b;
			break;
		case 2:
			t[0][1]=a; t[2][1]=b;
			break;
		case 3:
			t[0][2]=a; t[1][2]=-b;
			break;
		default:
			cout<<"Enter correct choice\n->";
			shear(pt);
			return;
	}
	matEngine(t,pt);
	setcolor(RED);
	cube(newVertices);
	return;
}

float* matMul(float t[4][4], float pt[4])
{
	float newPt[4]={0,0,0,0};
	int i,j;
	for(i=0; i<4;i++)
		for (j=0;j<4;j++)
			newPt[i]+=t[i][j]*pt[j];
	return newPt;
}

void matEngine(float t[4][4], p pt[4])
{
	int i;
	for(i=0;i<8;i++)
	{
		float c[4]={pt[i].x,pt[i].y,pt[i].z,1};
		float *a;
		a=matMul(t,c);
		newVertices[i].x=*a;
		newVertices[i].y=*(a+1);
		newVertices[i].z=*(a+2);
	}
	newOrigin.x=newVertices[0].x;
	newOrigin.y=newVertices[0].y;
	newOrigin.z=newVertices[0].z;
	return;
}
