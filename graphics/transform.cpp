 # include <iostream>
 using namespace std;
 # include <graphics.h>
 //# include<conio.h>
 # include<math.h>
 #include<stdio.h>
 void Polygon( int n, int coordinates[]);
 void reflection_x( int n,int coordinates[]);
 void reflection_y( int n,int coordinates[]);
 void multiply_matrices( int[3], int[3][3],int[3]);
 void translation(const int,int [],const int,const int);
 void apply_rotation(const int,int [],float);
 void multiply_matrices1(const float matrix_1[3],
 const float matrix_2[3][3],float matrix_3[3]);
 void apply_scaling(const int,int [],const float,const float);
 void shear(int,int [],float);
 
  void Line( int x_1, int y_1, int x_2, int y_2);

 
 int main( )
    {
     // int driver=VGA;
     // int mode=VGAHI;

    // initgraph(&driver,&mode,"..\\Bgi");
     int gdriver,gmode;
    gmode=VGAMAX; gdriver=VGA;
    initgraph(&gdriver,&gmode,"");
        
          line(320,100,320,400);

	  line(315,105,320,100);
	  line(320,100,325,105);

	  line(315,395,320,400);
	  line(320,400,325,395);

	  line(150,240,500,240);

	  line(150,240,155,235);
	  line(150,240,155,245);

	  line(500,240,495,235);
	  line(500,240,495,245); 
	  
	 // putpixel(320,240,14);
	  int n=5,xl,yl;
	  
	     int polygon_points[10]={ 30,30,30, 60,60, 60,60,30,30, 30};
	     int ch=0,c=0;
	     float theta,sx,sy,sh;
	  
	      Polygon(n,polygon_points);
	      
	    
	      
	      while(ch!=6)
	      {  
                  cout<<"enter your choice"<<endl;
                  cout<<"1 reflect"<<endl<<"2 translate"<<endl<<"3 rotate"<<endl<<"4 scaling"<<endl<<"5 shear"<<endl<<"6 Exit"<<endl;
                       cout<<"enter yout choice"<<endl;
	      		cin>>ch;
	      		if(ch==1)
	      		{
                   
                   		cout<<"x{1} or y(2)"<<endl;
                   		cin>>c;
                   		if(c==1)
                   		{
                   			reflection_x(n,polygon_points);
                   // Polygon(4,polygon_points);
                   		}
                   		if(c==2)
                   		{
                    			reflection_y(n,polygon_points);
                    // Polygon(4,polygon_points);
                    		}
          		}
          
          		if(ch==2)
          		{
                   
                  		 cout<<"enter xl,yl"<<endl;
                   		 cin>>xl>>yl;
                   		 translation(n,polygon_points,xl,yl);
                   
          		}   
          		if(ch==3)
          		{
                		cout<<"enter angle"<<endl;
                		cin>>theta;
                		apply_rotation(n,polygon_points,theta);   
                   
          		}   
          		if(ch==4)
          		{
                   
                  		 cout<<"enter sx sy"<<endl;
                  		 cin>>sx>>sy;
                    		apply_scaling(n,polygon_points,sx,sy);
          		}          
          
          		if(ch==5)
          		{
                   		cout<<"enter shear factor"<<endl;
                   		cin>>sh;
                   		shear(n,polygon_points,sh);
          		}
          
          
          }
          setcolor(13);
	   Polygon(5,polygon_points);   
	 // system("pause");
         getch();
         closegraph();
        cleardevice();
return 0;
	 //closegraph();
	  
       //return 0;
   }  





 void Line( int x_1, int y_1, int x_2, int y_2)
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

	     putpixel(x+320,240-y,color);

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

		   putpixel(x+320,240-y,color);
		}
		
	  }
	    else
	  {
	     int two_dx=(2*dx);
	     int two_dx_dy=(2*(dx-dy));
	     int p=((2*dx)-dy);

	     int x=x1;
	     int y=y1;

	     putpixel(x+320,240-y,color);

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

		   putpixel(x+320,240-y,color);
		}}
   }
   
    void apply_rotation(const int n,int coordinates[],float angle)
    {
       angle*=(M_PI/180);

       for(int count_1=0;count_1<n;count_1++)
	  {
	     float matrix_a[3]={coordinates[(count_1*2)],
					     coordinates[((count_1*2)+1)],1};
	     float matrix_b[3][3]={ { cos(angle),sin(angle),0 } ,
				    { -sin(angle),cos(angle),0 } ,
						      { 0,0,1 } };
	     float matrix_c[3]={0};

	     multiply_matrices1(matrix_a,matrix_b,matrix_c);

	     coordinates[(count_1*2)]=(int)(matrix_c[0]+0.5);
	     coordinates[((count_1*2)+1)]=(int)(matrix_c[1]+0.5);
	  }
    }
	  
 void reflection_x( int n,int coordinates[])
    {
       for(int count=0;count<n;count++)
	  {
	     int matrix_a[3]={coordinates[(count*2)],
					     coordinates[((count*2)+1)],1};
	     int matrix_b[3][3]={ {1,0,0} , {0,-1,0} ,{ 0,0,1} };
	     int matrix_c[3]={0};

	     multiply_matrices(matrix_a,matrix_b,matrix_c);

	     coordinates[(count*2)]=matrix_c[0];
	     coordinates[((count*2)+1)]=(matrix_c[1]);
	  }
    }

