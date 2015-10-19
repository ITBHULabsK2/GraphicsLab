
 # include <iostream>
 using namespace std;
 # include <graphics.h>
 //# include    <conio.h>
 # include     <math.h>

int xc,yc,zc;

 void draw_cube(int [8][3]);
 void draw_pyramid(int [5][3]);
 void get_projected_point(int&,int&,int&);
 void multiply_matrices(const float[4],const float[4][4],float[4]);

 void Line(const int,const int,const int,const int);


 int main( )
    {
       int driver=VGA;
       int mode=VGAHI;

       initgraph(&driver,&mode,"..\\Bgi");



cout<<"enter xc yc zc";
cin>>xc>>yc>>zc;
       int cube[8][3]={
			 {370,200,50},      
			 {470,200,50},      
			 {470,300,50},      
			 {370,300,50},     
			 {370,200,10},     
			 {470,200,10},     
			 {470,300,10},     
			 {370,300,10}     
		      };

       setcolor(6);
	 draw_cube(cube);
       getch( );
       closegraph( );
       return 0;
    }

 void draw_cube(int edge_points[8][3])
    {
       for(int i=0;i<8;i++)
	  get_projected_point(edge_points[i][0],
				     edge_points[i][1],edge_points[i][2]);

       	 Line(edge_points[0][0],edge_points[0][1],
				     edge_points[1][0],edge_points[1][1]);
	 Line(edge_points[1][0],edge_points[1][1],
				     edge_points[2][0],edge_points[2][1]);
	 Line(edge_points[2][0],edge_points[2][1],
				     edge_points[3][0],edge_points[3][1]);
	 Line(edge_points[3][0],edge_points[3][1],
				     edge_points[0][0],edge_points[0][1]);
	 Line(edge_points[4][0],edge_points[4][1],
				     edge_points[5][0],edge_points[5][1]);
	 Line(edge_points[5][0],edge_points[5][1],
				     edge_points[6][0],edge_points[6][1]);
	 Line(edge_points[6][0],edge_points[6][1],
				     edge_points[7][0],edge_points[7][1]);
	 Line(edge_points[7][0],edge_points[7][1],
				     edge_points[4][0],edge_points[4][1]);
	 Line(edge_points[0][0],edge_points[0][1],
				      edge_points[4][0],edge_points[4][1]);
	 Line(edge_points[1][0],edge_points[1][1],
				      edge_points[5][0],edge_points[5][1]);
	 Line(edge_points[2][0],edge_points[2][1],
				      edge_points[6][0],edge_points[6][1]);
	 Line(edge_points[3][0],edge_points[3][1],
				      edge_points[7][0],edge_points[7][1]);
}

 void get_projected_point(int& x,int& y,int& z)
    {
       x=(int)(xc-(x-xc)/(z-zc)*zc);
       y=(int)(yc-(y-yc)/(z-zc)*zc);
       z=0;
    }

 void Line(const int x_1,const int y_1,const int x_2,const int y_2)
    {
       int color=getcolor( );

       int x1=x_1;
       int y1=y_1;

       int x2=x_2;
       int y2=y_2;

       if(x_1>x_2)
	  {
	     x1=x_2;
	     y1=y_2;

	     x2=x_1;
	     y2=y_1;
	  }

       int dx=abs(x2-x1);
       int dy=abs(y2-y1);
       int inc_dec=((y2>=y1)?1:-1);

       if(dx>dy)
	  {
	     int two_dy=(2*dy);
	     int two_dy_dx=(2*(dy-dx));
	     int p=((2*dy)-dx);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(x<x2)
		{
		   x++;

		   if(p<0)
		      p+=two_dy;

		   else
		      {
			 y+=inc_dec;
			 p+=two_dy_dx;
		      }

		   putpixel(x,y,color);
		}
	  }

       else
	  {
	     int two_dx=(2*dx);
	     int two_dx_dy=(2*(dx-dy));
	     int p=((2*dx)-dy);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(y!=y2)
		{
		   y+=inc_dec;

		   if(p<0)
		      p+=two_dx;

		   else
		      {
			 x++;
			 p+=two_dx_dy;
		      }

		   putpixel(x,y,color);
		}
	  }
    }

