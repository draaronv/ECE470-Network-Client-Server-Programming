#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "client_marshal.h"
using namespace std;

int main()
{
server_message re;
re=unmarshal("LIST Main Menu \\ 3 1. Check Status \\ 2. Change status \\ 3. Logout \\\\ ");
re.printing();
return 0;
}
