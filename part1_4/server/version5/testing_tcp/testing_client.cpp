#include "tcp_client2.h"
using namespace std;

int main()
{
client test;
test.initialize_client();
test.send_message("START 2");
test.send_message("CHOICE 5");
test.send_message("END 1");
test.send_message("ERROR 2");
test.send_message("end");
test.closeSockets();
return 0;
}