void reflection_y( int n,int coordinates[])
    {
       for(int count=0;count<n;count++)
	  {
	     int matrix_a[3]={coordinates[(count*2)],
					     coordinates[((count*2)+1)],1};
	     int matrix_b[3][3]={ {-1,0,0} , {0,1,0} ,{ 0,0,1} };
	     int matrix_c[3]={0};

	     multiply_matrices(matrix_a,matrix_b,matrix_c);

	     coordinates[(count*2)]=(matrix_c[0]);
	     coordinates[((count*2)+1)]=matrix_c[1];
	  }
    }



void Polygon( int n, int coordinates[])
    {
       if(n>=2)
	  {
	     Line(coordinates[0],coordinates[1],
				     coordinates[2],coordinates[3]);

	     for(int count=1;count<(n-1);count++)
		Line(coordinates[(count*2)],coordinates[((count*2)+1)],
					    coordinates[((count+1)*2)],
					    coordinates[(((count+1)*2)+1)]);
	  }
    }
void multiply_matrices( int matrix_1[3],
				   int matrix_2[3][3],int matrix_3[3])
    {
       for(int count_1=0;count_1<3;count_1++)
	  {
	     for(int count_2=0;count_2<3;count_2++)
		matrix_3[count_1]+=
			   (matrix_1[count_2]*matrix_2[count_2][count_1]);
	  }
    }
    
    void translation(const int n,int coordinates[],
						  const int Tx,const int Ty)
    {
       for(int count_1=0;count_1<n;count_1++)
	  {
	     int matrix_a[3]={coordinates[(count_1*2)],
					     coordinates[((count_1*2)+1)],1};
	     int matrix_b[3][3]={ {1,0,0} , {0,1,0} ,{ Tx,Ty,1} };
	     int matrix_c[3]={0};

	     multiply_matrices(matrix_a,matrix_b,matrix_c);

	     coordinates[(count_1*2)]=matrix_c[0];
	     coordinates[((count_1*2)+1)]=matrix_c[1];
	  }
    }
    void multiply_matrices1(const float matrix_1[3],
			       const float matrix_2[3][3],float matrix_3[3])
    {
       for(int count_1=0;count_1<3;count_1++)
	  {
	     for(int count_2=0;count_2<3;count_2++)
		matrix_3[count_1]+=
			   (matrix_1[count_2]*matrix_2[count_2][count_1]);
	  }
    }
 void apply_scaling(const int n,int coordinates[],
					      const float Sx,const float Sy)
    {
       for(int count_1=0;count_1<n;count_1++)
	  {
	     float matrix_a[3]={coordinates[(count_1*2)],
					     coordinates[((count_1*2)+1)],1};
	     float matrix_b[3][3]={ {Sx,0,0} , {0,Sy,0} ,{ 0,0,1} };
	     float matrix_c[3]={0};

	     multiply_matrices1(matrix_a,matrix_b,matrix_c);

	     coordinates[(count_1*2)]=(int)(matrix_c[0]+0.5);
	     coordinates[((count_1*2)+1)]=(int)(matrix_c[1]+0.5);
	  }
    }

void shear( int n,int coordinates[],float sh)
    {
       for(int count=0;count<n;count++)
	  {
	     float matrix_a[3]={coordinates[(count*2)],
					     coordinates[((count*2)+1)],1};
	     float matrix_b[3][3]={ {1,0,0} , {sh,1,0} ,{ 0,0,1} };
	     float matrix_c[3]={0};

	     multiply_matrices1(matrix_a,matrix_b,matrix_c);

	     coordinates[(count*2)]=(int)(matrix_c[0]);
	     coordinates[((count*2)+1)]=(int)matrix_c[1];
	  }
    }
