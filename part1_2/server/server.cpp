#include "server_marshal.h"
using namespace std;

int main(int argc,char*argv[])
{
if(argc<3)
{
cout<<"Testing unmarshal"<<endl;
client_message test=unmarshal(argv[1]);
test.printing();
}
else
{
cout<<"Testing Marshal"<<endl;
server_message test1;
test1.command=argv[1];
test1.messa=argv[2];
switch(argc)
{
    case 5:
    {
        test1.num_lines=atoi(argv[3]);
        test1.lines.push_back(argv[4]);
        break;
    }
    case 6:
    {
        test1.num_lines=atoi(argv[3]);
        test1.lines.push_back(argv[4]);
        test1.lines.push_back(argv[5]);
        break;
    }
    case 7:
    {
        test1.num_lines=atoi(argv[3]);
        test1.lines.push_back(argv[4]);
        test1.lines.push_back(argv[5]);
        test1.lines.push_back(argv[6]);
        break;
    }
}
cout<<marshal(test1)<<endl<<endl;
}
return 0;
}
