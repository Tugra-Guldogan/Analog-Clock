#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<time.h>
 
#define PI 3.147
 
void clockLayout();
void secHand();
void hrHand();
void minHand();
int maxx,maxy;
 
void main()
{
int gdriver=DETECT,gmode,error;
initgraph(&gdriver,&gmode,"c:\turboc3\bgi\");
error=graphresult();
if(error!=grOk)
{
  printf("Error in graphics, code= %d",grapherrormsg(error));
  exit(0);
}
 
while(1)
{
  clockLayout();
  secHand();
  minHand();
  hrHand();
  sleep(1);               
  cleardevice();           
}
}
 
void clockLayout()
{
int i,x,y,r;
float j;
maxx=getmaxx();
maxy=getmaxy();
 
for(i=1;i<5;i++)
{                  
  setcolor(YELLOW);
  circle(maxx/2,maxy/2,120-i);
}
 
pieslice(maxx/2,maxy/2,0,360,5);    
x=maxx/2+100;y=maxy/2;
r=100;
setcolor(BLUE);
 
for(j=PI/6;j<=(2*PI);j+=(PI/6))
{    
  pieslice(x,y,0,360,4);
  x=(maxx/2)+r*cos(j);
  y=(maxy/2)+r*sin(j);
}
 
x=maxx/2+100;y=maxy/2;
r=100;
setcolor(RED);
 
for(j=PI/30;j<=(2*PI);j+=(PI/30))
{  
  pieslice(x,y,0,360,2);
  x=(maxx/2)+r*cos(j);
  y=(maxy/2)+r*sin(j);
}
}
 
void secHand()
{
struct time t;
int r=80,x=maxx/2,y=maxy/2,sec;
float O;
 
maxx=getmaxx();maxy=getmaxy();
gettime(&t);                    
sec=t.ti_sec;
O=sec*(PI/30)-(PI/2);         
setcolor(YELLOW);
line(maxx/2,maxy/2,x+r*cos(O),y+r*sin(O));
}
 
void hrHand()
{
int r=50,hr,min;
int x,y;
struct time t;
float O;
 
maxx=getmaxx();
maxy=getmaxy();
x=maxx/2,y=maxy/2;
gettime(&t);                     
hr=t.ti_hour;
min=t.ti_min;
 
if(hr<=12)O=(hr*(PI/6)-(PI/2))+((min/12)*(PI/30));
if(hr>12) O=((hr-12)*(PI/6)-(PI/2))+((min/12)*(PI/30));
setcolor(BLUE);
line(maxx/2,maxy/2,x+r*cos(O),y+r*sin(O));
}
 
void minHand()
{
int r=60,min;
int x,y;
float O;
struct time t;
maxx=getmaxx();
maxy=getmaxy();
x=maxx/2;
y=maxy/2;
gettime(&t); 
min=t.ti_min;
O=(min*(PI/30)-(PI/2));
setcolor(RED);
line(maxx/2,maxy/2,x+r*cos(O),y+r*sin(O));
}
