#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <stdlib.h>
#include "SimObj.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
using namespace std;

class view
{
    public:
        view();
        virtual ~view();
        void Default();
        void size(int s);
        void zoom(int z);
        void pan(int x,int y);
        void show(vector<pair<string,pair<float,float> > > SimO);

    protected:

    private:
        int x,y,s,z;///s-size z-zoom
        ///if c1>c2 return true else return false
        static  bool Sort_coordinates(pair<string,pair<float,float> > c1,pair<string,pair<float,float> > c2);


};

#endif // VIEW_H
