#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
#include "Warehouse.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
class truck:public Vehicle   
{
    public:
        truck(string name ,float x,float y,int crates);
        virtual ~truck();
        void AddToPath(shared_ptr<Warehouse> wp,string arrivalT,int caseQ,string departureT);///add the warehouses that the truck supposed to move to
        void Update(int t);
        void Print_State();


    protected:

    private:
        int crates,indexP;///indexP (index for the vector)- where the truck parked at or from where the tuck started moving
        int time_compare(int t,string st);
        int minutes(string t1,string t2);///Calculate the time by minutes between t1 and t2
        int minutes(string t1,int t2);///Calculate the time by minutes between t1 and t2
        bool f;
        struct info
        {
            shared_ptr<Warehouse> wp;
            string arrivalT;
            int caseQ;
            string departureT;
        };
        vector<info> path; ///vector of info
};

#endif // TRUCK_H
