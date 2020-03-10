#include<graphics.h>
#include<iostream>

int main()
{
   int gd=DETECT,gm;
   
   initgraph(&gd,&gm,NULL);
   setcolor(YELLOW);
   circle(320,240,60);
   line(260,240,264,240);
   outtextxy(266,236,"9");
   line(376,240,380,240);
   outtextxy(368,236,"3");
   line(320,300,320,296);
   outtextxy(315,285,"6");
   line(320,180,320,184);
   outtextxy(312,184,"12");
   outtextxy(346,190.04,"1");
   outtextxy(363.96,210,"2");
   outtextxy(361.96,265,"4");
   outtextxy(344,280.96,"5");
   outtextxy(288,190.04,"11");
   outtextxy(268.04,210,"10");
   outtextxy(272.04,265,"8");
   outtextxy(288.08,280.96,"7");
   putpixel(320,240,YELLOW);
   line(320,240,320,270);
   delay(50000);
   
   closegraph();
   
   //cleardevice(); 
   
   
   
   }
   
   
   
