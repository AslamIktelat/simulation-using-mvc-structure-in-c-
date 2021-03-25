#include "SimObj.h"

SimObj::SimObj(string name,float x,float y)
:name(name),x(x),y(y)
{
    //ctor
}

SimObj::~SimObj()
{
    //dtor
}
 string SimObj::GetName()
 {
   return name;
 }
pair<float,float> SimObj::Get_Location()
{
 return pair<float,float>(x,y);
}
void SimObj::Set_Location(float x,float y)
{
   this->x=x;
   this->y=y;
}
float SimObj::calculate_distance(pair<float,float> point)///the distance between the location of the simObj ,and point
{
 return sqrt( pow(x-point.first,2) + pow(y-point.second,2) );
}
void SimObj::Print_State()
{
   cout<<GetName()<<" ("<<x<<", "<<y<<"), ";
}
