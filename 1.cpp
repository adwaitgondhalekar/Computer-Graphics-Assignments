#include<graphics.h>
#include<iostream>

int main()
{

   int gd=DETECT,gm;
   initgraph(&gd,&gm,NULL);
   setcolor(9);
   //outtextxy(204.5,200,'inner Circle');
   rectangle(100,100,400,300);
   setcolor(2);
   line(100,200,250,100);
   line(100,200,250,300);
   line(250,300,400,200);
   line(400,200,250,100);
   setcolor(13);
   rectangle(175,150,325,250);
   setcolor(10);
   circle(250,200,50);
   setcolor(6);
   circle(250,200,180.27);
   delay(500000);
   closegraph();
   
}
