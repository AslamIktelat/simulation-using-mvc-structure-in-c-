#ifndef CHOPPER_H
#define CHOPPER_H
#include "Vehicle.h"

class chopper:public Vehicle
{
    public:
        chopper(string name,float x,float y);
        virtual ~chopper();
        void AddattackR(int i);
        void course(float course,float speed);
        void position(float x,float y,float speed);
        virtual void Update(int t);
        virtual void Print_State();


    protected:

    private:
        int attackR;
};

#endif // CHOPPER_H
