#include "server_marshal.h"
using namespace std;

int main()
{
server_message cm;
cm.command="LIST";
cm.messa="Main Menu";
cm.num_lines=3;
cm.lines.push_back("1. Check Status");
cm.lines.push_back("2. Change status");
cm.lines.push_back("3. Logout");
cout<<marshal(cm)<<endl;
}
