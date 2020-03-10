#include<iostream>
#include<graphics.h>
#include<math.h>
#define max 10
#define PI 3.14159265

using namespace std;

class transformation
{
   
   public:
   double transmatrix[3][3];
   double scalingmatrix[3][3];
   double rotationmatrix[3][3];
   int tx,ty,sx,sy;
   double angle;
   int no_of_sides;
   double coordmatrix[max][3];
   double resultant[max][3];
   transformation(int s)
   {
      no_of_sides=s;
      
      for(int i=0;i<3;i++) 
         transmatrix[i][i] = 1;
 
      for(int i=0;i<no_of_sides;i++)
         coordmatrix[i][2]=1;
         
      for(int i=0;i<no_of_sides;i++)
          for(int j=0;j<3;j++)
             resultant[i][j]=0;
             
             transmatrix[0][1]=0;
      	     transmatrix[0][2]=0;
             transmatrix[1][0]=0;
             transmatrix[1][2]=0;
      
      for(int i=0;i<3;i++)
      {
         for(int j=0;j<3;j++)
          {
            scalingmatrix[i][j]=0;
            rotationmatrix[i][j]=0;
          }
       }
                  
   }
   void transform()
   {
       cout<<"ENTER THE TRANSFORMING FACTOR tx\n";
       cin>>tx;
       
       cout<<"ENTER THE TRANSFORMING FACTOR ty\n";
       cin>>ty;
       
       transmatrix[2][0]=tx;
       transmatrix[2][1]=ty;
       
       for(int i=0;i<no_of_sides;i++)
          {
             for(int j=0;j<3;j++)
                {
                   for(int k=0;k<3;k++)
                     {
                         
                         resultant[i][j]+=coordmatrix[i][k]*transmatrix[k][j];
                         
                     }
                }
          }
           for(int i=0;i<no_of_sides;i++)
          {
             for(int j=0;j<3;j++)
                {
                   cout<<resultant[i][j];
                }
             cout<<"\n";
          }
        setcolor(RED);
        for(int i=0;i<no_of_sides;i++)
        {  
           if(i!=no_of_sides-1)
               line(320+resultant[i][0],240-resultant[i][1],320+resultant[i+1][0],240-resultant[i+1][1]);
               else
               line(320+resultant[i][0],240-resultant[i][1],320+resultant[0][0],240-resultant[0][1]);
        }
                         
    }
    
