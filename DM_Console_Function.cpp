#include "DM_Console_Function.h"

//��ȡ����IP����Ҫϵͳ��Ӧ��msvcr120.dll
string GetLocalIP()
{
	std::string IP_string = "";
	WSADATA wsaData;
	char name[155];
	char *ip;
	PHOSTENT hostinfo;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0) {
		if (gethostname(name, sizeof(name)) == 0) {
			if ((hostinfo = gethostbyname(name)) != NULL) { //��Щ���ǻ��IP�ĺ���
				ip = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
				IP_string = ip;

			}
		}
		WSACleanup();
	}
	return IP_string;
}
