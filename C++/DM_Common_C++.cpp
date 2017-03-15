#include "DM_Common_C++.h"

//Function 1
//获取本机IP，需要系统对应的msvcr120.dll
string DM_Common_Space::DM_Common::GetLocalIP()
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

//string大小写转换,flag=true标示字符串转大写，flag=false表示字符串转小写，默认转大写
void DM_Common_Space::DM_Common::str_trans(string &src, bool flag)
{
	transform(src.begin(), src.end(), src.begin(), flag ? toupper : tolower);
}