#include <iostream>
using namespace std;
#include "DM_Common_C++.h"
using namespace DM_Common_Space;

int main()
{
	//Test Function 1  :  GetLocalIP()  获取本机IP
	string s;
	s = DM_Common::GetLocalIP();
	cout << s << endl;
	return 0;
}