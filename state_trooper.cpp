#include "state_trooper.h"

state_trooper::state_trooper(string name,map< string ,shared_ptr<Warehouse> > path,shared_ptr<Warehouse> FirstWarehouse)
:Vehicle(name,(FirstWarehouse->Get_Location()).first,(FirstWarehouse->Get_Location()).second),path(path),MovingTo(nullptr),FirstWarehouse(FirstWarehouse)
{
   Set_status(1);///stopped
   Set_speed(90);
   this->path.erase(FirstWarehouse->GetName());///delete from path the warehouse that visited
}

state_trooper::~state_trooper()
{
    //dtor
}
 void state_trooper::Update(int t)
 {
     if(Get_status()!=1)///not stopped
     {
         if(Get_status()==5)///heading to
         {
             if(Get_Location()==Get_Destination())///arrived at "MovingTo"
             {
                 if(path.size()==0)///the trooper is at the first warehouse
                    Set_status(1);///set status stop
                 else
                 {
                     NextWarehouse();///set-MovingTo- the next warehouse
                     UpDate_Location(60);
                 }

             }
             else///not arrived yet
             UpDate_Location(60);


         }
         if(Get_status()==4)///moving to (xy)
         {
                if(Get_Location()==Get_Destination())///arrived
                     Set_status(1);
                else
                UpDate_Location(60);

         }
         if(Get_status()==6)
            UpDate_Location(60);

     }

 }
void state_trooper::Print_State()
{
///print state by status
    cout<<"State_trooper ";
   Vehicle::Print_State();
  switch(Get_status())
    {
    case 1:
        {
            cout<<"Stopped";
            break;
        }
    case 4:
        {
            cout<<"Moving to ";
            Print_Des();
            break;
        }
    case 6:
        {
            cout<<"heading on course "<<Get_Course()<<" deg,";
            break;
        }
    case 5:
        {
             cout<<"Heading to "<<MovingTo->GetName();
            break;
        }
    }
    cout<<" speed 90.00 km/h"<<"\n";


}
void state_trooper::NextWarehouse()
{
      path.erase(MovingTo->GetName());///delete the warehouse which the state trooper visited
      float min_des=((path.begin())->second)->calculate_distance(Get_Location());
      shared_ptr<Warehouse> temp=FirstWarehouse;
      ///search for the next warehouse which its distant is the min
      for(auto it=path.begin();it!=path.end();it++)
      {
          float Min=(it->second)->calculate_distance(Get_Location());
        if(Min<min_des)
        {
            min_des=Min;
          temp=it->second;
        }

      }
      ///if the path.size = 0 then temp = FirstWarehouse which oint at the first warehouse
      ///set destination to the first warehouse the state trooper visited
      destination(temp);
}
 void state_trooper::destination(shared_ptr<Warehouse> MovingTo)
 {
     this->MovingTo=MovingTo;
     Set_status(5);///heading to
     Set_Des(MovingTo->Get_Location());///set destination point
     Calculate_course();///calculate and set angle between location and destination

 }
void state_trooper::course(float course)
{
    set_course(course);
    Set_status(6);///moving on course

}
void state_trooper::position(float x,float y)
{
 Set_Des(x,y);
 Set_status(4);
 Calculate_course();///calculate and set angle between location and destination

}
