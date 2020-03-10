#include<iostream>
#include<graphics.h>
using namespace std;

class polygon
{
   public:
   void initialize();
   void scanline(int xx[10],int yy[10],int n);
};

void polygon::initialize()
{
   int gm,gd=DETECT;
   initgraph(&gd,&gm,NULL);
}

void polygon::scanline(int xx[10],int yy[10],int n)
{

   int i,k,inter_x[50],temp,y,ymax=0,ymin=480;
   
   float m[50],dx,dy;
   
   for(i=0;i<=n;i++)
    {
        if(yy[i]>=ymax)
           ymax=yy[i];
        if(yy[i]<=ymin)
           ymin=yy[i];
        
        dx=xx[i+1]-xx[i];
        dy=yy[i+1]-yy[i];
        
        if(dx==0)
          m[i]=0;
        if(dy==0)
          m[i]=1;
          
       if(dx!=0 && dy!=0)
         m[i]=dy/dx;
    }
    
    for(y=ymax;y>=ymin;y--)
     {
         int cnt=0;
           for(i=0;i<n;i++)
             {
                if(((yy[i]>y) && (yy[i+1]<=y))||((yy[i]<=y) && (yy[i+1]>y)))
                 {
                   inter_x[cnt]=(xx[i]+(m[i]*(y-yy[i])));
                   cnt++;
                 }
             }
     
     
     for(k=0;k<cnt-1;k++)
      {
         for(i=0;i<cnt-1;i++)
            {
               if(inter_x[i]>inter_x[i+1])
                 {
                    temp=inter_x[i];
                    inter_x[i]=inter_x[i+1];
                    inter_x[i+1]=temp;
                 }
            }
      }
      
      for(i=0;i<cnt-1;i++)
        {
            line(inter_x[i],y,inter_x[i+1],y);
            delay(100);
        }
    }
    getch();
}
int main()
{
   polygon p;
   
   int n,x[10],y[10];
   p.initialize();
   
   cout<<"ENTER THE NUMBER OF VERTICES\n";
   cin>>n;
   
   for(int i=0;i<=n-1;i++)
    {
        cout<<"ENTER THE COORDINATES OF point "<<(i+1)<<":";
        cin>>x[i];
        cin>>y[i];
        cout<<"\n";
   }
   
   //To draw polygon
   
   
   for(int i=0;i<n-1;i++)
   {
      line(x[i],y[i],x[i+1],y[i+1]);
   }
   line(x[0],y[0],x[n-1],y[n-1]);
   
   p.scanline(x,y,n);
   closegraph();
   getch();
   return 0;
 }
