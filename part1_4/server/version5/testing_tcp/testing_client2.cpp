#include "tcp_client2.h"
using namespace std;

int main()
{
client test;
test.initialize_client();
string temp;
test.send_message("START 2");
temp=test.receive_message();
cout<<temp<<endl;

test.send_message("CHOICE 5");
temp=test.receive_message();
cout<<temp<<endl;

test.send_message("END 1");
temp=test.receive_message();
cout<<temp<<endl;

test.send_message("ERROR 2");
temp=test.receive_message();
cout<<temp<<endl;

test.send_message("end");
temp=test.receive_message();
cout<<temp<<endl;

test.closeSockets();

return 0;
}
