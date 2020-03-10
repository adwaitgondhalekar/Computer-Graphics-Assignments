#include<iostream>
#include<graphics.h>
using namespace std;


class brecircle
{
   int xc,yc,xi,yi,r,Di,limit,d,d_;
   
   public:
    
   void mycircle(int ,int ,int );
   void mh();
   void md();
   void mv();
   void setpixel(int x,int y,int z)
   {
       putpixel(320+x,240-y,z);
   }
};

void brecircle::mycircle(int xc,int yc,int r)
{
   
    limit=0;
    
    xi=0;
    yi=r;
    Di=2*(1-r);
    
    while(yi>=limit)
     {
         delay(50);
         setpixel(xc+xi,yc+yi,RED);
         setpixel(xc+xi,yc-yi,BLUE);
         setpixel(xc-xi,yc-yi,RED);
         setpixel(xc-xi,yc+yi,BLUE);
         
         if(Di<0)
         {
            d=((2*Di)+(2*yi)-1);
            
            if(d<=0)
             mh();
             
            else
             md();
          }
     else if(Di>0)
          {
            d_=((2*Di)-(2*xi)-1);
            
            if(d_<=0)
             md();
             else
             mv();
          }
       else if(Di==0)
           md();
         }
 }
 
 void brecircle::mh()
 {
    xi=xi+1;
    Di=Di+(2*xi)+1;
 }
 
 void brecircle::mv()
 {
 
    yi=yi-1;
    Di=Di-(2*yi)+1;
 }
 
 void brecircle::md()
 {
   xi=xi+1;
   yi=yi-1;
   Di=Di+(2*xi)-(2*yi)+2;
 }
 
 int main()
 {
    brecircle c;
    int Xc,Yc,R;
    
    //float Xc,Yc,R;
    int gd=DETECT,gm;
    
    cout<<"ENTER THE COORDINATES OF CENTER OF THE CIRCLE\n";
    cin>>Xc>>Yc;
    
    cout<<"ENTER THE RADIUS OF THE CIRCLE\n";
    cin>>R;
    
    initgraph(&gd,&gm,NULL);
    line(0,240,640,240);
    line(320,0,320,480);
    c.mycircle(Xc,Yc,R);
    delay(5000);
    closegraph();
}
    
    
