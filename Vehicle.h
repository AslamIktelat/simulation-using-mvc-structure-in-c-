#ifndef VEHICLE_H
#define VEHICLE_H
#include "SimObj.h"
#include <math.h>
#include <utility>
using namespace std;
class Vehicle:public SimObj
{
    public:
        Vehicle(string name,float x,float y);
        virtual ~Vehicle();
        void Stop();///set status to 1 -status stop
        void Set_status(int s);///set status
        int Get_status();///return status
        void Set_speed(float s);///set speed
        float Get_speed();///return speed
        void Set_Des(float x,float y);///set destination by two float x y
        void Set_Des(pair<float,float> p);///set destination by pair of float
        pair<float,float> Get_Destination();
        void set_course(float c);///set course
        float Get_Course();///return angle
        void Print_Des();//print the destination
        void Calculate_course();///calculate -and set- the angle between the location point and the destination point
        void UpDate_Location(int minutes);///update location by speed and given time by minutes
        virtual void Update(int t)=0;

    protected:

    private:
        float speed,DesX,DesY,angle;
        int status;
};

#endif // VEHICLE_H
