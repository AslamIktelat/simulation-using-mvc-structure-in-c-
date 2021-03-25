#include "view.h"

view::view()
:x(-10),y(-10),s(25),z(2)
{

}
view::~view()
{
    //dtor
}
void view::Default()
{
 x=-10;
 y=-10;
 s=25;
 z=2;
}
void view::size(int s)
{
    this->s=s;
    if(s>30)
        this->s=30;
    if(s<6)
        this->s=6;
}
void view::zoom(int z)
{
 this->z=z;
}
void view::pan(int x,int y)
{
    this->x=x;
    this->y=y;
}
bool view::Sort_coordinates(pair<string,pair<float,float> > c1,pair<string,pair<float,float> > c2)
{
  pair<float,float> p1=c1.second,p2=c2.second;
  if(p1.second==p2.second)///y1==y2
  {
      if(p1.first<p2.first)
        return true;
      else
        return false;
  }
  if(p1.second>p2.second)
    return true;
  return false;

}
void view::show(vector<pair<string,pair<float,float> > > SimO)
{
sort(SimO.begin(), SimO.end(),Sort_coordinates);///call sort for SimO vector
 auto it=SimO.begin();
int Y=s*z-abs(y)-z,X=s*z-abs(x)-z;
//if the coordinate is out of range-range of the view- then erase it from the vector
for(;it!=SimO.end();it++)
{
  pair<float,float> p=(*it).second;
  float tempX=p.first,tempY=p.second;
  if(tempX<x || tempX>X || tempY>Y || tempY<y)
  {SimO.erase(it); --it; }
    
}
it=SimO.begin();
int c=3,temp;
temp=(s+2)/3;
if((temp*3)-2!=s)
    c=(temp*3)-2-s+3;

for(int i=Y;i>y-z;i=i-z)///i!=y-z
{
if(c==3)
{
    if(i>=0)
    {
        if(i<10)
       cout<<"   "<<i;
      if(i>=10 && i<100)
        cout<<"  "<<i;
      if(i>=100)
        cout<<" "<<i;
    }
    else
    {

    if(i>-10)
       cout<<"  "<<i;
      if(i<=-10 && i>-100)
        cout<<" "<<i;
      if(i<=-100)
        cout<<i;
    }

c=0;
}
else
    cout<<"    ";
    for(int j=x;j<X+z;j=j+z)///j!=x-z
    {
        ///print
        if(it!=SimO.end())
        {
            float XX=((*it).second).first,YY=((*it).second).second;
            if(YY>i) ///if we pass the point
             {
           it++;
             }
            if((*it).second== make_pair<float,float>(j,i))
             {
            cout<<((*it).first).substr(0,2);///print the first 2 letters
            it++;
            }
            else
       cout<<" .";
        }
        
         else
       cout<<" .";
    }

    cout<<endl;
    c++;
}

c=3;
for(int i=x;i<X+z;i=i+z)///i!=X+z
{
if(c==3)
{
    if(i>=0)
    {
        if(i<10)
       cout<<"     "<<i;
      if(i>=10 && i<100)
        cout<<"    "<<i;
      if(i>=100)
        cout<<"   "<<i;
    }
    else
    {

    if(i>-10)
       cout<<"    "<<i;
      if(i<=-10 && i>-100)
        cout<<"   "<<i;
      if(i<=-100)
        cout<<"  "<<i;
    }

c=0;
}
c++;
}
cout<<endl;
}

