#include <iostream>
#include "tcp_client2.h"
#include "client_marshal.h"
using namespace std;

int main()
{
    //Start Client
    client test;
    test.initialize_client();
    //Creating sample client message
    client_message starting;
    starting.options="START";
    starting.decision=1;
    //Marshal the client message
    string sendMessage=marshal(starting);
    //Send starting message
    test.send_message(sendMessage);
    while(true)
    {
        string recMessage;
        //Receive message
        recMessage=test.receive_message();
        server_message servMessage;
        //
        servMessage=unmarshal(recMessage);
        //
        servMessage.printing();

    }
    test.closeSockets();
    return 0;
}
