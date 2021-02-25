#ifndef _DATAMODEL_H_
#define _DATAMODEL_H
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


class alarm
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
        rooms n;
        alarm a;
        locks lo;
        void setUsername(string newUsername);
        void setPassword(string password);
};
#endif

