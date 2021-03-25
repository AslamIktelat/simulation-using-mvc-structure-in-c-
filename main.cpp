
#include <iostream>
#include "controller.h"
#include <exception>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{


    controller con;
    bool exit=false;
    try{con.CopyDataFromFile(argv[1]);}
        catch(string e)
         {
             cerr<<e;
             exit=true;
         }
    for(int i=2;i<argc;i++)
    {
         
         try{con.AddTruckFromFile(argv[i]);}
        catch(string e)
         {
             cerr<<e;
             exit=true;
         }
        
    }
    string line;
    while(exit!=true)
    {
        start:
        cout<<"Time "<<con.GetTime()<<": Enter command:";
        cin>>line;

         if(line=="exit")
         {
              exit=true;
              break;///break the while
         }
         if(line=="stop")
          {
              con.stop();
              goto start;

          }

         if(line=="default")
         {
             con.Default();
             goto start;
         }

         if(line=="show")
         {
             con.show();
             goto start;
         }

         if(line=="status")
         {
             con.status();
             goto start;
         }

         if(line=="go")
         {
             con.go();
             goto start;
         }

              if(line=="size")
               {
                 int s;
                 cin>>s;
                 con.Size(s);
                 goto start;
                }
          if(line=="zoom")
          {
              int z;
             cin>>z;
             con.zoom(z);
            goto start;

          }
          if(line=="pan")
          {
             int x,y;
             cin>>x>>y;
             con.pan(x,y);
             goto start;
          }
          if(line=="create")
          {
              string name,kind,pos;
               cin>>name>>kind;
                getline(cin,pos);
               if(kind=="Chopper")
               {
                  
                    size_t f1=pos.find("(");
                    size_t f2=pos.find(",");
                    size_t f3=pos.find(")");
                   float x=stof(pos.substr(f1+1,f2)),y=stof(pos.substr(f2+2,f3));///f3-1
                  try{con.create(name,2,x,y,"");}
                  catch(string e){cerr<<e<<"\n";}
                   goto start;

               }
              if(kind=="State_trooper")
                {
                pos.erase (0,1);      
                   try{con.create(name,1,0,0,pos);}
                   catch(string e){cerr<<e<<"\n";}
                   goto start;
                }

          
                  
          }


         ///line has the name of the vehicle
         /// secWord has the command
         string secWord;
         cin>>secWord;
          if(secWord=="course")
          {
          float a=0,speed=0;
          string info,sa,sspeed;
          getline(cin,info);
          size_t found = info.find(" ");
          if (found!=string::npos)
          {
            a=stof(info,&found);
            info=info.substr(found);
          }
          found = info.find(" ");
          if (found!=string::npos)
          {
          speed=stof(info.substr(found+1));
          }
          con.course(line,a,speed);
              goto start;

          }
          
          if(secWord=="position")
          {
              string info;
              float x,y,speed=0;
              getline(cin,info);
              con.position(line,x,y,speed);
              goto start;

          }
          if(secWord=="destination")
          {
              string warehouseName;
              getline(cin,warehouseName);
              warehouseName.erase(0,1); 
              con.destination(line,warehouseName);
              goto start;

          }
          /*if(secWord=="attack")
          {
              goto start;

          }*/
          cerr<<"Wrong command"<<"\n";
          
    }///while

}
