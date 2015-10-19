#include<iostream>
#include<math.h>
#include<graphics.h>
#define SIZE 50
using namespace std;

float fund[4][4];

float poly[4][8]={
			{SIZE,SIZE,0,0,SIZE,SIZE,0,0},
			{0,SIZE,SIZE,0,0,SIZE,SIZE,0},
			{0,0,0,0,SIZE,SIZE,SIZE,SIZE},
			{1,1,1,1,1,1,1,1}
		};
void initialize_fund()
	{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(i!=j) fund[i][j]=0; else fund[i][j]=1;
	}
void drawline(int x1,int y1, int z1, int x2, int y2, int z2, int color)
	{
	setcolor(color);
	line(400+x1-z1/2, 300-(y1-z1/2) ,400+x2-z2/2 ,300-(y2-z2/2) );
	}

void initialize_scale(float sx, float sy,float sz)
	{
					initialize_fund();
					fund[0][0]=sx;
					fund[1][1]=sy;
					fund[2][2]=sz;

	}
void initialize_rot( float theta, int rotabt)
{	initialize_fund();
	switch(rotabt)
	{
	case 'z':fund[0][0]=cos(theta);fund[0][1]=-sin(theta);
		fund[1][0]=sin(theta);fund[1][1]=cos(theta);
		break;
	case 'y':fund[0][0]=cos(theta);fund[0][2]=-sin(theta);
		fund[2][0]=sin(theta);fund[2][2]=cos(theta);
		break;
	case 'x':fund[1][1]=cos(theta);fund[1][2]=-sin(theta);
		fund[2][1]=sin(theta);fund[2][2]=cos(theta);
		break;
	}

}
void initialize_trans(float tx, float ty,float tz)
	{	initialize_fund();
		fund[0][3]=tx;
		fund[1][3]=ty;
		fund[2][3]=tz;
	}

void initialize_shear(float a, float b,int shearabt)
	{
		initialize_fund();
		switch(shearabt)
			{
			case 'x':
					fund[1][0]=a;
					fund[2][0]=b;
					break;
			case 'y':
					fund[0][1]=a;
					fund[2][1]=b;
					break;
			case 'z':
					fund[0][2]=a;
					fund[1][2]=b;
					break;
			}
	}

void matmul()
	{
	int i,j,k;
	float poly_mod[4][8];
	for(i=0;i<4;i++)
		{
		for(j=0;j<8;j++)
			{
			poly_mod[i][j]=0;
			for(k=0;k<4;k++)
				poly_mod[i][j]+=fund[i][k]*poly[k][j];
			}
		}
	for(i=0;i<4;i++)
		for(j=0;j<8;j++)
			poly[i][j]=poly_mod[i][j];
	}
void display(int color)

	{
	drawline(poly[0][0],poly[1][0],poly[2][0],poly[0][1],poly[1][1],poly[2][1],color);
	drawline(poly[0][1],poly[1][1],poly[2][1],poly[0][2],poly[1][2],poly[2][2],color);
	drawline(poly[0][2],poly[1][2],poly[2][2],poly[0][3],poly[1][3],poly[2][3],color);
	drawline(poly[0][3],poly[1][3],poly[2][3],poly[0][0],poly[1][0],poly[2][0],color);

	drawline(poly[0][4],poly[1][4],poly[2][4],poly[0][5],poly[1][5],poly[2][5],color);
	drawline(poly[0][5],poly[1][5],poly[2][5],poly[0][6],poly[1][6],poly[2][6],color);
	drawline(poly[0][6],poly[1][6],poly[2][6],poly[0][7],poly[1][7],poly[2][7],color);
	drawline(poly[0][7],poly[1][7],poly[2][7],poly[0][4],poly[1][4],poly[2][4],color);

	drawline(poly[0][0],poly[1][0],poly[2][0],poly[0][4],poly[1][4],poly[2][4],color);
	drawline(poly[0][1],poly[1][1],poly[2][1],poly[0][5],poly[1][5],poly[2][5],color);
	drawline(poly[0][2],poly[1][2],poly[2][2],poly[0][6],poly[1][6],poly[2][6],color);
	drawline(poly[0][3],poly[1][3],poly[2][3],poly[0][7],poly[1][7],poly[2][7],color);
	}
