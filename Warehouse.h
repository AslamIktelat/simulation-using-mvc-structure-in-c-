#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "SimObj.h"
#include <iostream>
using namespace std;
class Warehouse:public SimObj
{
    public:
        Warehouse(string name,float x,float y,int inventory);
        virtual ~Warehouse();
         void Update(int t);
        void Print_State();

    protected:

    private:
        int inventory;
};

#endif // WAREHOUSE_H
