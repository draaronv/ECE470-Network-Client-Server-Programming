#include "tcp_client.h"
using namespace std;

int main()
{
client test;
string temp="follow";
while (temp!="end")
{
temp=test.receive_message();
cout<<temp<<endl;
}
test.closing_all();
return 0;
}
