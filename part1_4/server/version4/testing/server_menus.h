#ifndef _SERVER_MENUS_H_
#define _SERVER_MENUS_H_
#include <iostream>
#include <string>
#include "server_marshal.h"
#include "tcp_server2.h"
#include "datamodel.h"
using namespace std;

home sample;
server_message devicesLists()
{
    vector<string> temp=sample.deviceList;
    temp.push_back("4. Return to the Previous Menu");
    server_message deviceListMess;
    deviceListMess.command="LIST";
    deviceListMess.messa="List of Devices";
    deviceListMess.num_lines=temp.size();
    deviceListMess.lines=temp;
    return deviceListMess;
}

server_message roomsList()
{
    vector<string> temp=sample.ro.roomList;
    temp.push_back("4. Return to the previous Menu");
    server_message roomListMess;
    roomListMess.command="LIST";
    roomListMess.messa="List of Rooms";
    roomListMess.lines=temp;
    return roomListMess;
}

server_message alarmStatus(int option1)
{
    vector<string> temp;
    string tempAlarm;
    bool alarmStatus=sample.al.getStatus();
    if(alarmStatus)
    {
        tempAlarm="ON";
    }
    else
    {
        tempAlarm="OFF";
    }
    string alarmSt="Alarm";
    string temp1;
    stringstream ss;
    int number=1;
    ss<<number<<". "<<alarmSt<<number<<":"<<tempAlarm;
    getline(ss,temp1);
    temp.push_back(temp1);
    if(option1==1)
    {
        temp.push_back("2. Change the status");
    }
    temp.push_back("4. Return to the Previous Menu");
    server_message alarmStatusMessage;
    alarmStatusMessage.command="LIST";
    alarmStatusMessage.num_lines=temp.size();
    alarmStatusMessage.messa="Check Status: Alarm";
    alarmStatusMessage.lines=temp;
    return alarmStatusMessage;
}
//Status
//Alarm Menu
//
//
//

int alarmMenu(server test,int option1)
{
    string userInput;
    server_message alarmMenuMess;
    while(true)
    {
        alarmMenuMess=alarmStatus(option1);
        string maAlarmMenu=marshal(alarmMenuMess);
        test.send_message(maAlarmMenu);
        userInput=test.receive_message();
        client_message tempMessage;
        tempMessage=unmarshal(userInput);
        if(tempMessage.decision==4)
        {
            break;
        }
        else if(tempMessage.decision==2)
        {
            sample.al.changeStatus();
        }
        else
        {
        }
    }
    return -1;
}
//Room Menu
//
//
//
int roomMenu(server test)
{
    //
    server_message options1;
    options1.command="LIST";
    options1.messa="You entered Bedroom";
    options1.num_lines=1;
    options1.lines.push_back("Welcome to bedroom");
    string maOptions1=marshal(options1);

    server_message options2;
    options2.command="LIST";
    options2.messa="You entered Bathroom";
    options2.num_lines=1;
    options2.lines.push_back("Welcome to the Bathroom");
    string maOptions2=marshal(options2);

    server_message options3;
    options3.command="LIST";
    options3.messa="You entered Living room";
    options3.num_lines=1;
    options3.lines.push_back("Welcome to living room");
    string maOptions3=marshal(options3);

    //
    string userInput;
    server_message roomMenuMess;
    while(true)
    {
        roomMenuMess=roomsList();
        string maRoomMenuMess=marshal(roomMenuMess);
        test.send_message(maRoomMenuMess);
        userInput=test.receive_message();
        client_message tempMessage;
        tempMessage=unmarshal(userInput);
        if(tempMessage.decision==4)
        {
            break;
        }
        else if(tempMessage.decision==1)
        {
            test.send_message(maOptions1);
            test.receive_message();
        }
        else if(tempMessage.decision==2)
        {
            test.send_message(maOptions2);
            test.receive_message();
        }
        else if(tempMessage.decision==3)
        {
            test.send_message(maOptions3);
            test.receive_message();
        }
    }
    return -1;
}

//Locks
//
//
//


//Change
//Alarm Menu
//
//
//


//Room Menu
//
//
//


//Locks
//
//
//


