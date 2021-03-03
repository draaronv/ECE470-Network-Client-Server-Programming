#include "tcp_client.h"
using namespace std;

int main()
{
client test;
test.send_message("START 2");
test.send_message("CHOICE 5");
test.send_message("END 1");
test.send_message("ERROR 2");
test.send_message("end");
test.closing_all();
return 0;
}
