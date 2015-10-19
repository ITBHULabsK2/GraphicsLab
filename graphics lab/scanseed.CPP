#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<iostream.h>
#include<process.h>
#include<graphics.h>
void seedfill(int x,int y,int fill,int bound);
typedef struct node{
	    int x,y;
	    struct node *next;
	    }*ptr;
class stack{
	    public:
		 int no;
		 struct node *top,*null;
		 void push(int i,int j);
		 ptr pop();
		 ptr getnode();
		 void freenode(ptr p);
		 int isempty();
		 stack(void){top=null;no=0;};
	      };
void stack::push(int i,int j)
{       ptr p=top;
	  if(top==null){ top=getnode();top->next=null;top->x=i;top->y=j;no++;}
	else{
	top->next=getnode();
	top=top->next;
	top->x=i;top->y=j;
	top->next=p;no++;
       }
 }

ptr stack::getnode(void)
{
  ptr p;
  p=(ptr) malloc(sizeof(struct node));
  return(p);
}

ptr stack::pop(void)
{    ptr p;
	 if(top==null){
	 cout<<"\n there are no elements in the stack";
	 _cexit();}
  else{ if(no==2){p=top; top=top->next;top->next=null;no--;return(p);}
       else{p=top; top=top->next;no--;return(p);}
  }
 }

 int stack::isempty()
 {
	if(top==null)return(1);else{ return(0);}
 }
 void main()
 {     	int gd=DETECT,gm,i,x,y,k,h,r;
	initgraph(&gd,&gm,"C:\\TC\\bgi");
	setcolor(GREEN);
	cout<<"enter the chioce";
	cin>>i;
	switch(i){
	case 1:
	       cout<<"circle\n";
	      cout<<"enter the radius and centre of the circle........";
	      cin>>r>>x>>y;
	      circle(x,y,r);
	      seedfill(x,y,BLUE,GREEN);
	      break;
	case 2:

	      cout<<"enter the coordinates of polygon..............";
	      cin>>x>>y>>h>>k;
	      rectangle(x,y,h,k);
	      seedfill((x+h)/2,(y+k)/2,BLUE,GREEN);
	      break;
	default :
	      cout<<"enter the correct choice" ;

	 }
	getch();
	closegraph();
	}
  void seedfill(int x,int y,int fill,int bound)
  {
	stack st;ptr p;
	st.push(x,y);

	while(st.isempty()==0)
	{
	  p=st.pop();
	  int current=getpixel(p->x,p->y);
	  if((current!=fill)&&(current!=bound))
	  putpixel(p->x,p->y,fill);
	  int m=p->x,n=p->y;
	  while(getpixel(m+1,n)!=fill&&(getpixel(m+1,n)!=bound))
	  {
		putpixel(m+1,n,fill);
		m++;
	  }
	  m=p->x;n=p->y;
	  while(getpixel(m-1,n)!=fill&&(getpixel(m-1,n)!=bound))
	  {
		putpixel(m-1,n,fill);
		m--;
	  }
	 if((getpixel(p->x,p->y+1)!=fill)&&(getpixel(p->x,p->y+1)!=bound))
	 { st.push(p->x,p->y+1);}
	 if((getpixel(p->x,p->y-1)!=fill)&&(getpixel(p->x,p->y-1)!=bound))
	 { st.push(p->x,p->y-1); }
	  } return;
       }