#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "datamodel.h"
#include "server_menus.h"
#include "server_marshal.h"
#include "tcp_server2.h"
using namespace std;

int main()
{
server_message temp=lightList(1,1);

for(unsigned int i=0;i<temp.lines.size();i++)
{
    cout<<temp.lines[i]<<endl;
}
return 0;
}
