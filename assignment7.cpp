#include<iostream>
#include<graphics.h>
using namespace std;

//Compute the bit code for a point (x,y) using the clip rectangle

//Bounded diagonally by (Xmin,Ymin) and (Xmax,Ymax)

//assume these are global constants

static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xl,yl,xh,yh;

int getcode(int x,int y)
{
   int code=0;
   //perform bitwise OR to get outcode
   
     if(y>yh)
     code |= TOP;
     
     if(y<yl)
     code |= BOTTOM;
     
     if(x<xl)
     code |= LEFT;
     
     if(x>xh)
     code |= RIGHT;
     
     return code;
}

int main()
{
    int gddriver=DETECT,gmode;
    initgraph(&gddriver,&gmode,NULL);
    
    setcolor(BLUE);
    
    cout<<"ENTER TOP LEFT & BOTTOM RIGHT COORDINATES OF THE WINDOW:\n";
    cin>>xl>>yl>>xh>>yh;
    
    rectangle(xl,yl,xh,yh);
    
    int x1,y1,x2,y2;
    
    cout<<"ENTER THE END POINTS OF LINE\n";
    cin>>x1>>y1>>x2>>y2;
    line(x1,y1,x2,y2);
    
    getch();
    
    int outcode1,outcode2;
    
    outcode1=getcode(x1,y1);
    outcode2=getcode(x2,y2);
    
    int accept=0;//decide if the line is to be drawn
    
    while(1)
    {
       cout<<"inside while\n";
       float m=(float)(y2-y1)/(x2-x1);
       //Both points inside accept line
       
       if(outcode1==0 && outcode2==0)
       {
          accept=1;
          break;
       }
       
       //AND of both codes!=0 then the line is outside reject it
       
       else if((outcode1 & outcode2)!=0)
       {
          break;
       }
       
       else
       {
       
          int x,y;
          int temp;
          
          //Decide if the point is inside if not calculate intersection
          
          if(outcode1==0)
            temp=outcode2;
          else
            temp=outcode1;
         //line clips top edge
         if(temp & TOP)
         {
           x=x1+(yh-y1)/m;
           y=yh;
         }        
         //line clips bottom edge
         else if(temp & BOTTOM)
         {
            x=x1+(yl-y1)/m;
            y=yl;
         }
         //line clips left edge
         else if(temp & LEFT)
         {
            x=xl;
            y=y1+m*(xl-x1);
         }
         //line clips right edge
         else if(temp & RIGHT)
         {
            x=xh;
            y=y1+m*(xh-x1);
         }
         
         
         //check which point we had selected earlier as temp and replace its coordinate
         if(temp == outcode1)
         {
            x1=x;
            y1=y;
            //cout<<x<<" "<<y<<endl;
            outcode1=getcode(x1,y1);
         }
         else
         {
            x2=x;
            y2=y;
            //cout<<x<<" "<<y<<endl;
            outcode2=getcode(x2,y2);
        }
      }
  }
  
  setcolor(WHITE);
  cout<<"After clipping\n";
  
  if(accept==1)
     //rectangle(xl,yl,xh,yh);
     line(x1,y1,x2,y2);
     
  getch();
  delay(5000);
  closegraph();
  
  return 0;
}

