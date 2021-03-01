#include "tcp_client.h"
using namespace std;

int main()
{
client test;
cout<<test.receive_message()<<endl;
test.closing_all();
return 0;
}
