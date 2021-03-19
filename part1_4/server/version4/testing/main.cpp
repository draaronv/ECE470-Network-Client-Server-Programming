#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "datamodel.h"

using namespace std;

int main()
{
home sample;
vector<string> temp=sample.ro.house_room[3].lightsList;
for(unsigned int i=0;i<temp.size();i++)
{
    cout<<temp[i]<<endl;
}
return 0;
}
