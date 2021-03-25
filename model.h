#ifndef MODEL_H
#define MODEL_H
#include<iostream>
#include "SimObj.h"
#include "Vehicle.h"
#include "Warehouse.h"
#include "state_trooper.h"
#include "truck.h"
#include "chopper.h"
#include <utility>
#include <map>
#include <vector>
#include <utility>
class model
{
    public:
        static model& getInstance();
        static void DeleteInstance();
         model (const model&)=delete;
         model& operator=(const model&)=delete;
         model(const model&&)=delete;
         model&& operator=(const model&&)=delete;
         int GetTime();///return the time
         void create(string name,int mood,float x=0,float y=0,string WarehouseName=0);///state trooper    chopper
         void AddWarehous(string name,float x,float y,int inventory);///warehouse
         void AddTruck(string truckName,string WarehouseName,int crates);
         void AddPathToTruck(string truckName,string warehouseName,string arrivalT,int caseQ,string departureT);
         void go();///call the function update for the Vehicles
         void status();///print status for the Vehicles and warehouse
         void course(string name,float angle,float speed=0);
         void position(string name,float x,float y,float speed=0);
         void destination(string name,string Warehouse_name);
         void stop();
        vector<pair<string,pair<float,float> > > BroadcastNL();///retuen a vector of the names and location of the SimObj's


    private:
         model();
         virtual ~model();
         static model *inst;
         int time;
         map<string,shared_ptr<Vehicle>> Vehicles;
         map<string,shared_ptr<Warehouse>> Warehouses;





};

#endif // MODEL_H
