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
    float x1,x2,y1,y2,xnew,ynew;
    float dx,dy,steps;
    int s1,s2,interchange_flag,e_;
    void dda();
    void bressenham();
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

void lined::dda()
{
     int ctr=0;
     dx=x2-x1;
     dy=y2-y1;
     
     if(abs(dx)>abs(dy))
        steps=abs(dx);
     else
        steps=abs(dy);
        
       xnew=dx/steps;
       ynew=dy/steps;
       float x=x1;
       float y=y1;
       
       setpixel(320+x1,240-y1);
      
     while(ctr<steps)
     {
        
           x+=xnew;
           y+=ynew;
    
       setpixel(320+x,240-y);
           
           ctr++;
           delay(100);
     }
}        

void lined::bressenham()
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
       
       delay(100);
      }
 }
      
      
     
   
          
int main()
{

     int gd=DETECT,gm;
     initgraph(&gd,&gm,NULL);
     line(320,0,320,480);
     line(0,240,640,240);
     lined obj;
     cout<<"ENTER THE COORDINATES OF THE STARTING POINT\n";
     cout<<"x1="<<endl;
     cin>>obj.x1;
     cout<<"y1="<<endl;
     cin>>obj.y1;
     cout<<"ENTER THE COORDINATES OF THE END POINT\n";
     cout<<"x2="<<endl;
     cin>>obj.x2;
     cout<<"y2="<<endl;
     cin>>obj.y2;
     
     
   int l=0,ch;
       while(l==0)
              {
                     cout<<"1.DDA LINE DRAWING\n";
                     cout<<"2.BRESSENHAMS LINE DRAWING\n";
                     cout<<"3.EXIT\n";
                     cout<<"ENTER YOUR CHOICE\n";
                     cin>>ch;
                     
                     
                     switch(ch)
                         {
                                case 1:  obj.dda();
                                         break;
                                          
                                case 2:  obj.bressenham();
                                         break;          
                                          
                                case 3: l=1;
                                        closegraph();
                                        break;
                                         
                         }
               }
               delay(5000);
               closegraph();
               
}
