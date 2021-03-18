#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
bool alarmStatus=false;
string tempAlarm;
if(alarmStatus)
{
    tempAlarm="ON";
}
else
{
    tempAlarm="OFF";
}
string alarmSt="Alarm";
string temp;
stringstream ss;
int number=1;
ss<<number<<". "<<alarmSt<<number<<":"<<tempAlarm;
getline(ss,temp);
cout<<temp<<endl;
return 0;
}
