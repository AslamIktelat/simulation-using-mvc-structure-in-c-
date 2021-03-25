#include "chopper.h"

chopper::chopper(string name,float x,float y)
:Vehicle(name,x,y),attackR(2)
{
   Set_status(1);///stopped
   Set_speed(0);
}

chopper::~chopper()
{
    //dtor
}
void chopper::AddattackR(int i)
{
   attackR=attackR+i;
   if(attackR>20)
    attackR=20;
}
void chopper::course(float course,float speed)
{
   set_course(course);
   if(speed>170)
    Set_speed(170);
   else
    Set_speed(speed);
   Set_status(6);
}
void chopper::position(float x,float y,float speed)
{
  Set_Des(x,y);///set Des
  Set_speed(speed);///set speed
  Calculate_course();/// call Calculate_course to Calculate and set angle 
  Set_status(4);
}
void chopper::Update(int t)
{
    if(Get_status()!=1)///not stopped
    {
        if(Get_status()==6)///on course
        {
        cout<<"\n"<<"this is from Chopper     ";
            UpDate_Location(60);
        }
        else///heading to (x,y)
        {
            if(Get_Location()==Get_Destination())///arrived
                Set_status(1);///stopped
            else
            {
               UpDate_Location(60);
               
               }

        }

    }

}
void chopper::Print_State()
{
    cout<<"Chopper ";
    Vehicle::Print_State();
     switch(Get_status())
    {
    case 1:
        {
            cout<<"Stopped";
            break;
        }
    case 6:
        {
            cout<<"Heading on course "<<Get_Course();
            break;
        }
    case 4:
        {
            cout<<"Heading to ";
            Print_Des();
            break;
        }

    }
    cout<<" , speed "<<Get_speed()<<" km/h"<<"\n";


}
