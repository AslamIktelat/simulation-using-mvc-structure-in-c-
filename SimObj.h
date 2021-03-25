#ifndef SIMOBJ_H
#define SIMOBJ_H
#include <string>
#include <utility>
#include <iostream>
#include <math.h>
using namespace std;

class SimObj
{ 
    public:
        SimObj(string name,float x,float y);
        virtual ~SimObj();
        string GetName();///return name
        pair<float,float> Get_Location();///return location
        void Set_Location(float x,float y);///set location
        float calculate_distance(pair<float,float> point);///distance from this object
        virtual void Update(int t)=0;///virtual 
        virtual void Print_State();///print name and location
    private:
        string name;
        float x,y;

};

#endif // SIMOBJ_H
