#include "tcp_client.h"
using namespace std;

int main()
{
client test;
client test2("127.0.0.1",5555);
string temp="follow";
while (temp!="end")
{
temp=test.receive_message();
cout<<temp<<endl;
//sleep(1);
test2.send_message(temp);
}
test.closing_all();
test2.closing_all();
return 0;
}
