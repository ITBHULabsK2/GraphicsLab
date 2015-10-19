#include<iostream>
using namespace std;
#include<graphics.h>
#include<math.h>

#define round(a) (int)(a+0.5)
struct pts
{
	int x;
	int y;
}ctrl_pts[10],curve_pts[200];

void compute_coeff(int n,int *c)
{
	int k,i;
	for(k=0;k<=n;k++)
	{
		c[k]=1;
		for(i=n;i>=k+1;i--)
		c[k] *= i;
		for(i=n-k;i>=2;i--)
		c[k] /= i;
	}
}
 
void compute_point(float u,struct pts *point,int nctrls,int *c)
{
	int k,n=nctrls -1;
	float blend;
	
	point->x = 0;
	point->y= 0;
	
	for(k=0;k<nctrls;k++)
	{
		blend = c[k] * powf(u,k) * powf(1-u,n-k);
		point->x += (int)(ctrl_pts[k].x * blend);
		point->y += (int)(ctrl_pts[k].y * blend);
	}
}

int main()
{	
	int i,j,nctrls,m=200;
	char out[20];
	int gd = VGA,gm = VGAMAX;
	initgraph(&gd,&gm,"");
	int midx= getmaxx()/2;
	int midy= getmaxy()/2;
	cout<<"enter the number of control points..";
	cin>>nctrls;
	for(i=0;i<nctrls;i++)
	{
		cout<<endl<<"enter the x coord and y coord of "<< i+1 <<"th control point..";
		cin>>ctrl_pts[i].x >> ctrl_pts[i].y;
		sprintf(out,"(%d,%d)",ctrl_pts[i].x,ctrl_pts[i].y);
		outtextxy(midx + ctrl_pts[i].x,midy+ctrl_pts[i].y,out);
	}
	
		
	int *c = (int *) malloc (nctrls * sizeof(int));
	compute_coeff(nctrls-1, c);
	for(i=0;i<=m;i++)
		compute_point(i/(float) m ,&curve_pts[i],nctrls,c);
	
	for(i=0;i<m;i++)
		putpixel(round(midx + curve_pts[i].x),round(midy + curve_pts[i].y),6);
	getch();
	closegraph();
	cleardevice();
	


}

