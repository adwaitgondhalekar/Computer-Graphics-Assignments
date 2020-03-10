#include<iostream>
#include<cstdlib>
#include<graphics.h>
using namespace std;

class pixel
{

   public:
   void setpixel(int x,int y);
   
};

class lined:public pixel
{
     public:
   
    float dx,dy;
    int s1,s2,interchange_flag,e_;
    void dda();
    void bressenham(int x1,int y1,int x2,int y2);
    int sign(int diff);
};

int lined::sign(int diff)
{

   if(diff>0)
     return 1;
   else if(diff<0)
     return -1;
    else
      return 0;
}
void pixel::setpixel(int x,int y)
{

    putpixel(x,y,15);
}



void lined::bressenham(int x1,int y1,int x2,int y2)
{
 
     dx=abs(x2-x1);
     dy=abs(y2-y1);
     
     float x=x1;
     float y=y1;
     
     s1=sign(x2-x1);
     s2=sign(y2-y1);
 
     if(dy>dx)
       {
          int temp=dx;
          dx=dy;
          dy=temp;
          interchange_flag=1;
       }
       else
          interchange_flag=0;
          
       
     e_=(2*dy)-dx;
     
     for(int i=1;i<=dx;i++)
       {
          
          setpixel(320+x,240-y);
          while(e_>0)
            {
              if(interchange_flag==1)
                 x=x+s1;
              else
                 y=y+s2;
              
              e_=e_-(2*dx);
            }
            
         if(interchange_flag==1)
           y=y+s2;
         else
           x=x+s1;
           
       e_=e_+(2*dy);
       
       delay(5);
      }
 }
       
int main()
{

     int gd=DETECT,gm;
     initgraph(&gd,&gm,NULL);
     line(320,0,320,480);
     line(0,240,640,240);
     lined obj;
     
    
   int l=0,ch;
       while(l==0)
              {
                     cout<<"1.PATTERN\n";
                     cout<<"2.EXIT\n";
                     cout<<"ENTER YOUR CHOICE\n";
                     cin>>ch;
                     switch(ch)
                         {
                                case 1:  {
                                          
                                           obj.bressenham(-100,100,100,100);
                                           obj.bressenham(100,100,100,-100);
                                           obj.bressenham(100,-100,-100,-100);
                                           obj.bressenham(-100,-100,-100,100);
                                           
                                           obj.bressenham(0,100,100,0);
                                           obj.bressenham(100,0,0,-100);
                                           obj.bressenham(0,-100,-100,0);
                                           obj.bressenham(-100,0,0,100);
                                           obj.bressenham(-50,50,50,50);
                                           obj.bressenham(50,50,50,-50);
                                           obj.bressenham(50,-50,-50,-50);
                                           obj.bressenham(-50,-50,-50,50);
                                           
                                          
                                         break;
                                          }
                                          
                                case 2:  l=1;
                                         closegraph();
                                         break;         
                         }
               }
               delay(5000);
               closegraph();
               
}

