#include "Vehicle.h"

Vehicle::Vehicle(string name,float x,float y)
:SimObj(name,x,y)
{
    //ctor
}

Vehicle::~Vehicle()
{
    //dtor
}
void Vehicle::Set_status(int s)
{
  status=s;
}
int Vehicle::Get_status()
{
  return status;
}
void Vehicle::Stop()
{
  status=1;
}
void Vehicle::Set_speed(float s)
{
  speed=s;
}
void Vehicle::Set_Des(float x,float y)
{
  DesX=x;
  DesY=y;
}
void Vehicle::Set_Des(pair<float,float> p)
{
  Set_Des(p.first,p.second);
}
void Vehicle::set_course(float c)
{
 angle=c;
}
 void Vehicle::UpDate_Location(int minutes)
 {
 ///update the location by the speed ,angle ,and the time that passed by minutes 
        float Sx,Sy;
        float t=minutes/60;
        Sx=sin(angle*(3.14159265/180.0))*speed;///speed on x axis
        Sy=cos(angle*(3.14159265/180.0))*speed;///speed on y axis
        pair <float,float> p=Get_Location();
        float Sxx,Syy;
        Sxx=Sx*t;
        Syy=Sy*t;
        Set_Location(p.first+Sx,p.second+Sy);

 }
void Vehicle::Calculate_course()
{
 ///calculate the angle between the vector of
 // the location and the  destination
    float dot,len;
    pair <float,float> p=Get_Location();
    dot=p.first*DesX+p.second*DesY;
    len=sqrt (pow(p.first,2)+pow(p.second,2));
    len=len*sqrt(pow(DesX,2)+pow(DesY,2));
    angle=acos(dot/len);
}
 pair<float,float> Vehicle::Get_Destination()
 {
   return pair<float,float> (DesX,DesY);
 }
float Vehicle::Get_Course()
{
   return angle;
}
float Vehicle::Get_speed()
{
   return speed;
}
void Vehicle::Print_Des()
{
cout<<"("<<DesX<<","<<DesY<<")";
}
