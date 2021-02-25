#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "client_marshal.h"
using namespace std;


int main(int argc,char*argv[])
{
if(argc==2)
{
cout<<"Testing unmarshal"<<endl;
server_message test1;
test1 =unmarshal(argv[1]);
test1.printing();
}

if(argc>2)
{
cout<<"Testing Marshall"<<endl;
client_message test;
test.decision=atoi(argv[2]);
test.options=argv[1];
cout<<marshal(test)<<endl;
}
return 0;
}
