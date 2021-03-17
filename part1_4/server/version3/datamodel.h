#ifndef _DATAMODEL_H_
#define _DATAMODEL_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class light
{
    public:
        string name;
        bool status;
};



class room
{
    public:
        vector<light> l;
};



class rooms
{
    public:
        vector<room> r;
        string name;
        int light_number;
};


class alarmSystem
{
    public:
        string name;
        int code;
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
        void setUsername(string newUsername);
        void setPassword(string password);
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

