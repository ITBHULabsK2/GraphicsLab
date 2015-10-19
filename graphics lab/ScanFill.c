#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



struct poly_edge
{
 int y2;
 float xintersect, dx;
 struct poly_edge *next;
};
typedef struct poly_edge EDGE;

struct pt
{
 int x, y;
};
typedef struct pt dcPt;

int main()
{
 int cnt, i, x, y;
 dcPt pts[100];
 int gdriver,gmode;
 gmode=VGAMAX; gdriver=VGA;
 initgraph(&gdriver,&gmode,"");
    
 printf("enter no. of vertices \n");
 scanf("%d",&cnt);
 
 printf("\nenter the vertices x and y coordinates");
 for(i=0;i<cnt;i++)
 {
  scanf("%d,%d", &x, &y);
  pts[i].x=x; pts[i].y=y;
 }
 
 for(i=0;i<cnt;i++)
 {
  printf("\n%d,%d\n", pts[i].x, pts[i].y);
 }

 scanFill(cnt, pts);
 getch();
 return 0;
}


void insertEdge(EDGE *list, EDGE *edge)
{
 EDGE *p, *q=list;
 p=q->next;
 while (p!=NULL)
 {
  if(edge->xintersect < p->xintersect)
    p=NULL;
  else
    {
     q=p;
     p=p->next;
    }
  }
  edge->next=q->next;
  q->next=edge;
}

int ynext(int k, int cnt, dcPt *pts)  /*error dcPt*/
{
 int j;
 if((k+1)>(cnt-1))
   j=0;
 else
   j=k+1;
 while(pts[k].y==pts[j].y)    /*error dcPt*/
   if((j+1)>(cnt-1))
     j=0;
   else
     j++;
 return(pts[j].y);
}

void makeEdgeRec(dcPt lower, dcPt upper, int yComp, EDGE *edge, EDGE *edges[])   /*error dcPt*/
{
 edge->dx = (float)(upper.x-lower.x)/(upper.y-lower.y);
 edge->xintersect = lower.x;
 if(upper.y<yComp)
   edge->y2=upper.y-1;
 else
   edge->y2=upper.y;
 insertEdge(edges[lower.y], edge);
}

void buildEdgeList(int cnt, dcPt *pts, EDGE *edges[])      /*error dcPt*/
{
 EDGE *edge;
 dcPt v1,v2;          /*error dcPt*/
 int i, yprev=pts[cnt-2].y;    /*error dcPt*/
 v1.x=pts[cnt-1].x; v1.y=pts[cnt-1].y;      /*error dcPt*/
 for(i=0; i<cnt; i++)
 {
  v2 = pts[i];    /*error dcPt*/
  if(v1.y != v2.y)
  {
   edge= (EDGE *)malloc(sizeof(EDGE));
   if(v1.y<v2.y)
     makeEdgeRec(v1, v2, ynext(i, cnt, pts), edge, edges);      /*error dcPt*/
   else
     makeEdgeRec(v2, v1, yprev, edge, edges);
  }
  yprev=v1.y;
  v1 = v2;
 }
}

void buildActiveList(int scan, EDGE *active, EDGE *edges[])
{
 EDGE *p, *q;
 p=edges[scan]->next;
 while(p)
 {
  p=q->next;
  insertEdge(active, p);
  p=q;
 }
}

void fillScan(int scan, EDGE *active)
{
 EDGE *p1, *p2;
 int i;
 p1=active->next;
 while(p1)
 {
  p2=p1->next;
  for(i=p1->xintersect; i<p2->xintersect; i++)
    putpixel((int)i, scan, 6);
  p1 = p2->next;
 }
}

void deleteAfter(EDGE *q)
{
 EDGE *p=q->next;
 q->next = p->next;
 free(p);
}

void updateActiveList(int scan, EDGE *active)
{
 EDGE *q=active, *p=active->next;
 while(p)
   if(scan>=p->y2)
   {
    p=p->next;
    deleteAfter(q);
   }
   else
   {
    p->xintersect = p->xintersect + p->dx;
    q=p;
    p=p->next;
   }
}

void resortActiveList(EDGE *active)
{
 EDGE *q, *p=active->next;
 active->next = NULL;
 while(p)
 {
  q=p->next;
  insertEdge(active, p);
  p = q;
 }
}

void scanFill(int cnt, dcPt *pts)         /*error dcPt*/
{
 int WINDOW_HEIGHT=getmaxx();

 EDGE *edges[WINDOW_HEIGHT], *active;        
 int i, scan;
 for(i=0; i<WINDOW_HEIGHT; i++)
 {
  edges[i] = (EDGE *)malloc(sizeof(EDGE));
  edges[i]->next = NULL;
 }
 buildEdgeList(cnt, pts, edges);   /*error dcPt*/
 active =  (EDGE *)malloc(sizeof(EDGE));
 active->next = NULL;
 for(scan=0; scan<WINDOW_HEIGHT; scan++)
 {
  buildActiveList(scan, active, edges);
  if(active->next)
  {
   fillScan(scan, active);
   updateActiveList(scan, active);
   resortActiveList(active);
  }
 }
}


    
