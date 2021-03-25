#ifndef STATE_TROOPER_H
#define STATE_TROOPER_H
#include "Vehicle.h"
#include "Warehouse.h"
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <iostream>
using namespace std;

class state_trooper:public Vehicle
{
    public:
        state_trooper(string name,map< string,shared_ptr<Warehouse> > path,shared_ptr<Warehouse> FirstWarehouse);
        virtual ~state_trooper();
          void Update(int t);
         void Print_State();
         void destination(shared_ptr<Warehouse> MovingTo);
         void course(float course);
         void position(float x,float y);





    protected:

    private:
        map< string ,shared_ptr<Warehouse> > path;
       shared_ptr<Warehouse> MovingTo,FirstWarehouse;
       void NextWarehouse();///set the next warehouse


};

#endif // STATE_TROOPER_H