//Check Status Menu
//
//
//
int checkStatusMenu(server test)
{
     //Temporary
    server_message options1;
    options1.command="LIST";
    options1.messa="You entered Alarms";
    options1.num_lines=1;
    options1.lines.push_back("Welcome to Alarms");
    string maOptions1=marshal(options1);

    server_message options2;
    options2.command="LIST";
    options2.messa="You entered Locks";
    options2.num_lines=1;
    options2.lines.push_back("Welcome to the Locks");
    string maOptions2=marshal(options2);

    server_message options3;
    options3.command="LIST";
    options3.messa="You entered Lights";
    options3.num_lines=1;
    options3.lines.push_back("Welcome to the Lights");
    string maOptions3=marshal(options3);

    //Temporary
    string userInput;
    server_message deviceListMess;
    deviceListMess=devicesLists();
    string maDeviceListMess=marshal(deviceListMess);
    while(true)
    {
        test.send_message(maDeviceListMess);
        userInput=test.receive_message();
        client_message tempMessage;
        tempMessage=unmarshal(userInput);
        if(tempMessage.decision==1)
        {
            int aaAlarmSt;
            aaAlarmSt=alarmMenu(test,0);
        }
        else if(tempMessage.decision==2)
        {
            test.send_message(maOptions2);
            userInput=test.receive_message();
        }
        else if(tempMessage.decision==3)
        {
           int rrRoomSt;
           rrRoomSt=roomMenu(test);
        }
        else if(tempMessage.decision==4)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return -1;

}



//Change Status Menu
//
//
//
int changeStatusMenu(server test)
{
    //Temporary
    server_message options1;
    options1.command="LIST";
    options1.messa="You entered Alarms";
    options1.num_lines=1;
    options1.lines.push_back("Welcome to Alarms");
    string maOptions1=marshal(options1);

    server_message options2;
    options2.command="LIST";
    options2.messa="You entered Locks";
    options2.num_lines=1;
    options2.lines.push_back("Welcome to the Locks");
    string maOptions2=marshal(options2);

    server_message options3;
    options3.command="LIST";
    options3.messa="You entered Lights";
    options3.num_lines=1;
    options3.lines.push_back("Welcome to the Lights");
    string maOptions3=marshal(options3);

    //Temporary
    string userInput;
    server_message deviceListMess;
    deviceListMess=devicesLists();
    string maDeviceListMess=marshal(deviceListMess);
    while(true)
    {
        test.send_message(maDeviceListMess);
        userInput=test.receive_message();
        client_message tempMessage;
        tempMessage=unmarshal(userInput);
        if(tempMessage.decision==1)
        {
            int aaAlarmSt;
            aaAlarmSt=alarmMenu(test,1);

        }
        else if(tempMessage.decision==2)
        {
            test.send_message(maOptions2);
            userInput=test.receive_message();

        }
        else if(tempMessage.decision==3)
        {
            test.send_message(maOptions3);
            userInput=test.receive_message();
        }
        else if(tempMessage.decision==4)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    return -1;
}



//Main Menu
//
//
//
int mainMenu(server test)
{
    string maMenu;
    server_message cm;
    cm.command="LIST";
    cm.messa="Main Menu";
    cm.num_lines=3;
    cm.lines.push_back("1. Check Status");
    cm.lines.push_back("2. Change status");
    cm.lines.push_back("3. Logout");
    maMenu=marshal(cm);
    server_message ending;
    ending.command="END";
    ending.messa="Ending Connection";
    string maEnding=marshal(ending);

    server_message options1;
    options1.command="LIST";
    options1.messa="You entered option 1";
    options1.num_lines=1;
    options1.lines.push_back("Welcome to the check Status");
    string maOptions1=marshal(options1);

    server_message options2;
    options2.command="LIST";
    options2.messa="You entered option 1";
    options2.num_lines=1;
    options2.lines.push_back("Welcome to the check Status");
    string maOptions2=marshal(options2);
    while(true)
    {
        string userInput;
        test.send_message(maMenu);
        client_message tempMessage;
        userInput=test.receive_message();
        tempMessage=unmarshal(userInput);
        if(tempMessage.decision==1)
        {
             int ccCheck;
             ccCheck=checkStatusMenu(test);
        }
        else if(tempMessage.decision==2)
        {
           int ccChange;
           ccChange=changeStatusMenu(test);
        }
        else if(tempMessage.decision==3)
        {
            test.send_message(maEnding);
            break;
        }
    }
    return -1;
}



#endif
