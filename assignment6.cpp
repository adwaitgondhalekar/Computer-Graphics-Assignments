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
   
    float dx,dy,steps,xnew,ynew,wx,wy;
    int s1,s2,interchange_flag,e_;
    void dda(int x1,int y1,int x2,int y2);
    //void bressenham(int x1,int y1,int x2,int y2);
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



void lined::dda(int x1,int y1,int x2,int y2)
{

     int ch,w;
     cout<<"1.DOTTED LINE\n";
     cout<<"2.DASHED LINE\n";
     cout<<"3.DASH-DOT LINE\n";
     cout<<"4.THICK LINE\n";
     cout<<"5.SOLID LINE\n";
     cout<<"ENTER YOUR CHOICE\n";
     cin>>ch;
     
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
       
       switch(ch)
       {
            case 1:     
            
                       
                        for(int i=0;i<=steps;i++)
                           {
                                 if(i%3==0)
                                  setpixel(320+x,240-y);
                                  
                                  delay(100);
                                  
                                  x=x+xnew;
                                  y=y+ynew;
                           }
                           
                           break;
            case 2:
                       
                        for(int i=0;i<=steps;i++)
                           {
                                 if(i%5!=0)
                                  setpixel(320+x,240-y);
                                  
                                  delay(100);
                                  
                                  x=x+xnew;
                                  y=y+ynew;
                           }
                           
                           break;
            case 3:
                       for(int i=0;i<=steps;i++)
                           {
                                 if(i%5!=0)
                                  setpixel(320+x,240-y);
                                 else
                                  {
                                   x=x+xnew;
                                   y=y+ynew;
                                   setpixel(320+x,240-y);
                                    x=x+xnew;
                                    y=y+ynew;
                                   }
                                  
                                  delay(100);
                                  
                                  x=x+xnew;
                                  y=y+ynew;
                           }
                           
                           break;
            case 4:  {
                        cout<<"ENTER THE WIDTH OF THE THICK LINE\n";
                        cin>>w;
                        int l=0;
                        if(abs(dx)>abs(dy))
                          {
                             wy=((w-1)/2)*(pow(pow((pow(x2-x1,2))+(pow(y2-y1,2)),2),0.5))/(pow(x2-x1,2));
                             x=x1;
                             y=y1-wy;
                             while(l!=w)
                             {
                           
                             for(int i=0;i<=steps;i++)
                               {
                                
                                  setpixel(320+x,240-y);
                                  
                                  delay(100);
                                  
                                  x=x+xnew;
                                  y=y+ynew;
                              }
                               l++;
                               x=x1;
                               y=(y1-wy)+l;
                             
                             }
                          }
                        else
                          {
                             wx=((w-1)/2)*(pow(pow((pow(x2-x1,2))+(pow(y2-y1,2)),2),0.5))/(pow(y2-y1,2));
                             x=x1-wx;
                             y=y1;
                             while(l!=w)
                             {
                           
                             for(int i=0;i<=steps;i++)
                               {
                                
                                  setpixel(320+x,240-y);
                                  
                                  delay(100);
                                  
                                  x=x+xnew;
                                  y=y+ynew;
                              }
                               l++;
                               y=y1;
                               x=(x1-wx)+l;
                             
                             }
                          }
                         }   
                          
                case 5:   for(int i=0;i<=steps;i++)
                           {
                                
                                  setpixel(320+x,240-y);
                                  
                                  delay(100);
                                  
                                  x=x+xnew;
                                  y=y+ynew;
                           }
                           
                           break;          
                         
                        
                        
                        
       }
       
      
   
}        

       
int main()
{

     int gd=DETECT,gm;
     initgraph(&gd,&gm,NULL);
     line(320,0,320,480);
     line(0,240,640,240);
     lined obj;
     int x1,x2,y1,y2;
     
    
   int l=0,ch;
       while(l==0)
              {
                     cout<<"1.LINE DRAWING(BRESSENHAMS)\n";
                     cout<<"2.EXIT\n";
                     cout<<"ENTER YOUR CHOICE\n";
                     cin>>ch;
                     switch(ch)
                         {
                                case 1:  {
                                          cout<<"ENTER STARTING COORDINATES\n";
                                          cout<<"X1:";
                                          cin>>x1;
                                          cout<<"Y1:";
                                          cin>>y1;
                                          cout<<"X2:";
                                          cin>>x2;
                                          cout<<"Y2:";
                                          cin>>y2;
                                          
                                          obj.dda(x1,y1,x2,y2);
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
