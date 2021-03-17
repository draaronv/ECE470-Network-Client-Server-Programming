#include <iostream>
#include <string>
#include <vector>
#include "server_marshal.h"
#include "tcp_server2.h"
#include "server_menus.h"
using namespace std;

int main()
{
string receiveStartingMessage;
//Initialize server
server test;
test.initialize_server();
//Receive
receiveStartingMessage=test.receive_message();
//Unmarshall the message from the client
client_message startingMessage;
startingMessage=unmarshal(receiveStartingMessage);
//Check if you have the starting message
if(startingMessage.command!="START")
{
test.closeSockets();
exit(EXIT_SUCCESS);
}
// Create the sample
samples_serverMessage temp;
server_message userServMess;
server_message passServMess;
userServMess=temp.create_userNameResponse();
string userMessage=marshal(userServMess);
//Password
passServMess=temp.create_passWordResponse();
string passMessage=marshal(passServMess);
string userInput;
while(true)
{
    //Send username response
    test.send_message(userMessage);
    //Receive User Response
    userInput=test.receive_message();
    client_message tempUserMessage;
    tempUserMessage=unmarshal(userInput);
    //Send Password
    test.send_message(passMessage);
    userInput=test.receive_message();
    client_message tempPassMessage;
    tempPassMessage=unmarshal(userInput);
    if(tempPassMessage.decision==45 && tempUserMessage.decision==7)
    {
        int mmMenu=mainMenu(test);
        if(mmMenu==-1)
        {
        test.closeSockets();

        break;
        }
    }
}

return 0;
}

