#include "tcp_server2.h"
using namespace std;

int main()
{
server test;
test.initialize_server();
string temp="follow";
while (temp!="end")
{
temp=test.receive_message();
cout<<temp<<endl;
}
test.closeSockets();
return 0;
}
