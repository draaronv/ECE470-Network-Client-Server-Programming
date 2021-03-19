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
};

void room::setLightList()
{
    for(unsigned int i=0;i<lights.size();i++)
    {
        lightsList.push_back(lights[i].name);
    }
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
    house_room.push_back(bedroom);
    house_room.push_back(bathroom);
    house_room.push_back(livingroom);
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
    public:
        alarmSystem()
        {
            status=true;
        };

        string name;
        int code;
        void changeStatus()
        {
            status=!status;
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
};


class locks
{
    public:
        vector<lock> llock;
};

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

