#include "Warehouse.h"

Warehouse::Warehouse(string name,float x,float y,int inventory)
:SimObj(name,x,y),inventory(inventory)
{

}

Warehouse::~Warehouse()
{
    //dtor
}
void Warehouse::Update(int t)
{
  inventory=inventory-t;
}
void Warehouse::Print_State()
{
    cout<<"Warehouse ";
  SimObj::Print_State();
  cout<<"Inventory: "<<inventory<<"\n";

}