    void scaling()
    {
       
        cout<<"ENTER THE SCALING FACTOR Sx\n";
        cin>>sx;
        
        cout<<"ENTER THE SCALING FACTOR Sy\n";
        cin>>sy;
        
        scalingmatrix[0][0]=sx;
        scalingmatrix[1][1]=sy;
        scalingmatrix[2][2]=1;
        
        for(int i=0;i<no_of_sides;i++)
          for(int j=0;j<3;j++)
             resultant[i][j]=0;
        
        
        
        for(int i=0;i<no_of_sides;i++)
          {
             for(int j=0;j<3;j++)
                {
                   for(int k=0;k<3;k++)
                     {
                         
                         resultant[i][j]+=coordmatrix[i][k]*scalingmatrix[k][j];
                         
                         
                     }
                }
          }
           for(int i=0;i<no_of_sides;i++)
          {
             for(int j=0;j<3;j++)
                {
                   cout<<resultant[i][j];
                }
             cout<<"\n";
          }
        setcolor(YELLOW);
        for(int i=0;i<no_of_sides;i++)
        {  
           if(i!=no_of_sides-1)
               line(320+resultant[i][0],240-resultant[i][1],320+resultant[i+1][0],240-resultant[i+1][1]);
               else
               line(320+resultant[i][0],240-resultant[i][1],320+resultant[0][0],240-resultant[0][1]);
        }
      }
      void rotation()
      {
          
          char rtype;
          cout<<"ROTATION IS COUNTER-CLOCKWISE?(y/n)\n";
          cin>>rtype;
          
          cout<<"ENTER THE ANGLE OF ROTATION\n";
          cin>>angle;
          
          //angle=((angle*(22/7))/180);
          
          if(rtype=='y'||rtype=='Y')
          {
            rotationmatrix[0][0]=cos(angle*(PI/180));
            rotationmatrix[0][1]=sin(angle*(PI/180));
            rotationmatrix[1][0]=-sin(angle*(PI/180));
            rotationmatrix[1][1]=cos(angle*(PI/180));
            rotationmatrix[2][2]=1;
          }
          else
          {
            rotationmatrix[0][0]=cos(angle*(PI/180));
            rotationmatrix[0][1]=-sin(angle*(PI/180));
            rotationmatrix[1][0]=sin(angle*(PI/180));
            rotationmatrix[1][1]=cos(angle*(PI/180));
            rotationmatrix[2][2]=1;
          }
          
          for(int i=0;i<no_of_sides;i++)
             for(int j=0;j<3;j++)
                resultant[i][j]=0;
        
        
        
        for(int i=0;i<no_of_sides;i++)
          {
             for(int j=0;j<3;j++)
                {
                   for(int k=0;k<3;k++)
                     {
                         
                         resultant[i][j]+=coordmatrix[i][k]*rotationmatrix[k][j];
                         
                         
                     }
                }
          }
           for(int i=0;i<no_of_sides;i++)
          {
             for(int j=0;j<3;j++)
                {
                   cout<<resultant[i][j];
                }
             cout<<"\n";
          }
        setcolor(GREEN);
        for(int i=0;i<no_of_sides;i++)
        {  
           if(i!=no_of_sides-1)
               line(320+resultant[i][0],240-resultant[i][1],320+resultant[i+1][0],240-resultant[i+1][1]);
               else
               line(320+resultant[i][0],240-resultant[i][1],320+resultant[0][0],240-resultant[0][1]);
        }
     }
             
            
};
    int main()
    {
        int gd=DETECT,gm;
        initgraph(&gd,&gm,NULL);
        
        int ch,l=0,sides;
        
        line(0,240,640,240);
        line(320,0,320,480);
        
        cout<<"ENTER THE NUMBER OF SIDES\n";
        cin>>sides;
        
        transformation obj(sides);
        
        for(int i=0;i<sides;i++)
        {
           int x1,y1;
           cout<<"ENTER COORDINATES OF POLYGON\n";
           cout<<"Point"<<(i+1)<<endl;
           cin>>x1>>y1;
           obj.coordmatrix[i][0]=x1;
           obj.coordmatrix[i][1]=y1;
           //line(x1,y1,x2,y2,RED);
        }
        
        for(int i=0;i<sides;i++)
          {
             for(int j=0;j<3;j++)
                {
                   cout<<obj.coordmatrix[i][j];
                }
             cout<<"\n";
          }
        setcolor(BLUE);
        
        for(int i=0;i<sides;i++)
            {
               if(i!=sides-1)
               line(320+(obj.coordmatrix[i][0]),240-(obj.coordmatrix[i][1]),320+(obj.coordmatrix[i+1][0]),240-(obj.coordmatrix[i+1][1]));
               else
               line(320+(obj.coordmatrix[i][0]),240-(obj.coordmatrix[i][1]),320+(obj.coordmatrix[0][0]),240-(obj.coordmatrix[0][1]));
               
            }
           
        
        while(l==0)
          {
                cout<<"1.POLYGON TRANSFORMATION\n";
                cout<<"2.POLYGON SCALING\n";
                cout<<"3.POLYGON ROTATION\n";
                cout<<"4.EXIT\n";
                cout<<"ENTER YOUR CHOICE\n";
                cin>>ch;
                
                switch(ch)
                { 
                      case 1:
                             
                                obj.transform();
                                break;
                             
                      case 2:  
                                obj.scaling();
                                break;       
                                
                      case 3:   obj.rotation();
                                break;
                      case 4: l=1;
                              closegraph();
                }
          }
          delay(5000);
          closegraph();
          return 0;
 }
 
