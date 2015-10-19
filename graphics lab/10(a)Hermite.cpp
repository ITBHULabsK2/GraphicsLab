#include<iostream>
#include<vector>
#include<graphics.h>
using namespace std;
int main()
	{	int gd=VGA,gm=VGAMAX,n,x1,y1,z1,xd1,yd1,zd1,x2,y2,z2,xd2,yd2,zd2;
		int hermite[4][4]={
					{2,-2,1,1},
					{-3,3,-2,-1},
					{0,0,1,0},
					{1,0,0,0}
				};
		int coeff[4][3];
		int coord[4][3];
		float plot[3];
		initgraph(&gd,&gm,NULL);
		int maxx=getmaxx(),maxy=getmaxy();
		cout<<"Enter number of control points"<<endl;
		cin>>n;
		//Enter the points in the order in which they are to be connected
		cout<<"Enter coordinates of n control points and their corresponding derivatives"<<endl;
		/*cin>>x1>>y1>>z1;
		cin>>xd1>>yd1>>zd1;*/
		cin>>coord[0][0]>>coord[0][1]>>coord[0][2];
		cin>>coord[2][0]>>coord[2][1]>>coord[2][2];
		for(int i=1;i<n;i++)
			{
			
			//cin>>x2>>y2>>z2>>xd2>>yd2>>zd2;
			cin>>coord[1][0]>>coord[1][1]>>coord[1][2];
			cin>>coord[3][0]>>coord[3][1]>>coord[3][2];
			for(int j=0;j<4;j++)
				for(int k=0;k<3;k++)
					{
					coeff[j][k]=0;
					for(int l=0;l<4;l++)
						coeff[j][k]+=hermite[j][l]*coord[l][k];
					}
			float up[4];
			for(float u=0;u<=1;u+=0.001)
				{
				up[0]=u*u*u;up[1]=u*u;up[2]=u;up[3]=1;
				for(int j=0;j<3;j++)
					{
					plot[j]=0;
					for(int k=0;k<4;k++)
						plot[j]+=up[k]*coeff[k][j];
					}
				putpixel(plot[0],plot[1],RED);
				}
			coord[0][0]=coord[1][0];coord[0][1]=coord[1][1];coord[0][2]=coord[1][2];
			coord[2][0]=coord[3][0];coord[2][1]=coord[3][1];coord[2][2]=coord[3][2];
			
			}
	getch();
	return 0;
	}
