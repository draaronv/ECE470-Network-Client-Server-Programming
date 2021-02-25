#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class client_message
{
    public:
        string options;
        int decision;
        void printing()
        {
            cout<<options<<" "<<decision<<endl;
        }
};

class server_message
{
    public:
        string options;
        string message;
        int num_lines;
        vector<string>lines;
        void printing()
        {
            cout<<options<<"    "<<num_lines<<"     "<<message<<endl;
            for(unsigned int i=0;i<lines.size();i++)
            {
                cout<<lines[i]<<endl;
            }   
        }
};

server_message client_unmarshal(string message)
{
    string command;
    server_message res;
    stringstream ss(message);
    ss>>command;
    if(command=="USER")
    {   res.options="USER";
        getline(ss,res.message);
    }
    else if(command=="PASS")
    {
        res.options="PASS";
        getline(ss,res.message);
    }
    else if(command=="LIST")
    {
        res.options="LIST";
        getline(ss,res.message,'\\');
        ss>>res.num_lines;
        vector<stringstream> tt(res.num_lines);
        string temp;
        int i=0;
        while(ss>>temp)
        {
            if(res.message=="\\\\")
            {
                break;
            }
            else if(temp=="\\")
            {
                i++;
            }
            else
            {
                tt[i]<<temp<<" ";
            }
        }
        for(unsigned int j=0;j<tt.size();j++)
        {
            string temp2;
            getline(tt[j],temp2);
            res.lines.push_back(temp2);
        }
    }
    else if(command=="ERROR")
    {
        res.options="ERROR";
        getline(ss,res.message);
        ss>>res.message;
    }
    else if(command=="END")
    {
        res.options="END";
        getline(ss,res.message);
        ss>>res.message;
    }
    else
    {
    }
    return res;
}

string client_marshal(client_message cm)
{
    stringstream ss;
    string result;
    if(cm.options=="START")
    {
        ss<<cm.options<<" "<<cm.decision;
    }
    else if(cm.options=="CHOICE")
    {
        ss<<cm.options<<" "<<cm.decision;
    }
    else if(cm.options=="END")
    {
        ss<<cm.options<<" "<<cm.decision;
    }
    else if(cm.options=="ERROR")
    {
        ss<<cm.options<<" "<<cm.decision;
    }
    else
    {
    } 
    getline(ss,result);
    return result;
}

client_message server_unmarshal(string message)
{
    string command;
    int decision;
    client_message res;
    istringstream ss(message);
    ss>>command>>decision;
    res.options=command;
    res.decision=decision;
    return res;
}

string server_marshal(server_message sm)
{
stringstream ss;
string result;
string c[5]={"USER","PASS","LIST","ERROR","END"};
if(sm.options == c[0])
{
    ss<<sm.options<<" "<<sm.message<<"\\";
}
else if(sm.options == c[1])
{
    ss<<sm.options<<" "<<sm.message<<"\\";
}
else if(sm.options == c[2])
{
    ss<<sm.options<<" "<<sm.num_lines<<" "<<sm.message<<"\\";
    for(int i=0;i<sm.num_lines;i++)
    {
        ss<<sm.lines[i]<<"\\";
    }
    ss<<"\\\\";
}
else if(sm.options == c[3])
{
    ss<<sm.options<<" "<<sm.message;
}
else if(sm.options == c[4])
{
    ss<<sm.options<<" "<<sm.message;
}
else
{
}
getline(ss,result);
return result;
}


#endif

