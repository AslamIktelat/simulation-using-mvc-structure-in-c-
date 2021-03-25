#include "controller.h"

controller::controller()
:flag(false),mo(model::getInstance())
{

}

controller::~controller()
{
    //dtor
}
void controller::CopyDataFromFile(string Fname)
{
string line;
ifstream myfile (Fname);
  if (!myfile.is_open())
      throw string("Failed opening required file:"+Fname);


    string name,sx,sy,Sin;
    float fx,fy;
    int fin,cl=0;
    while(!myfile.eof())
    {
        cl++;
        getline(myfile,line);
         std::size_t found =line.find(",");
          if (found==string::npos)
            throw string("Wrong format input at file:"+Fname+to_string(cl)+"\n");
        name=line.substr(0,found);
        line=line.substr(found+1);///cut the line

        found =line.find("(");
          if (found==string::npos)
            throw string("Wrong format input at file:"+Fname+" line:"+to_string(cl)+"\n");
        std::size_t found2 =line.find(",");
          if (found==string::npos)
            throw string("Wrong format input at file:"+Fname+" line:"+to_string(cl)+"\n");
          sx=line.substr(found+1,found2-found);
         fx = strtof(sx.c_str(),NULL);
          line=line.substr(found2+1);  ///cut the line

           found =line.find(")");
          if (found==string::npos)
            throw string("Wrong format input at file:"+Fname+" line:"+to_string(cl)+"\n");
           sy= line.substr(0,found);
           fy = strtof(sy.c_str(),NULL);
           line=line.substr(found+3);///cut the line
           Sin=line;
           fin = strtof(Sin.c_str(),NULL);
           try{mo.AddWarehous(name,fx,fy,fin);}
           catch(string e){throw;}
    }
myfile.close();

}

void controller::Default()
{
  vi.Default();
}
void controller::Size(int s)
{
 vi.size(s);
}
void controller::zoom(int z)
{
    vi.zoom(z);
}
void controller::pan(int x,int y)
{
    vi.pan(x,y);
}
void controller::show()
{
  vi.show(mo.BroadcastNL());
}
void controller::status()
{
 mo.status();
}
void controller::go()
{
mo.go();
}
void controller::create(string name,int mood,float x,float y,string WarehouseName)
{
    try
    {
        mo.create(name,mood,x,y,WarehouseName);
    }
    catch(string &e)
    {
        cerr<<e<<"\n";
    }
}
void controller::course(string name,float angle,float speed)
{
   try {mo.course(name,angle,speed);}
   catch( string e){ cerr<<e<<"\n";}
   catch (int i)
    {
        cerr<<"code bug from course"<<"\n";
    }
}
void controller::position(string name,float x,float y,float speed)
{
    try {mo.position(name,x,y,speed);}
    catch(string e){cerr<<e<<"\n";}
    catch(int i){cerr<<"code bug from position"<<"\n";}
}
void controller::destination(string name,string Warehouse_name)
{
  try{mo.destination(name,Warehouse_name);}
  catch(string e){cerr<<e<<"\n";}
}
void controller::stop()
{
mo.stop();
}
int controller::GetTime()
{
 return mo.GetTime();
}

void controller::AddTruckFromFile(string Fname)
{
int cl=1,crates=0;///counter line
vector<string> temp;
string line,WarehouseName;
ifstream myfile (Fname);
  if (!myfile.is_open())
      throw string("Failed opening required file:"+Fname);
///the first line
getline(myfile,line);
size_t found =line.find(",");
if (found==string::npos)
throw string("Wrong format input at file:"+Fname+" line:"+to_string(cl));
WarehouseName=line.substr(0,found);
line+=",0,"+line.substr(found+1);
temp.push_back(line);
string strPush;
 while((!myfile.eof())) ///push to the vector and check the input 
    {
        getline(myfile,line);
        strPush=line;
        cl++;
        int c=0;
        string n,t1,t2,cq;
        size_t found =line.find(",");
        if (found==string::npos)
            throw string("Wrong format input at file:"+Fname+" line:"+line+" line number:"+to_string(cl));
        n=line.substr(0,found);///n has the name of the warehouse
        line=line.substr(found+1);
        
        found =line.find(",");
        if (found==string::npos)
            throw string("Wrong format input at file:"+Fname+" line:"+line+" line number:"+to_string(cl));
        t1=line.substr(0,found);//t1 has the arrival time
        line=line.substr(found+1);
        
        found =line.find(",");
        if (found==string::npos)
            throw string("Wrong format input at file:"+Fname+" line:"+line+" line number:"+to_string(cl));
        cq=line.substr(0,found);//t1 has the case quantity in string format
        c=atoi(cq.c_str());
        line=line.substr(found+1);
        
      
        t2=line;//t1 has the departure time 
        temp.push_back(strPush);
        crates=crates+c;
    }
    string TruckName;
    size_t f =Fname.find(".");
        TruckName=Fname.substr(0,f);///n has the name of the warehouse
try{mo.AddTruck(TruckName,WarehouseName,crates);}
catch(string e){throw;}
///read from the vector
for(unsigned int i=0;i<temp.size();i++)
{

        int c=0;
        line=temp[i];
        
        string n,t1,t2,cq;
        size_t found =line.find(",");
        n=line.substr(0,found);///n has the name of the warehouse
        line=line.substr(found+1);
        
        found =line.find(",");
        t1=line.substr(0,found);//t1 has the arrival time
        line=line.substr(found+1);
        
        found =line.find(",");
        cq=line.substr(0,found);//t1 has the case quantity in string format
        c=atoi(cq.c_str());
        line=line.substr(found+1);
        
        t2=line;//t1 has the departure time 
        

    try{
       mo.AddPathToTruck(TruckName,n,t1,c,t2);
    }
    catch(string e){throw;}
}



myfile.close();
}