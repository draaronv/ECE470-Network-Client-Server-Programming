#ifndef _DATAMODEL_H_
#define _DATAMODEL_H_
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class light
{
    public:
        string name;
        bool status;
        light();
        light(string name,bool status);
};

light::light()
{
    name="Bedroom Light";
    status=true;
}
light::light(string name1, bool status1)
{
    name=name1;
    status=status1;
}


class room
{
    public:
        vector<light> lights;
        vector<string> lightsList;
        string roomName;
        int roomNumber;
        int numLights;
        room();
        room(string roomMa ,int ro);
        void setLightList();
        void changeAllLights();
        void changeSingleLights(int option);
};

void room::changeAllLights()
{
    for(unsigned int i=0;i<lights.size();i++)
    {
        lights[i].status=!lights[i].status;
    }
    setLightList();
}

void room::changeSingleLights(int option)
{
    lights[option].status=!lights[option].status;
    setLightList();
}

void room::setLightList()
{
    vector<string> tempLight;
    for(unsigned int i=0;i<lights.size();i++)
    {
        stringstream ss;
        string lightSta;
        string temp;
        if(lights[i].status)
        {
            lightSta="ON";
        }
        else
        {
            lightSta="OFF";
        }
        ss<<lights[i].name<<" : "<<lightSta;
        getline(ss,temp);
        tempLight.push_back(temp);
    }
    lightsList=tempLight;
}


room::room()
{
    light t1("Light 1",true);
    light t2("Light 2",true);
    light t3("Light 3",true);
    light t4("Light 4",true);
    lights.push_back(t1);
    lights.push_back(t2);
    lights.push_back(t3);
    lights.push_back(t4);
    roomName="Bedroom";
    numLights=lights.size();
    roomNumber=1;
    setLightList();
}

room::room(string roomNa,int ro)
{
    roomNumber=ro;
    stringstream ss;
    string temp;
    ss<<roomNumber<<". "<<roomNa;
    getline(ss,temp);
    light t1("1. Light 1",true);
    light t2("2. Light 2",true);
    light t3("3 .Light 3",true);
    light t4("4. Light 4",true);
    lights.push_back(t1);
    lights.push_back(t2);
    lights.push_back(t3);
    lights.push_back(t4);
    roomName=temp;
    numLights=lights.size();
    setLightList();
}



class rooms
{
    private:
    public:
        vector<room> house_room;
        int numRoom;
        rooms();
        vector<string> roomList;
        int obtainNumberofRooms()
        {
            return numRoom;
        }
        void setRoomList();
};

rooms::rooms()
{
    room bedroom("bedroom",1);
    room bathroom("bathroom",2);
    room livingroom("living",3);
    room kitchen("kitchen",4);
    house_room.push_back(bedroom);
    house_room.push_back(bathroom);
    house_room.push_back(livingroom);
    house_room.push_back(kitchen);
    numRoom=house_room.size();
    setRoomList();
}

void rooms::setRoomList()
{
    for(unsigned int i=0;i<house_room.size();i++)
    {
        roomList.push_back(house_room[i].roomName);
    }
}


class alarmSystem
{
    private:
        bool status;
        int code;
    public:
        alarmSystem()
        {
            status=true;
            code=12345;
        };
        string name; 

        void changeStatus(int opt)
        {
            if(opt==code)
            {
                status=!status;
            }
        }

        bool getStatus()
        {
            return status;
        };
};



class lock
{
    public:
        string name;
        int code;
        bool status;
    lock();
    lock(string nam,bool stat,int codd); 
};

lock::lock()
{
    name="Main";
    code=12345;
    status=true;
}

lock::lock(string nam,bool stat,int codd)
{
    name=nam;
    code=codd;
    status=stat;
}

class locks
{
    private:
        int masterLock;
    public:
        vector<lock> llock;
        vector <string> locksList;
        int numLocks;
        locks();
        void setLocksList();
        void changeAllLocks(int opt);
        void changeSingleLock(int option, int opt);
};

void locks::changeAllLocks(int opt)
{
    if(opt==masterLock)
    {
    for(unsigned int i=0;i<llock.size();i++)
    {
        llock[i].status=!llock[i].status;
    }
    setLocksList();
    }
}

void locks::changeSingleLock(int option,int opt)
{
    if(opt==llock[option].code)
    {
    llock[option].status=!llock[option].status;
    setLocksList();
    }
}

locks::locks()
{
    lock ll1("1. Main Door",true,3441);
    lock ll2("2. Back Door",true,1234);
    lock ll3("3. Left Door",true,7812);
    lock ll4("4. Right door",true,2232);
    lock ll5("5. Bedroom door",true,2131);
    llock.push_back(ll1);
    llock.push_back(ll2);
    llock.push_back(ll3);
    llock.push_back(ll4);
    llock.push_back(ll5);
    numLocks=llock.size();
    setLocksList();
}

void locks::setLocksList()
{
   vector<string> tempLock;
    for(unsigned int i=0;i<llock.size();i++)
    {
        stringstream ss;
        string lightSta;
        string temp;
        if(llock[i].status)
        {
            lightSta="ON";
        }
        else
        {
            lightSta="OFF";
        }
        ss<<llock[i].name<<" : "<<lightSta;
        getline(ss,temp);
        tempLock.push_back(temp);
    }
    locksList=tempLock;
}

class home
{
    private:
        string password;
        string username;
    public:
        vector<string> deviceList;
        rooms ro;
        alarmSystem al;
        locks lo;
        home(); 
        void setDeviceList();
};


void home::setDeviceList()
{
    deviceList.push_back("1. Alarms");
    deviceList.push_back("2. Locks");
    deviceList.push_back("3. Lights");
}

home::home()
{
    setDeviceList();
}
#endif

