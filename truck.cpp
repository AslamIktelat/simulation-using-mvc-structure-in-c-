#include "truck.h"

truck::truck(string name ,float x,float y,int crates)
:Vehicle(name,x,y),crates(crates),indexP(0),f(true)
{
    //ctor
}

truck::~truck()
{
    //dtor
}
void truck::Update(int t)
{
    
  if( Get_status()!= 1 && Get_status()!= 3 )///if its not off road or stopped
  {
      if(Get_status()==2)///parked in warehouse
      {
            string departureT=path[indexP].departureT;
            if(time_compare(t,departureT)==1)///time to move to the next warehouse
            {
                if(indexP==path.size()-1)///End of path, no more warehouses to move to
                    Stop();
                else
                {
                     Set_status(5);///heading to the next warehouse
                     float dis=(path[indexP].wp)->calculate_distance((path[indexP+1].wp)->Get_Location());///calculate the distance between the warehouse the truck parked in to the next warehouse
                     Set_Des((path[indexP+1].wp)->Get_Location());///set the destination of the truck to the next warehouse
                    Calculate_course();///calculate -and set- the angel between the location point and the destination point
                    int time=minutes(path[indexP].departureT,path[indexP+1].arrivalT)/60.0;
                    Set_speed((dis*100)/time);
                    f=true;

                }

            }
      }
      if(Get_status()==5)///heading to warehouse
      {
         cout<<"\n"<<"indexP:"<<indexP<<"\n";

          string arrivalT=path[indexP].arrivalT;
           if(time_compare(t,arrivalT)!=1)///still on the road
           {
                if(f)///if the this the first time we call update location
                {
                     UpDate_Location(minutes(path[indexP].departureT,t));
                     indexP++;
                     f=false;

                }
                else
                UpDate_Location(60);


           }
           else///arrived to warehouse
           {
               indexP++;
               Set_status(2);
               f=true;
            (path[indexP].wp)->Update(path[indexP].caseQ);///update the warehouse
               crates=crates-path[indexP].caseQ;///update the truck crates
               ///parked at warehouse at the index indexP
           }

      }

  }
}
void truck::Print_State()
{
    cout<<"Truck ";
    SimObj::Print_State();
    switch(Get_status())
    {
    case 1:
        {
            cout<<"Stopped";
            break;
        }
    case 2:
        {
            cout<<"Parked at "<<(path[indexP].wp)->GetName();
            break;
        }
    case 3:
        {
            cout<<"Off road";
            break;
        }
    case 5:
        {
             cout<<"Heading to "<<(path[indexP+1].wp)->GetName();
            break;
        }
    }
    cout<<" , Crates: "<<crates<<"\n";

}
void truck::AddToPath(shared_ptr<Warehouse> wp,string arrivalT,int caseQ,string departureT)
{
info in;///info struct
//set the fields of the struct
in.wp=wp;
in.arrivalT=arrivalT;
in.caseQ=caseQ;
in.departureT=departureT;
path.push_back(in);///push back to path
if(path.size()==2)
{
   Set_Des(wp->Get_Location());
   Calculate_course();
    (path[indexP].wp)->Update(crates);///update the warehouse
   Set_status(5);///heading to warehouse at index indexP+1
}
}
int truck::time_compare(int time,string str1)
{
cout<<"\n"<<"this is time_compare(int time,string str1) time:"<<time<<" str1:"<<str1<<" res:";
    ///t>st return 1
    ///t= st return 0
    ///else return -1
  int hour1,minute1;
	  int time1,time2;
	   sscanf(str1.c_str(), "%d:%d",&hour1,&minute1);
	   time1=(hour1*60)+minute1;
	   time2 = time*60;
	   if(time1>time2) {cout<<"1"<<"\n"; return 1;}
	   else if(time2>time1) {cout<<"-1"<<"\n"; return -1;}
	   {cout<<"0"<<"\n"; return 0;}
}
int truck::minutes(string str1,string str2)
{
cout<<"\n"<<"this is minutes(string str1,string str2) str1:"<<str1<<" str2:"<<str2<<" res:";
    ///t2>t1
   int hour1,hour2,minute1,minute2;
	  int time1,time2;
	   sscanf(str1.c_str(), "%d:%d",&hour1,&minute1);
	   sscanf(str2.c_str(), "%d:%d",&hour2,&minute2);
	   time1 = (hour1*60)+minute1;
	   time2 = (hour2*60)+minute2;
        cout<<time2-time1<<"\n";
	   return time2-time1; 
}
int truck::minutes(string str1,int time)
{
cout<<"\n"<<"this is minutes(string str1,int time) str1:"<<str1<<" time:"<<time<<" res:";
    ///t2>t1
  int hour1,minute1;
	  int time1,time2;
	   sscanf(str1.c_str(), "%d:%d",&hour1,&minute1);
	   time1=(hour1*60)+minute1;
	   time2 = time*60;
       cout<<time2-time1<<"\n";
	   return time2-time1;
}
