#ifndef _SERVER_MARSHAL_H_
#define _SERVER_MARSHAL_H_
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
using namespace std;

class client_message
{
    public:
    string command;
    int decision;
    void printing()
    {
        cout<<command<<"    "<<decision<<endl;
    }
};

class server_message
{
    public:
        string command;
        string messa;
        vector<string> lines;
        int num_lines;
};

struct samples_serverMessage
{
    server_message userNameResponse;
    server_message passWordResponse;
    server_message create_userNameResponse()
    {
        userNameResponse.command="USER";
        userNameResponse.messa="Please Enter your username:";
        return userNameResponse;
    };

    server_message create_passWordResponse()
    {
        passWordResponse.command="PASS";
        passWordResponse.messa="Please Enter your password:";
        return passWordResponse;
    };
};


client_message unmarshal(string message)
{
    string command;
    int decision;
    client_message res;
    istringstream ss(message);
    ss>>command>>decision;
    res.command=command;
    res.decision=decision;
    return res;
}

string marshal(server_message sm)
{
stringstream ss;
string result;
string c[5]={"USER","PASS","LIST","ERROR","END"};
if(sm.command == c[0])
{
    ss<<sm.command<<" "<<sm.messa<<" ";
}
else if(sm.command == c[1])
{
    ss<<sm.command<<" "<<sm.messa<<" ";
}
else if(sm.command == c[2])
{
    ss<<sm.command<<" "<<sm.messa<<" "<<"\\"<<" "<<sm.num_lines;
    for(int i=0;i<sm.num_lines;i++)
    {
        ss<<" "<<sm.lines[i]<<" "<<"\\";
    }
}
else if(sm.command == c[3])
{
    ss<<sm.command<<" "<<sm.messa;
}
else if(sm.command == c[4])
{
    ss<<sm.command<<" "<<sm.messa;
}
else
{
}
getline(ss,result);
return result;
}


#endif

