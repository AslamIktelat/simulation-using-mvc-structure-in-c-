#include "model.h"

model *model::inst=nullptr;
model::model()
:time(0)
{
  Warehouses.insert({"Frankfurt",shared_ptr<Warehouse>(new Warehouse("Frankfurt",40,10,100000))});
}

model::~model()
{

}
int model::GetTime()
{
return time;
}
model& model::getInstance()
{
   if(inst==nullptr)
    inst=new model();
   return *inst;
}
void model::DeleteInstance()
{
if(inst!=nullptr)
    inst->~model();

}
void model::create(string name,int mood,float x,float y,string WarehouseName)
{
    if(mood ==1)///trooper
    {
         auto it=Warehouses.find(WarehouseName);
         if(it==Warehouses.end())///not found the warehouse
            throw "Warehouse: "+WarehouseName+" not found." ;
         if(Vehicles.find(name)!= Vehicles.end())///if the trooper already added
                throw "A vehicle with the name "+name+" already added.";
         Vehicles.insert({name,shared_ptr<Vehicle>( new state_trooper(name,Warehouses,it->second))});
    }
    if(mood==2)///chopper
    {
        if(Vehicles.find(name)!=Vehicles.end())///if the chopper already added
                throw "Chopper "+name+" already added.";
         Vehicles.insert({name,shared_ptr<Vehicle>( new chopper(name,x,y))});
    }

}
void model::AddWarehous(string name,float x,float y,int inventory)
{
      if(Warehouses.find(name)!=Warehouses.end())///if the warehouse already added
            throw "Warehouse: "+name+" already added. END..." ;
         Warehouses.insert({name,shared_ptr<Warehouse>( new Warehouse(name,x,y,inventory) )});
}
void model::go()
{
///call update for all Vehicles
  for(auto it=Vehicles.begin();it!=Vehicles.end(); it++)
    (it->second)->Update(time);
    time++;
}
void model::status()
{
///call print_state for all the Vehicles
for(auto it=Vehicles.begin();it!=Vehicles.end(); it++)
    (it->second)->Print_State();
///call print_state for all the Warehouses
for(auto it=Warehouses.begin();it!=Warehouses.end(); it++)
    (it->second)->Print_State();
}
void model::course(string name,float angle,float speed)
{
    bool f=false;
auto it=Vehicles.find(name);
if(it==Vehicles.end())///not found
    throw string ("No Vehicle with the name "+name+" was found.");
if( typeid(*(it->second))==typeid(state_trooper) )///if the Vehicle is state_trooper
{
    state_trooper *temp=(state_trooper*)((it->second).get());
    temp->set_course(angle);
    f=!f;
}
if(typeid(*(it->second))==typeid(chopper))///if the Vehicle is chopper
{
    chopper *temp=(chopper*)((it->second).get());
  temp->course(angle,speed);
  f=!f;
}
if(!f)///if non of the two if's was true ///code bug
    throw 0;

}
void model:: position(string name,float x,float y,float speed)
{
     bool f=false;
auto it=Vehicles.find(name);
if(it==Vehicles.end())///not found
    throw string("No Vehicle with the name "+name+" was found.");
if( typeid(*(it->second))==typeid(state_trooper) )
{
    state_trooper *temp=(state_trooper*)((it->second).get());
    temp->position(x,y);
 f=!f;
}
if(typeid(*(it->second))==typeid(chopper))
{
    chopper *temp=(chopper*)((it->second).get());
  temp->position(x,y,speed);
   f=!f;
}
if(!f)///code bug
    throw 0;
}
void model::destination(string name,string Warehouse_name)
{
   auto itW=Warehouses.find(Warehouse_name);
   if(itW==Warehouses.end())///warehouse not found
    throw string("Warehouse: "+Warehouse_name+" not found.");
   auto itV=Vehicles.find(name);
   if(itV==Vehicles.end())///vehicle not found
     throw string("No Vehicle with the name "+name+" was found.");
    if(typeid(*(itV->second))==typeid(state_trooper))
      {
      state_trooper *temp=(state_trooper*)((itV->second).get());
      temp->destination(itW->second);

      }
      else
        throw string("No such state trooper with the name "+name+"."); ///no state_trooper found with this name

}
void model::stop()
{
     for(auto it=Vehicles.begin();it!= Vehicles.end();it++)
     (it->second)->Stop();
}
void model::AddTruck(string truckName,string WarehouseName,int crates)
{
    auto it=Warehouses.find(WarehouseName);
         if(it==Warehouses.end())///not found the warehouse
            throw string("Warehouse: "+WarehouseName+" not found. END...") ;
    if(Vehicles.find(truckName)!=Vehicles.end())///if the truck already added
                throw string("Truck: "+truckName+" already added. END..." );
         float x=((it->second)->Get_Location()).first,y=((it->second)->Get_Location()).second;
    Vehicles.insert({truckName,shared_ptr<Vehicle>( new truck(truckName,x,y,crates))});
}
void model::AddPathToTruck(string truckName,string warehouseName,string arrivalT,int caseQ,string departureT)
{
  auto itV=Vehicles.find(truckName);
  auto itW=Warehouses.find(warehouseName);
         if(itW==Warehouses.end())///not found the warehouse
           throw string("Warehouse: "+warehouseName+" not found. END..." );
           truck *temp=(truck*)((itV->second).get());
    temp->AddToPath(itW->second,arrivalT,caseQ,departureT);

}
vector<pair<string,pair<float,float> > > model::BroadcastNL()
{
  vector< pair<string,pair<float,float> > > temp;

  for(auto it=Vehicles.begin();it!=Vehicles.end();it++)
  {
       pair<float,float> l=(it->second)->Get_Location();
      string name=it->first;
      pair<string,pair<float,float>> p(name,l);
      temp.push_back(p);
  }
  for(auto it=Warehouses.begin();it!=Warehouses.end();it++)
  {
      pair<float,float> l=(it->second)->Get_Location();
      string name=it->first;
      pair<string,pair<float,float>> p(name,l);
      temp.push_back(p);
  }

return temp;

}