void print()
	{
	for(int i=0;i<4;i++)
		{
		for(int j=0;j<8;j++)
			cout<<" "<<poly[i][j];
		cout<<endl;
		}
	}
int main()
	{
	int gd=VGA,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);
	int choice;

	drawline(0,0,0,400,0,0,WHITE);
	drawline(0,0,0,0,300,0,WHITE);
	drawline(0,0,0,0,0,600,WHITE);


	display(GREEN);

	do
		{
		cout<<"Enter choice number for transformation"<<endl<<"1.rotation"<<endl<<"2.translation"<<endl<<"3.scaling"<<endl;
		cout<<"4.Reflection"<<endl<<"5.Shearing"<<endl<<"6.Exit"<<endl;
		cin>>choice;
		if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
			break;
		float l,m,n,theta,sx,sy,sz,tx,ty,tz,x1,y1,z1,a,b,x2,y2,z2,dx,dy,dz,rotz,roty,xp,yp,zp;
		int ch;

		switch(choice)
			{
			case 1: cout<<"Enter angle theta"<<endl;
				cin>>theta;
				theta=theta*acos(0)/90;
				cout<<"Enter line about which you want to rotate"<<endl;
				cin>> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
				dx=x2-x1;dy=y2-y1;dz=z2-z1;
				l=dx/sqrt(dx*dx+dy*dy+dz*dz);m=dy/sqrt(dx*dx+dy*dy+dz*dz);n=dz/sqrt(dx*dx+dy*dy+dz*dz);
				if(l==1 )
						{
						 initialize_rot(theta,'x');
						 matmul();
						 display(RED);
						 break;
						 }
				if(m==1)
						{
						initialize_rot(theta,'y');
						matmul();
						display(RED);
						break;
						}
				if(n==1)
						{
						initialize_rot(theta,'z');
						matmul();
						display(RED);
						break;
						}
					
				tx=x1-z1*l/n;
				ty=y1-z1*m/n;
				rotz=acos(dx/sqrt(dx*dx+dy*dy));roty=acos(dx/sqrt(dx*dx+dz*dz));
				drawline(x1,y1,z1,x2,y2,z2,WHITE);
				initialize_trans(-tx,-ty,0);
				matmul();
				initialize_rot(-rotz,'z');
				matmul();
				initialize_rot(-roty,'y');
				matmul();
				initialize_rot(theta,'x');
				matmul();
				initialize_rot(roty,'y');
				matmul();
				initialize_rot(rotz,'z');
				matmul();
				initialize_trans(tx,ty,0);
				matmul();
				display(RED);
				break;
			case 2: cout<<"Enter value of tx,ty and tz"<<endl;
				cin>>tx>>ty>>tz;
				initialize_trans(tx,ty,tz);
				matmul();
				display(RED);
				break;
			case 3: cout<<"Enter value of sx,sy and sz"<<endl;
				cin>>sx>>sy>>sz;
				cout<<"Enter point about which to scale"<<endl;
				cin>>x1>>y1>>z1;
				initialize_trans(-x1,-y1,-z1);
				matmul();
				initialize_scale(sx,sy,sz);
				matmul();
				initialize_trans(x1,y1,z1);
				matmul();
				display(RED);
				break;
			case 4: cout<<"Enter two points of line normal to the plane in which to reflect"<<endl;
				cin>>x1>>y1>>z1>>x2>>y2>>z2;
				cout<<"Enter x,y and z intercept of plane"<<endl;
				cin>>xp>>yp>>zp;
				dx=x2-x1;dy=y2-y1;dz=z2-z1;
				l=dx/sqrt(dx*dx+dy*dy+dz*dz);m=dy/sqrt(dx*dx+dy*dy+dz*dz);n=dz/sqrt(dx*dx+dy*dy+dz*dz);
				if(l==1)
					{
					initialize_trans(-xp,0,0);
					matmul();
					for(int i=0;i<8;i++)
						poly[0][i]=-poly[0][i];
					initialize_trans(xp,0,0);
					matmul();
					display(RED);
					break;
					}
				if(m==1)
					{
					initialize_trans(0,-yp,0);
					matmul();
					for(int i=0;i<8;i++)
						poly[1][i]=-poly[1][i];
					initialize_trans(0,yp,0);
					matmul();
					display(RED);
					break;
					}
				if(n==1){
					initialize_trans(0,0,-zp);
					matmul();
					for(int i=0;i<8;i++)
						poly[2][i]=-poly[2][i];
					initialize_trans(0,0,zp);
					matmul();
					display(RED);
					break;
					}	
				tx=x1-z1*l/n;
				ty=y1-z1*m/n;
				rotz=acos(dx/sqrt(dx*dx+dy*dy));roty=acos(dx/sqrt(dx*dx+dz*dz));
				drawline(x1,y1,z1,x2,y2,z2,WHITE);
				initialize_trans(-tx,-ty,0);
				matmul();
				initialize_rot(-rotz,'z');
				matmul();
				initialize_rot(-roty,'y');
				matmul();
				initialize_trans(-xp,0,0);
				matmul();
				for(int i=0;i<8;i++)
					poly[0][i]=-poly[0][i];
				initialize_trans(xp,0,0);
				matmul();
				initialize_rot(roty,'y');
				matmul();
				initialize_rot(rotz,'z');
				matmul();
				initialize_trans(tx,ty,0);
				matmul();
				display(RED);
				break;
			case 5: cout<<"Enter two shearing factors a and b"<<endl;
				cin>>a>>b;
				cout<<"Enter point about which to shear"<<endl;
				cin>>x1>>y1>>z1;
				cout<<"Enter axis along which to shear"<<endl;
				cin>>ch;
				initialize_trans(-x1,-y1,-z1);
				matmul();
				initialize_shear(a,b,ch+'x');
				matmul();
				initialize_trans(x1,y1,z1);
				matmul();
				display(RED);
				break;

			}

		}while(1);
	
	/*display(WHITE);
	initialize_shear(0.5,0.5,'y');
	matmul();
	print();
	display(GREEN);*/
	/*display(WHITE);
	initialize_trans(100,100,0);
	matmul();
	print();
	display(GREEN);*/
	/*display(WHITE);
	initialize_rot(45,'x');
	matmul();
	print();
	display(GREEN);*/
	/*display(WHITE);
	initialize_scale(2,2,2);
	matmul();
	print();
	display(GREEN);*/
	/*display(WHITE);
	float rotz,roty,xintercept,yintercept,l,m,n,dx,dy,dz,x1,y1,z1,x2,y2,z2;
	cin>>x1>>y1>>z1>>x2>>y2>>z2;
	dx=x2-x1;
	dy=y2-y1;
	dz=z2-z1;
	l=dx/sqrt(dx*dx+dy*dy+dz*dz);
	m=dy/sqrt(dx*dx+dy*dy+dz*dz);
	n=dz/sqrt(dx*dx+dy*dy+dz*dz);	
	xintercept=x1-z1*l/n;
	yintercept=y1-z1*m/n;
	rotz=acos(dx/sqrt(dx*dx+dy*dy));
	roty=acos(dx/sqrt(dx*dx+dz*dz));
	initialize_trans(-xintercept,-yintercept,0);
	matmul();
	initialize_rot(-rotz,'z');
	matmul();
	initialize_rot(-roty,'y');
	matmul();
	initialize_rot(acos(0)/2,'x');
	matmul();
	initialize_rot(roty,'y');
	matmul();
	initialize_rot(rotz,'z');
	matmul();
	initialize_trans(xintercept,yintercept,0);
	matmul();
	print();
	display(GREEN);*/
	
	
	getch();
	closegraph();
	cleardevice();
	return 0;
	}
