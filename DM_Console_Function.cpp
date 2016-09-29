#include "DM_Console_Function.h"

//获取本机IP，需要系统对应的msvcr120.dll
string GetLocalIP()
{
	std::string IP_string = "";
	WSADATA wsaData;
	char name[155];
	char *ip;
	PHOSTENT hostinfo;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0) {
		if (gethostname(name, sizeof(name)) == 0) {
			if ((hostinfo = gethostbyname(name)) != NULL) { //这些就是获得IP的函数
				ip = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
				IP_string = ip;

			}
		}
		WSACleanup();
	}
	return IP_string;
}
