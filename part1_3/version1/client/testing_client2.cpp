#include "tcp_client.h"
using namespace std;

int main()
{
client test;
client test2("127.0.0.1",5555);
string temp;
test.send_message("START 2");
temp=test2.receive_message();
cout<<temp<<endl;

test.send_message("CHOICE 5");
temp=test2.receive_message();
cout<<temp<<endl;

test.send_message("END 1");
temp=test2.receive_message();
cout<<temp<<endl;

test.send_message("ERROR 2");
temp=test2.receive_message();
cout<<temp<<endl;

test.send_message("end");
temp=test2.receive_message();
cout<<temp<<endl;

test.closing_all();
test2.closing_all();
return 0;
}
