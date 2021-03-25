#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "view.h"
#include "model.h"
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <exception>
#include<string>
#include <cstdlib>
using namespace std;
class controller
{
    public:
        controller();
        void CopyDataFromFile(string Fname);
        void AddTruckFromFile(string Fname);
        virtual ~controller();
        ///for the view
        void Default();
        void Size(int s);
        void zoom(int z);
        void pan(int x,int y);
        void show();
        ///for the model
        void status();
        void go();
        void create(string name,int mood,float x=0,float y=0,string WarehouseName=0);
        void course(string name,float angle,float speed=0);
        void position(string name,float x,float y,float speed=0);
        void destination(string name,string Warehouse_name);
        void stop();
        int GetTime();


    protected:

    private:
        bool flag;
        model& mo;
        view vi;
};

#endif // CONTROLLER_H
