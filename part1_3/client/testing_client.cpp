#include "tcp_client.h"
using namespace std;

int main()
{
client test;
test.send_message("Messages ss s");
test.send_message("My name is ");
test.send_message("djedkddwd");
test.send_message("end");
test.closing_all();
return 0;
}
