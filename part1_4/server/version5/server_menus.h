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
    int tempNum=sample.ro.obtainNumberofRooms();
    stringstream ss;
    string tempAA;
    ss<<tempNum+1<<". "<<"Return to the previous Menu";
    getline(ss,tempAA);
    temp.push_back(tempAA);
    server_message roomListMess;
    roomListMess.command="LIST";
    roomListMess.messa="List of Rooms";
    roomListMess.num_lines=temp.size();
    roomListMess.lines=temp;
    return roomListMess;
}

server_message listsLock(int option)
{
    vector<string> temp=sample.lo.locksList;
    int tempNum=sample.lo.numLocks;
    stringstream ss;
    if(option==1)
    {
        stringstream ss1;
        string tempAA1;
        tempNum++;
        ss1<<tempNum<<". "<<"Change the status of all the locks";
        getline(ss1,tempAA1);
        temp.push_back(tempAA1);
    }
    string tempAA;
    ss<<tempNum+1<<". "<<"Return to the Previous Menu";
    getline(ss,tempAA);
    temp.push_back(tempAA);
    server_message listsLockMess;
    listsLockMess.command="LIST";
    listsLockMess.messa="Welcome to Locks";
    listsLockMess.num_lines=temp.size();
    listsLockMess.lines=temp;
    return listsLockMess;
}

server_message lightList(int option1,int type)
{
    vector<string> temp=sample.ro.house_room[option1-1].lightsList;
    int tempNum=sample.ro.house_room[option1-1].numLights;
    stringstream ss;
    if(type==1)
    {
        stringstream ss1;
        string tempAA1;
        tempNum++;
        ss1<<tempNum<<". "<<"Change the status of all lights";
        getline(ss1,tempAA1);
        temp.push_back(tempAA1);
    }
    string tempAA;
    ss<<tempNum+1<<". "<<"Return to the previous Menu";
    getline(ss,tempAA);
    temp.push_back(tempAA);
    server_message lightListMess;
    lightListMess.command="LIST";
    lightListMess.messa=sample.ro.house_room[option1-1].roomName;
    lightListMess.num_lines=temp.size();
    lightListMess.lines=temp;
    return lightListMess;
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

//Light Menu
int lightMenu(server test,int option,int type)
{
    string userInput;
    while(true)
    {
        server_message lightMenuMess=lightList(option,type);
        string maLightMenuMess=marshal(lightMenuMess);
        int tempNum=sample.ro.house_room[option-1].numLights;
        test.send_message(maLightMenuMess);
        userInput=test.receive_message();
        client_message tempMessage;
        tempMessage=unmarshal(userInput);
        if(type==0)
        {
            if(tempMessage.decision==(tempNum+1))
            {
                break;
            } 
        }
        else
        {
            if(tempMessage.decision==(tempNum+2))
            {
                break;
            }
            else if(tempMessage.decision==(tempNum+1))
            {
                sample.ro.house_room[option-1].changeAllLights();
            }
            else if(tempMessage.decision==1)
            {
                sample.ro.house_room[option-1].changeSingleLights(0);
            }
            else if(tempMessage.decision==2)
            {
                sample.ro.house_room[option-1].changeSingleLights(1);
            }
            else if(tempMessage.decision==3)
            {
                sample.ro.house_room[option-1].changeSingleLights(2);
            }
            else if(tempMessage.decision==4)
            { 
                sample.ro.house_room[option-1].changeSingleLights(3);
            }
        }
        
    }
return -1;
}

//Room Menu
//
//
//
int roomMenu(server test,int type)
{
    string userInput;
    server_message roomMenuMess;
    while(true)
    {
        roomMenuMess=roomsList();
        string maRoomMenuMess=marshal(roomMenuMess);
        int tempNum=sample.ro.obtainNumberofRooms();
        test.send_message(maRoomMenuMess);
        userInput=test.receive_message();
        client_message tempMessage;
        tempMessage=unmarshal(userInput);
        if(tempMessage.decision==(tempNum+1))
        {
            break;
        }
        else if(tempMessage.decision==1)
        {
            int llLightMenu;
            llLightMenu=lightMenu(test,1,type);
        }
        else if(tempMessage.decision==2)
        {
             int llLightMenu;
            llLightMenu=lightMenu(test,2,type);

        }
        else if(tempMessage.decision==3)
        {
            int llLightMenu;
            llLightMenu=lightMenu(test,3,type);
        }
    }
    return -1;
}


//Locks
//
//
//
int lockMenu(server test,int option)
{ 
    //Temporary
    //Temporary
    string userInput;
    while(true)
    {
        server_message lockMenuMess=listsLock(option);
        string maLockMenuMess=marshal(lockMenuMess);
        int tempNum=sample.lo.numLocks;
        test.send_message(maLockMenuMess);
        userInput=test.receive_message();
        client_message tempMessage;
        tempMessage=unmarshal(userInput);
        if(option==0)
        {
            if(tempMessage.decision==(tempNum+1))
            {
                break;
            }
        }
        else
        {
            if(tempMessage.decision==(tempNum+1))
            {
                sample.lo.changeAllLocks();
            }
            else if(tempMessage.decision==(tempNum+2))
            {
                break;
            }
            else if(tempMessage.decision==1)
            {
                sample.lo.changeSingleLock(0);
            }
            else if(tempMessage.decision==2)
            {
                sample.lo.changeSingleLock(1);
            }
            else if(tempMessage.decision==3)
            {
                sample.lo.changeSingleLock(3);
            }
            else if(tempMessage.decision==4)
            {
                sample.lo.changeSingleLock(3);
            }
        }
    }
    return -1;
}



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
           int llLockMenu;
           llLockMenu=lockMenu(test,0);
        }
        else if(tempMessage.decision==3)
        {
           int rrRoomSt;
           rrRoomSt=roomMenu(test,0);
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
            int llLockMenu;
            llLockMenu=lockMenu(test,1);
        }
        else if(tempMessage.decision==3)
        {
            int rrRoomSt;
            rrRoomSt=roomMenu(test,1);
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
