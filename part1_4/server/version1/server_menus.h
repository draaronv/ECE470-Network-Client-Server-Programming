#ifndef _SERVER_MENUS_H_
#define _SERVER_MENUS_H_
#include <iostream>
#include <string>
#include "server_marshal.h"
#include "tcp_server2.h"
using namespace std;

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
            //Create Message
            test.send_message(maOptions1);
            userInput=test.receive_message();
        }
        else if(tempMessage.decision==2)
        {
            test.send_message(maOptions1);
            userInput=test.receive_message();
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
