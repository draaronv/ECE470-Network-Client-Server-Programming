#include "tcp_client.h"
using namespace std;

int main()
{
client test;
test.send_message("Hello world");
test.closing_all();
return 0;
}
